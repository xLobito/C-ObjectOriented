#include "ObjectPrueba.h"

#ifndef GC_CLASS_H
#define GC_CLASS_H 

/**
 * The following macro marks the destructor which belongs to specific class either built in or user-defined one. 
 * By doing so, it uses a single do-while(false) trick for a single operation (When it comes to macros, using if statements
 * may corrupt the expansion by making a twice expansion which it ain't the expected thing to happen), and restores the 
 * memory protection associated to the original "Object" class and checks out by inline assembly (x64 GNU Assembly) whether the pointer 
 * is allocated onto the Stack or the Heap. 
 * Based on the True/False evaluation, might occur different things 'cause the allocation differs quite a lot. Garbage Collector takes the Stack as root, therefore
 * it can't be deallocated. Similarly, pointers in the BSS Segment, or Memory Mapped Segment (Refers to mmap) are considered roots as well, yet it ain't that important here.
 * 
 * 1. When the pointer belongs to Stack Frame (is in between the highest address or lowest address), the destructor method is placed into the Memory Mapped Segment (Using Object), 
 * setting the "this" pointer related to the instance returned via stackalloc. 
 * Right after that, __exception_push_object internal function is called (See the function itself for more information) to set the local object to be destroyed properly 
 * when an exception is thrown. 
 * If the class has pointers in the heap after any local instance was given and exception is executed. The Garbage Collector will reclaim that memory "leaked" whenever it's required
 * or the programmer itself calls GC->Collect(). The local object is self-destroyed after popping arguments from the Stack Frame when either the function is ended or goes out of scope.
 * 
 * 2. When the pointer is assigned to the Heap (Data Segment), the inner workings are familiar when it comes to place the destructor method into the Memory Mapped Segment. However, 
 * instead calling __exception_push_object, GC->RegisterFinalizer() is called which registers the Heap-allocated object disposer. It uses a generic function to call the respective 
 * destructor, StandardDestructor takes two argumentos, one of it refers the instance of the class, and the other refers the destructor which is "casted" to specific destructor signature
 * (It's standarized as void (*)(void)) and then makes the call to jump out the destructor belonged to that instance. Any cleanup required are up to the programmer or the 
 * Garbage Collector will act at its will when necessary. 
 * 
 * Note: It's expected the programmer will deallocate the memory to avoid any memory overrun which may cause an exception (MemoryAccessException) if runs out of memory in large-sized projects.    
 */
#define destructor(T, N, FC) \
    do \
    { \
        callprotect(&this->object); \
        if(!strcmp(isPtrOnStack(this), "True")) \
        { \
            this->N = Object_trampoline(&this->object, T ## _ ## N, FC); \
            __exception_push_object(this, stepOut(__func__), this->N); \
            Object_prepare(&this->object); \
        } \
        else \
        { \
            this->N = Object_trampoline(&this->object, T ## _ ## N, FC); \
            GC->RegisterFinalizer(this, StandardDestructor, this->N); \
            Object_prepare(&this->object); \
        } \
    } while(0)

/* Typedef */
/**
 * The StackPtr structure is used to place a Stack-based data structure taking the local object instances in order to call the 
 * destructor whenever necessary. But its use is now deprecated 'cause the working are solved by the Garbage Collector and the Stack Frame
 * itself by popping off the class when goes out of scope. 
 * 
 * The GarbageCollector in the other hand; is the main class for the Garbage Collection system. As the other C-style class uses an Object 
 * to place the methods accordingly. 
 * The most used are Collect, Free and RegisterFinalizer. Yet, in terms of inner workings, Collect as well as Free are less common to be found. 
 * Alloc method is used when a primitive (or integral primitive) datatype requires memory (C-style dynamic memory storage), it's tracked by the 
 * Garbage Collector, but it can be Free'd when the programmer decides so. 
 * StackFinalizer, the same way as StackPtr structure is deprecated and no use shall occur. No matter what the programmer intends to do. 
 */
typedef struct StackPtr
{
    void *__rPtr;
    void (*dtor)(void);
    struct StackPtr *next;
    char *__f;
} StackPtr; /* DEPRECATED */

typedef struct GarbageCollector
{
    Object object;
    size_t __maxHeapSize; 
    void (*Collect)(void);
    void (*StackFinalizer)(void *, void (*)(void), const char *);
    void (*RegisterFinalizer)(void *, void (*)(void *, void *), void (*)(void));
    void (*Alloc)(size_t);
    void (*Free)(void *);
    size_t (*GetHeapSize)(void);
} GarbageCollector;

/**
 * The signature for the methods used here in the Garbage Collector class are marked with the static keyword, keeping out the export to other modules 
 * between the project. This is necessary 'cause it shouldn't be more initialization nor manipulation over these methods by the programmer. 
 * It ain't forbidden that programmers may create its own Garbage Collector classes, but, wouldn't be necessary. Would be redundant the use. Even custom methods 
 * can be created by the programmer itself using the proper inheritance and expanding it with his own methods. Everything can be inherited when the rightful 
 * syntax is given. 
 */

/* This sets the "C#-style static keyword" to call the methods whenever required. Occurs when the preinit section got executed. */
/* The rightful documentation to understand the successive calls until main function is reached are located in ObjectPrueba.h header file */
static void initGC(void);
/* The constructor in charge to initialize the methods as well the maximum space available for the Heap. */
extern void *GarbageCollector_GarbageCollector(void);
/* Method will reclaim any out of scope memory left behind either by the programmer or the framework itself. */
extern void GC_Collect(GarbageCollector * const);
/* Deprecated */
extern void GC_StackFinalizer(void *, void (*)(void), const char *, GarbageCollector * const);
/* Registers the disposer attached to respective class */
extern void GC_RegisterFinalizer(void *, void (*)(void *, void *), void (*)(void), GarbageCollector * const);
/* Method will act as "C-style" dynamic memory allocation. Same as calling malloc() from C Standard Library. */
extern void *GC_Alloc(size_t, GarbageCollector * const);
/* Method will act as "C-style" disposer memory allocation. The effect will be the same as calling free() from C Standard Library */
extern void GC_Free(void *, GarbageCollector * const);
/* Will stand as a property. Retrieves the max size of the Heap available for the system (Linux only) */
extern size_t GC_GetHeapSize(GarbageCollector * const);
/* Standard Destructor for heap allocated objects */
extern void StandardDestructor(void *, void *);
/* Will step one frame upwards to get the function name */
extern char *stepOut(const char *);

struct GarbageCollector *GC;
static StackPtr *stackRoots = NULL; /* Deprecated */
__attribute__((section(".preinit_array"), used)) static __typeof__(initGC) *ctorGC = &initGC;

/* Section */
static void initGC(void)
{
    GC = new GarbageCollector_GarbageCollector();
    GC_INIT(); /* Required for almost every platform */
    return;
}

#endif /* GC_CLASS_H */
#include "GC_Class.h"
#include <libunwind.h>
#include <libelf.h>

void *GarbageCollector_GarbageCollector(void);
void GC_Collect(GarbageCollector * const);
void GC_StackFinalizer(void *, void (*)(void), const char *, GarbageCollector * const);
void GC_RegisterFinalizer(void *, void (*)(void *, void *), void (*)(void), GarbageCollector * const);
void *GC_Alloc(size_t, GarbageCollector * const);
void GC_Free(void *, GarbageCollector * const);
size_t GC_GetHeapSize(GarbageCollector * const);
/* Supportive */
void StandardDestructor(void *, void *);
char *stepOut(const char *);
static void LookForStackRoots(void);

void *GarbageCollector_GarbageCollector(void)
{
    struct GarbageCollector *this = Object_create(sizeof(GarbageCollector), 7);

    FUNCTION(GC, Collect, 0);
    FUNCTION(GC, StackFinalizer, 3);
    FUNCTION(GC, RegisterFinalizer, 3);
    FUNCTION(GC, Alloc, 1);
    FUNCTION(GC, Free, 1);
    FUNCTION(GC, GetHeapSize, 0);
    Object_prepare(&this->object);
    return this;
}

void GC_Collect(GarbageCollector * const this)
{
    GC_collect_a_little();
    return;
}

optimize(0) void GC_StackFinalizer(void *ptr, void (*dtor)(void), const char *__f /* Non used */, GarbageCollector * const this)
{
    StackPtr *pushStackPtr = GC_MALLOC(sizeof(StackPtr));

    pushStackPtr->__rPtr = ptr;
    pushStackPtr->dtor = dtor;
    pushStackPtr->__f = GC_MALLOC(strlen(__f) + 1);
    strcpy(pushStackPtr->__f, __f);
    pushStackPtr->__f[strlen(__f)] = '\0';
    if(!stackRoots)
        stackRoots = pushStackPtr;
    else
    {
        pushStackPtr->next = stackRoots;
        stackRoots = pushStackPtr;
    }
    return;
}

optimize(0) void GC_RegisterFinalizer(void *ptr, void (*fp)(void *, void *), void (*dtor)(void), GarbageCollector * const this)
{
    return GC_register_finalizer(ptr, fp, (void *)dtor, 0, 0);
}

optimize(0) void *GC_Alloc(size_t size, GarbageCollector * const this)
{
    void *ptr = GC_MALLOC(size);

    if(ptr)
        return ptr;
    else
    {
        abort();
        //throw new MemoryAccessException("No memory available to be allocated");
    }
}

void GC_Free(void *ptr, GarbageCollector * const this)
{
    if(ptr)
    {
        return GC_FREE(ptr);
    }
    else
    {
        return; /* No op */
    }
    return; /* Never reached */
}

size_t GC_GetHeapSize(GarbageCollector * const this)
{
    this->__maxHeapSize = GC_get_heap_size();
    return this->__maxHeapSize;
}

/* Supportive */
void StandardDestructor(void *ptr, void *cdata)
{
    if(ptr)
    {
        ((void (*)(void))cdata)();
        GC->Free(ptr);
    }
    else 
    {
        return; /* No op */
    }
    return;
}

char *stepOut(const char *__f)
{
    bool state = 0;
    unw_cursor_t cursor;
    unw_context_t context;
    char *sym = GC_MALLOC(256);

    unw_getcontext(&context);
    unw_init_local(&cursor, &context);
    while((state = unw_step(&cursor)) > 0)
    {
        unw_word_t offset;
        unw_word_t pc;
        
        unw_get_reg(&cursor, UNW_REG_IP, &pc);
        if(!pc)
            return NULL;
        if(!unw_get_proc_name(&cursor, sym, 256, &offset))
        {
            if(!strcmp(sym, __f))
            {
                unw_step(&cursor);
                unw_get_reg(&cursor, UNW_REG_IP, &pc);
                if(!pc)
                    return NULL;
                if(!unw_get_proc_name(&cursor, sym, 256, &offset))
                    return sym;
            }
        }
    }
    return 0;
}

__attribute__((deprecated)) static void LookForStackRoots(void)
{
    StackPtr *aux = stackRoots;

    if(!aux)
        return;
    else
        aux->dtor();
    return;
} 
#include "ObjectPrueba.h"

#ifndef EXCEPTION_H
#define EXCEPTION_H

/* Mandatory defines for *NIX-based and set the local unwinding. */
/**
 * Each process has its own. Can't read it from other process. 
 */
#define _GNU_SOURCE
#define __USE_GNU
#define UNW_LOCAL_ONLY

#include <libunwind.h>
#include <setjmp.h>
#include <signal.h>
#include <ucontext.h>
#include "GC_Class.h"

/**
 * Typedefs.
 * 
 * The following typedefs are useful in Exception Handling procedure. Most of 'em are hidden in internal functions 
 * to avoid modifications and exploit security issues. 
 * These classes and simple structures controls the execution flow in a *NIX-based error, keeping some useful information
 * to be manipulated later, either by a handler or a single pop-out register. 
 */

/** 
 * ExceptionClass is the "standard" exception class to be used in Exception Handling. This class reserves the reason 
 * which triggers the error; as well as the type of the exception which generates it as well as the file and line. 
 * Three general-purpose methods are enabled to instruct the programmer about the error itself.
 */
typedef struct Except_Reason
{
    Object object;
    char ExceptionMessage[70];
    char ExceptionType[50];
    char *file;
    int line;
    int (*StackTrace)(void);
    char *(*GetType)(void);
    bool (*Equals)(const char *);
} ExceptionClass;

/**
 * If an error was triggered, this structure stacks constantly the exceptions which were thrown.
 * Works similarly as a Stack Frame or Call Stack, by acquiring some memory to set variables and then  
 * pops it out leaving the latest exception (Top of the Stack) behind. 
 * If fails to pops out the exception, then it's raised again and terminates execution because it couldn't be handled. 
 */
typedef struct Except_Frame
{
    struct Except_Frame *prev;
    jmp_buf env; /* Places the environment (Registers and Stack Pointer) to be restored after the exception is handled */
    const char *file;
    int line;
    const ExceptionClass *exception; /* The actual exception excepted to be handled */
} ExceptionFrame;

/**
 * The ExceptionFrame can't handle the context perfectly (If Stack Unwinding is on the run). Therefore, ContextFrame appears aside of ExceptionFrame,
 * keeping the same behavior but this only retains information of the machine context itself. It's useful to take the Instruction Pointer and get the 
 * frame of the Call Stack. 
 * If the exception is handled, and Unwinding doesn't fail. Then the ContextFrame pops out the latest (First in point of view from Stack structure) machine context
 * from it. 
 */
typedef struct context_stack
{
	struct context_stack *prev;
	ucontext_t ctx_frame; /* Machine context when every block is possible to throw an exception */
} ContextFrame;

/**
 * ExceptionFrame nor ContextFrame can handle the Stack Frame information of Stack-allocated objects. This new frame obtains the information of the local object
 * recently created and sets its destructor memory address to be called if any kind of Stack Unwinding occurs. 
 * A flag called statusFreed is necessary to check if the pointer was destroyed or not. This needs to be changed [WIP].
 */
typedef struct unwind_frame
{
	void *funcAddr; /* Memory address of the calling function/method. Useful when unwind is raised */
	int statusFreed; /* Flag */
	void *addrPtr; /* The "this" pointer associated to the method which triggers the DESTRUCTOR mark */
	void (*dtorPtr)(void); /* Function pointer known as the destructor of the object itself. Expected to be called if unwind occurs */
} UnwindFrame;

/**
 * This enumeration helps the Exception Handling system to check if the Exception was properly handled, or no Exception Handling was performed.
 * For kind of Exception may happens. Every one hints the system a different way to interpret the Exception Handling.
 * 1. ExceptionEntered assumes there is an exception to be handled. The system only knows there is one, but no information is given until it's raised. 
 * 2. ExceptionRaised asserts the exception is still on going. It will keep in this state until an appropriate handler is called. If the handler 
 * refuses to handle the exception this will remain and unhandled exception will terminate the execution. 
 * 3. ExceptionHandled is set when a handler modify the control flow and the execution can go as expected. When this occurs, the Stack Unwinding worked as expected 
 * and the environment was restored correctly. 
 * 4. ExceptionFinalized is set when the Exception Handling pass through a Finally statement and put it to end the Exception Handling procedure. 
 */
enum
{
	ExceptionEntered = 0,
	ExceptionRaised,
	ExceptionHandled,
	ExceptionFinalized
};

/**
 * When a Stack Unwinding occurs (Local objects need to be destroyed), this helps the system to check if the Stack Unwinding worked (Meaning, every single Stack-allocated
 * pointer is destroyed) or there it was a failure internal. If so, execution terminates immediately. 
 * 1. UnwindSuccess has the same purpose as UnwindMainReached. Hints that the top of unwinding was reached and so, the Stack Unwinding worked and the destructors was called. 
 * 2. UnwindMainReached was explained in 1. 
 * 3. UnwindNoReg is a returned value when the system fails to acquire the Instruction Pointer of the current frame. The expected result is terminate the execution 'cause can't perform
 * the rightful unwinding for that function on its frame. 
 * 4. UnwindNoInfo value is returned when an Instruction Pointer is zero. That value is obtained if the frame got corrupted, possibly. 
 * 5. UnwindNoSymbol occurs in case of the Symbol Table doesn't provide any references to specific frame. This shouldn't happen, though. 
 */
enum unwindStatus
{
	UnwindSuccess = 0,
	UnwindMainReached,
	UnwindNoReg,
	UnwindNoInfo,
	UnwindNoSymbol
};

/**
 * When a local object needs to be destroyed, the Call Stack goes up from lower to higher address. This values are useful to know either can continue or an error was detected. 
 * By continue, the meaning is checked if there is some frames available or the top (higher address) was reached.
 * 1. DestructorTopReached asserts the limit for Stack Unwinding is on. It may be any function/method which was previously marked via try statement. 
 * 2. DestructorFramesAvailable indicates that there is more frames to be walked up and possibly more objects to be destroyed. 
 * 3. DestructorNull is useful when fails to acquire any destructors for specific local object. Improbable for it to happen.  
 * 4. DestructorFreeFailed occurs when an object can't be destroyed. But, this needs to be deprecated 'cause DestructorNull is used for this purpose. 
 * 5. DestructorNoInfo is set if no destructor was found. In any case, this should be handled via MemoryAccessException if destructor points anywhere beyond its class. 
 */
enum destructorStatus
{
	DestructorTopReached = 0,
	DestructorFramesAvailable,
	DestructorNull,
	DestructorFreeFailed,
	DestructorNoInfo,
};

/**
 * Type definitions for specific enumerations and built in Exceptions. 
 * These Exceptions shouldn't be modified. Any attempt to modify 'em may cause critical errors, like RuntimeException. 
 */
typedef enum unwindStatus UnwindStatus;
typedef enum destructorStatus DestructorStatus;
typedef ExceptionClass Exception;
typedef ExceptionClass MemoryAccessException;
typedef ExceptionClass DivideByZeroException;
typedef ExceptionClass FileNotFoundException;
typedef ExceptionClass DataNotFoundException;
typedef ExceptionClass SystemInterruptedException;
typedef ExceptionClass SystemRuntimeException;
typedef ExceptionClass ArgumentException;
typedef ExceptionClass NullArgumentException;
typedef ExceptionClass FormatException;
typedef ExceptionClass InvalidCastException;
typedef ExceptionClass UnderflowException;
typedef ExceptionClass OverflowException;

/* Constructors */
/**
 * When a customized exception is thrown __enable_customized_exception takes the course and processes the exception by validating 
 * the Exception base class with proper arguments, and then calls the constructor. At last, the exception raises.
 * 
 * <param> message refers to reason which triggered the exception, if zero string a default reason provided by "Exception" is set. </param>
 * <param> __exceptionName refers to the type of customized exception. It's used later by GetType method principally. </param>
 * <param> ex refers to the customized exception pointer. By default is casted implicitly to void *, 'cause we can't use its type at static compile time. </param>
 * <param> ctor is the constructor associated to the customized exception which gets executed after "base class" is set properly. </param>
 * <exception> It's supposed to be non-throwable. Yet, there's left some modifications to be work on. [WIP] </exception>
 */
extern void __enable_customized_exception(char *, char *, void *, void *(*)(void));
/**
 * Just after __enable_customized_exception takes control of control flow, a call to isCustom is made. isCustom only takes the 
 * reason and the exception type. At first, the general purpose Exception variable got enabled by setting methods and file and line 
 * where the exception occurs. Then the control flow checks if there's a zero string. If so, a generic string reason got set into the 
 * general purpose exception and updates the global variable exceptionName. If not, simply cleans away any \x character given to the string reason
 * and copies it into the general purpose exception. As well as before, the exceptionName global variable is set by taking the type from __exceptionName.
 * 
 * <param> message refers to reason which triggered the exception, if zero string, a default reason provided by "Exception" is set. </param>
 * <param> __exceptionName refers to the type of customized exception. It's used later by GetType method principally. </param>
 * <exception> It's supposed to be non-throwable. Yet, there's left some modifications to be work on. [WIP] </exception>
 */
extern void isCustom(char *, char *);
/**
 * When a built in exception is thrown, buildException selects based on an identifier known as typeException and provides the respective 
 * information to the exception class by placing the exception reason and name. This even calls EnableException which updates the class methods
 * for use when necessary (If exception is scoped, of course). It is quite similar to isCustom.
 * 
 * <param> typeException refers to a magic number which points to specific type of built in exception. </param>
 * <param> message refers to reason which triggered the exception, if zero string, a default reason provided by "Exception" is set. </param>
 * <exception> No throw is available for this function. If any error is thrown while there is a try statement, shall be handled. But the behavior is undefined.
 * Otherwise, the execution shall be fail and abort() is called without any cleanup realized </exception>
 * <see> isCustom </see>
 */
extern void buildException(int, char *);
/**
 * EnableException initializes an instance to an exception object. Sets the important general purpose exception variables. Sets the file and line,
 * and establish the reason and other properties. But, the most important utility from this function is the initialization of class methods. 
 * The methods cannot be overriden. Strictly forbidden. These methods are only inheritables but no vtable should be avalaible for 'em. 
 * Note: This exception is automatically deallocated by the Garbage Collector without the help of finalizers (Std_finalizer is used). No need for the 
 * programmer to free it. 
 *
 * <param> file refers to the file where the exception is generated </param>
 * <param> line refers the specific line of the file which triggered the exception </param>
 * <param> check is used to switch over the multiple built in exceptions types and selecting the one is needed. </param>
 * <exception> This function should be exception safe. If Garbage Collector fails to allocate some memory, a warning is displayed. Therefore the execution is terminated. </exception>
 */
extern void *EnableException(const char *, int, int);

/* Exception methdos */

/**
 * A class method which iterates backwards (At the opposite way as Stack Frame grows) by retrieving some useful information about the execution from the execution was stopped. 
 * In order to do so, takes the context at the very moment and place a cursor. From this point starts to unwind the Stack and takes the Instruction Pointer and demangle the function or
 * class method name. The iteration is made continously while unw_step returns an integer greater than zero. If zero, then no further functions are available. 
 * If it's fails to demangle the function or class method name, then returns a UNW_ENOINFO which is placed as -1. The iteration stops at that point and no further functions are available.
 * 
 * <param> this refers to the class pointer which triggers this method. Is a C convention for C++ object type. </param>
 * <returns> Returns zero if the the cursor demangles all functions available or UNW_ENOINFO (-1) if it's fails to demangle some name. Stuck the unwind.
 * <exception> Shall be exception safe. No logical errors are defined for a local unwinding. </exception>
 */
extern int ExceptionClass_stackTrace(ExceptionClass * const);
/**
 * Using this pseudo-called property, returns the exception type declared previously. If the exception is customized, returns correctly its name. 
 * <param> this refers to the class pointer which triggers this method. Is a C convention for C++ object type. </param>
 * <returns> Returns a string with the exception type of the calling exception. If a null pointer constant is given, the return value equals to null. 
 * <exception> It's safe for using. No exception is thrown no matter what happens. Even a null constant pointer. </exception>
 */
extern char *ExceptionClass_GetType(ExceptionClass * const);
/**
 * Exception class method which evaluates the exception types of the calling method and another exception type. As declared as inline, the compile interprets this definition as 
 * "macro expansion". However, the static checking is far better. Returns true of false depending on comparing the two exception types.
 * 
 * <param> this refers to the class pointer which triggers this method. Is a C convention for C++ object type. </param>
 * <returns> Returns an integer constant boolean value. One for true returning, zero otherwise. 
 * <exception> If str1 is a null constant pointer, a MemoryAccessException shall be returned. If try statement (used with finally clause or a catch between) is set, then the error 
 * shall be noticed by the programmer. Otherwise, an abort execution is generated with no further information. </exception>
 */
extern bool ExceptionClass_Equals(const char *, ExceptionClass * const);

/* Supportive */

/**
 * __except_init initializes the Signal Stack, as well as the Exception Frame which pushes the exception information to be handled by the 
 * catch clause. The Signal Stack should be initialized by using sigaltstack() function and then a struct sigaction must be acquired with the proper handler. 
 * The flags relative to the sigaction by all the meanings should be SA_ONSTACK, SA_SIGINFO and SA_RESTART. Those three configures the handler to be on the 
 * alternative Stack (in order to not corrupt the Stack Frame if any error occurs at the time of the handling). Aside, adds information to the handler and reset the
 * signal handler after the handler controls the default signal. 
 * 
 * <param> sa is the default sigaction which must be set with certain flags to be a hint to the handler. </param>
 * <param> ss is the Signal Stack which is the used for handling the raised signal while avoiding any Stack Frame corruption </param>
 * <param> frame is the Stack Exception Frame which allocates constantly the exceptions occured at execution time. </param>
 * <exception> No throw is required for this function, but if the alternative stack fails to set or sigaction fails as well. The execution got aborted. </exception>
 */
extern void __except_init(struct sigaction *, stack_t *, ExceptionFrame *);
/**
 * __chk_except_name sets the local variable created by catch statement with the proper arguments provided by the general purpose exception. 
 * Initially checks the type of the current exception. When the switching is finally found. Simply copies all the memory addressing to the local variable
 * which is a double pointer. So the changes shall keep after this function goes out of scope. 
 * If the type name does not equals or no Exception local variable is provided. Then the execution got aborted and no cleanup is performed. 
 * 
 * <param> local is the pointer to pointer to local variable placed by the catch statement which is used after by the programmer if it's needed. </param>
 * <param> __exceptionName refers to the exception type name at the very moment when the execution reaches catch statement. </param>
 * <param> __exName is the exception type name for the local variable generated by catch statement. </param>
 * <exception> No throw is given. However, if no Exception type or no match for the exception type is given to the function. Then this function will abort() and no cleanup is performed. 
 */
extern int __chk_except_name(void **, const char *, const char *);
/**
 * Performs quite famiarly as __chk_except_name but this returns zero or one depending if the type is a built in one or a customized.
 * Basically checks for the type of local variable and the raised exception. If Exception or customized type name (And matches, either) is formally passed to this function, then will return one.
 * But, if the type matches to a built in exception then returns zero. 
 * If no match occurs, zero as well is returned to the caller. 
 * 
 * <param> __exceptionName refers to the exception type name at the very moment when the execution reaches catch statement. </param>
 * <param> __exName is the exception type name for the local variable generated by catch statement. </param>
 */
extern int __chk_except_isBuiltin(const char *, const char *);
/**
 * By taking the context from the Stack Context, retrieve the latest called function and right after 
 * calls the Stack Unwinding procedure, which calls the local object destructors to free any heap memories 
 * allocated for that local object (strings, or any other kind of heap object). 
 * It expects an integral integer as return value defined by the Stack Unwinding procedure (At the time of local destructors). 
 * Will return UnwindSuccess if the Stack got unwound, or terminate the process, 'cause the function didn't acquire any symbol 
 * related to the execution. Quite improbable for it to happen, though. 
 * 
 * <returns> Returns an integer in case of successful Stack Unwinding is performed. This is the only valid mark for this function. In case of failure, the execution 
 * should return one of this types: UnwindNoReg, UnwindNoInfo or UnwindNoSymbol which are enumerated as 1, 2, 3 exit codes respectively. 
 * <exception> Exception safe as many others. In case of invalid return value, the global destructors are safely called (_fini).  
 */
extern int __unwindPtrHandler(void);
/**
 * Using the string-like function name, callBacktraceUnwind performs the right Stack Unwinding from the latest function called until there is a safe point in single-threaded 
 * execution. If main function is reached, then no more destructors are called, 'cause this is the top of backtrace available. If a function is deeper in the backtrace and a catch clause 
 * is checked (StackContext takes this information. That's why it's useful), then the destructors are called in the same way as backtrace does it until the function is reached. Right after, UnwindSuccess
 * is returned to __unwindPtrHandler to be selected with resume execution or terminate it with proper cleanups.
 * A failure may exist if DestructorNull, DestructorFreeFailed or DestructorNoInfo is returned at local destructor execution. In any case, execution terminates in a safely way. 
 * 
 * <param> symRet is the string-like function name which marks the top of the backtrace. symRet may point to any function in the Call Stack, even main. But no further steps can be backtraced. 
 * <returns> Returns an integral integer value. In case of valid unwinding UnwindMainReached or UnwindSuccess is returned which safely resume execution in a single-threaded environment. 
 * For a failure, UnwindNoInfo is returned and __unwindPtrHandler should handle it. 
 * <see> __unwindPtrHandler for UnwindNoInfo handling. 
 * <exception> No exception throws from this point. If the symbol associated to specific destructor remains null or invalid address, the behavior is undefined. 
 */
extern int callBacktraceUnwind(const char *);
/**
 * Using two string-like function name, __callLocalDestructors evaluates in every call if the function is the same as the one which is expected to be the Top in Exception Handling. 
 * If Frames are available then iterates over a global array and checking the string-like function name calls the destructors for local objects and places a flag when a local object is 
 * destroyed. 
 * This needs to be modified to be a Stack global data structure [WIP]. 
 * 
 * <param> __ehRet is the Top of function in the backtrace process. If the string-like function name equals to this, then it should return DestructorTopReached. Successful Stack Unwinding was performed.
 * <param> __ehBt indicates the string-like function name of the actual function in the backtrace process. It's used in the destructor local object calls at Stack Unwinding. 
 * <returns> Should return DestructorTopReached if normal Stack Unwinding occurs, which is the average case scenario. DestructorFramesAvailable is identified if more possible destructors are available
 * into the Stack Unwinding process. This returning (DestructorFramesAvailable) is a hint to callBacktraceUnwind to continue execution with step in cursor into another frame into the Call Stack. 
 * <exception> Exceptions shouldn't occur at all. This is safe even for reflection (will return null if NoSymbol is available). But, the behavior is undefined if the destructor may not point to 
 * the destructor class. If DESTRUCTOR expansion is rightfully executed, it's fair impossible for this to be an undefined behavior. 
 */
extern int __callLocalDestructors(const char *, const char *);
/**
 * Reflection support is lightly implemented by reading its own executable. Iterates over the Symbol table (If any API has stripped symbol table, the behavior is undefined) and looks for the rightful
 * memory address for string-like function name provided to the function. If fails to retrieve any information for the ELF binary. Should terminates the execution and stderr is set marking the 
 * error as well as a message describing the error itself. 
 * 
 * <param> funcName is the string-like function name to be searched onto the Symbol Table. If parameter is null, the behavior is undefined.
 * <returns> Returns the memory address which belongs to its string-like function name. As a void pointer and allowed in Posix; it can be casted to a function pointer and then explicitly call it. 
 * <exception> No exception is thrown from this function. Yet, may terminate execution and if does it, stderr (C Standard error control) is properly set with error code and message related to it.  
 */
extern void *reflectStrFuncName(const char *);
/**
 * __exception_push_object adds into the __unwindFrames global array information for any local object instantiated via stackalloc. 
 * By doing it, places the destructor, the actual pointer to be instantiated and the function where the local object was created. 
 * When it happens, the initial flag is marked as false (0), with that, the system assures that the pointer is still on the run. It ain't affected or destroyed any heap instances by the Garbage Collector.
 * 
 * <param> this points to the latest instantiated object. Get the information for that class. Any heap allocations or modifications retains in here as well, with no further modifications.
 * <param> func is the actual function who forces the local object to be pushed into the __unwindFrames global array table. Strictly necessary for possible exception handling later. 
 * <param> dtor is the destructor associated to the local object. As well as func, dtor needs to be preserved for possible exception handling. 
 * <exception> Should throw exception if this is null. Which implies no Stack allocation was given for that object. [WIP]
 */
extern void __exception_push_object(void *, const char *, void (*)(void));
/**
 * One of the most important function for exception handling procedure. This openly throws the first exception into the StackException frames. 
 * First takes the exception allocated and using a local variable to update the frame (created by try statement). 
 * If this frame is null, then an unhandled exception occured, and so on prints the exception reason it was previously allocated in functions like buildException and EnableException. 
 * If the frame exists, places the information of the exception into the frame and executes __unwindPtrHandler to handle the Stack Unwinding process. Right after, switches based on the UnwindStatus 
 * return from the __unwindPtrHandler function. If the code is either UnwindSuccess or UnwindMainReached, the execution resumes into the finally clause, or terminates the execution properly.
 * If none of UnwindCodes are given, the default action is abort() the execution with no cleanup performed. It's quite much impossible for this to happen, no matter what. 
 * 
 * <param> e points to the actual exception object was thrown, preserves the information of the inner exception. 
 * <param> file is a simple string which uses the actual name where error occured.
 * <param> line is the line number where the exception was thrown. 
 * <exception> If except_raise couldn't handle the exception, this is rethrown and therefore the execution abruptly aborts wit the latest exception. If handles it, no exception occurs instead. 
 */
extern void except_raise(const ExceptionClass *, const char *, int);
/**
 * Simple mechanism to delete any \x characters found in the string message. No further explanations are required for this supportive function in terms of Exception Handling.
 * 
 * <param> str points to the original message variable.
 * <param> str2 is the expected to be changed message. With no \x escapes characters within. 
 * <returns> Returns a char pointer with the modified values from the original messages and with '\0' if it wasn't provided. 
 */
extern char *delete_char(char *, char *);
/**
 * When an abnormal execution is performed (either way by RuntimeException or bad Exception Handling codes), this function shows out the status of every register at the moment when the exception
 * could not be handled by the Exception Handling method. Also, shows the memory addressing associated to that value placed in the register. 
 * 
 * <exception> It's expected to be not throwable no matter what. But, SIGSEGV signal could be catch incorrectly if __context is null or the register wasn't properly set via getcontext().
 */
extern void dump_regs(void);
/**
 * handler is an useful function used for catching SIGSEGV or SIGTERM signals provided in Linux or any UNIX-based. Simply put, switches over the error codes and execute the respective action for any case.
 * When a SIGSEGV is generated, by taking null memory address, pointing to undefined heap memory address or stack smash, the respective exception is thrown and the resume the execution if try->catch->finally
 * statement are properly set by the programmer and Stack Unwinding is performed. 
 * When a SIGTERM occurs (normally raised by RuntimeException), places the context given by struct sigaction (Linux specific) into the global context. Using that, dumps out the registers 
 * and its memory address.
 * If no handler is provided, then the execution shall be abort(). 
 */
extern void handler(int, siginfo_t *, void *);

/* exceptionName is useful to retrieve the Exception class name when a throw statement is generated in order to raise the exception itself */
extern char exceptionName[256];
/* Non used for the time being */
extern int exceptIndex;
/* Global scoped variables useful to retrieve the machine context (x64 System V) before any throw statement is raised */
extern ucontext_t __ctx, *__ctxPtr, *__context;
/* Non used */
extern ucontext_t arrayCtx[10];
/* Exception Frame which "unwinds" Stack Frame after every throw is raised in exception handling */
extern ExceptionFrame *stackException;
/* A simple Stack structure which takes every context when a throw statement is raised, useful to restore machine context when the stack gets unwound */
extern ContextFrame *stackContext;
/* Locally (but Global) scoped array structure used for retrieving pointers (particularly locals addressed via alloca()) and then calling their destructors */
extern UnwindFrame __unwindFrames[255];
/* A counter variable for getting how many pointers addressed via alloca are on the Stack Frame while its unwinding is activated */
extern int __countAllocInit;

/* Useful definitions */

/**
 * The following macros are used when throwing an exception needs to be performed. 
 * Basically the mechanism calls the internal function buildException with the respective 
 * value depending on the type of exception and the message 
 */
#define throw 
#define MemoryAccessException(msg) buildException(MEM_EXCEPT, #msg)
#define DivideByZeroException(msg) buildException(DIV_ZERO_EXCEPT, #msg)
#define FileNotFoundException(msg) buildException(NOT_FOUND_EXCEPT, #msg)
#define DataNotFoundException(msg) buildException(DATA_NOT_FOUND_EXCEPT, #msg)
#define SystemInterruptedException(msg) buildException(INTERRUPTED_EXCEPT, #msg)
#define SystemRuntimeException(msg) buildException(RUNTIME_EXCEPT, #msg)
#define ArgumentException(msg) buildException(ARG_EXCEPT, #msg)
#define NullArgumentException(msg) buildException(NULL_ARG_EXCEPT, #msg)
#define FormatException(msg) buildException(FMT_EXCEPT, #msg) 
#define InvalidCastException(msg) buildException(INV_CAST_EXCEPT, #msg)
#define UnderflowException(msg) buildException(UNDER_EXCEPT, #msg)
#define OverflowException(msg) buildException(OVER_EXCEPT, #msg)
#define Exception(msg) buildException(STD_EXCEPT, #msg)


/**
 * The most important macro construct in terms of Exception Handling. This expands the try-catch-finally
 * construct by placing the useful information about machine context and the frame for the expected 
 * exception to come. 
 * Then the block evaluates the type of exception and handles it for finally come to an end the procedure. 
 */
#define try do \
	{ \
		volatile int except_flag; \
		stack_t ss; \
		struct sigaction sa; \
		ExceptionFrame frame; \
		ContextFrame ctxFrame; \
		getcontext(&ctxFrame.ctx_frame); \
		ctxFrame.prev = stackContext; \
		stackContext = &ctxFrame; \
		__except_init(&sa, &ss, &frame); \
		except_flag = sigsetjmp(frame.env, 1); \
		if(except_flag == ExceptionEntered) \
		{ 
#define catchEx(e, exName) \
			exName *e; \
			e = (void *)exInternal; \
			if(except_flag == ExceptionEntered) \
			{ \
				stackException = stackException->prev; \
				stackContext = stackContext->prev; \
			} \
		} \
		else if(frame.exception == (exInternal) && __chk_except_name((void **)&exInternal, exceptionName, #exName)) \
		{ \
			exName *e; \
			e = (void *)exInternal; \
			if(__chk_except_isBuiltin(exceptionName, #exName)) \
			{ \
				e = __customEx; \
				except_flag = ExceptionHandled; \
			} \
			else if(__chk_except_name((void **)&e, exceptionName, #exName) == 1 || __chk_except_isBuiltin(exceptionName, #exName)) \
			{ \
				except_flag = ExceptionHandled; \
			} \
			else \
			{ \
				; \
			}
#define finally \
			if(except_flag == ExceptionEntered) \
				stackException = stackException->prev; \
			stackContext = stackContext->prev; \
		} \
		{ \
			if(except_flag == ExceptionEntered) \
			{ \
				except_flag = ExceptionFinalized; \
			} \
			if(except_flag == ExceptionEntered) \
			{ \
				stackException = stackException->prev; \
				stackContext = stackContext->prev; \
			} \
		} \
		if(except_flag == ExceptionRaised) \
		{ \
			rethrow; \
		} \
		GC->Collect(); \
		GC->Free(ss.ss_sp); \
		ss.ss_sp = NULL; \
	} while(0);
#define rethrow except_raise(frame.exception, frame.file, frame.line)

/**
 * Unique identifiers for the type of built in exception, also for a custom exception. 
 * Is useful when buildException is called. 
 */
#define MEM_EXCEPT 0
#define DIV_ZERO_EXCEPT 1
#define NOT_FOUND_EXCEPT 2
#define DATA_NOT_FOUND_EXCEPT 3
#define INTERRUPTED_EXCEPT 4
#define RUNTIME_EXCEPT 5
#define ARG_EXCEPT 6
#define NULL_ARG_EXCEPT 7
#define FMT_EXCEPT 8
#define INV_CAST_EXCEPT 9
#define UNDER_EXCEPT 10
#define OVER_EXCEPT 11
#define STD_EXCEPT 12
#define CUSTOM_EXCEPT 99 /* Deprecated */

/**
 * Supportive macros which are useful in the Exception Handling process. 
 */
#define LPAREN (
#define RPAREN )
#define COMMA ,
#define CAT(L, R) CAT_(L, R)
#define CAT_(L, R) L ## R
#define EXPAND(...) __VA_ARGS__
#define REG(OP, D) EXPAND(OP CAT(REG_, D) RPAREN)
#define REG_Exception LPAREN Exception COMMA
#define REG_MemoryAccessException LPAREN MemoryAccessException COMMA
#define REG_FileNotFoundException LPAREN FileNotFoundException COMMA
#define REG_DataNotFoundException LPAREN DataNotFoundException COMMA
#define REG_SystemInterruptedException LPAREN SystemInterruptedException COMMA
#define REG_SystemRuntimeException LPAREN SystemRuntimeException COMMA
#define REG_ArgumentException LPAREN ArgumentException COMMA
#define REG_NullArgumentException LPAREN NullArgumentException COMMA
#define REG_FormatException LPAREN FormatException COMMA	
#define REG_InvalidCastException LPAREN InvalidCastException COMMA
#define REG_UnderflowException LPAREN UnderflowException COMMA
#define REG_OverflowException LPAREN OverflowException COMMA
#define __register_exception_name(exception) LPAREN exception COMMA 
#define setCatch(X, Y) catchEx(Y, X)
#define catch(A) REG(setCatch, A)

/**
 * Global variables used interchangeably in the Exception Handling process. The first one
 * is used in all the procedure, by retrieving the Exception "common" information and
 * copying to __customEx if needed. 
 * In other hand, __customEx is used specifically when a custom exception occurs. Internals 
 * modifies the value of this variable.  
 */
Exception *exInternal;
void *__customEx;

#endif /* EXCEPTION_H */
#include "GC_Class.h"
#include "Exception.h"

#define _GNU_SOURCE
#define __USE_GNU
#define UNW_LOCAL_ONLY

/**
 * Global Variables.
 * 
 * Note the fact this variables are only accessibles from this file scope marking as exception context variables,
 * which are used mostly in other places so the scope needs to be expanded to other source codes as well.
 */

/* exceptionName is useful to retrieve the Exception class name when a throw statement is generated in order to raise the exception itself */
char exceptionName[256];
/* Non used for the time being */
int exceptIndex = -1;
/* Global scoped variables useful to retrieve the machine context (x64 System V) before any throw statement is raised */
ucontext_t __ctx, *__ctxPtr, *__context;
/* Non used */
ucontext_t arrayCtx[10];
/* Exception Frame which "unwinds" Stack Frame after every throw is raised in exception handling */
ExceptionFrame *stackException = NULL;
/* A simple Stack structure which takes every context when a throw statement is raised, useful to restore machine context when the stack gets unwound */
ContextFrame *stackContext = NULL;
/* Locally (but Global) scoped array structure used for retrieving pointers (particularly locals addressed via alloca()) and then calling their destructors */
UnwindFrame __unwindFrames[255];
/* A counter variable for getting how many pointers addressed via alloca are on the Stack Frame while its unwinding is activated */
int __countAllocInit = 0;

/**
 * Constructors.
 * 
 * This constructors break the standard object constructs using new Instance. But it's necessary 'cause the exceptions
 * can't be allocated at any moment and after raise it from the constructor itself. It needs to be faster and throwable from 
 * any single point of the running process. Therefore, the new mechanism is using the throw directive, like so:
 * throw new -ExceptionName-, where -ExceptionName- is any Exception built in or customized by the programmer using Exception as base class 
 * through inheritance.
 */

/* When a new type of exception (Customized) is thrown, this method enables the customized exception with proper values and even call the constructor for it */
void __enable_customized_exception(char *, char *, void *, void *(*)(void));
/* Asserts there is a custom exception and so initialize the "general purpose" exception and then passes it to the custom exception (which is inherited) */
void isCustom(char *, char *);
/* This function initializes a general purpose exception (Built in) and after raises the exception to be handled or terminated */
void buildException(int, char *);
/* Sets correctly class methods to be callable from the user */
void *EnableException(const char *, int, int); 

/**
 * Exception Methods.
 * 
 * Built in methods for exception class. Useful for debugging or user information while running.
 */

/* Outputs the Stack Trace showing every method/function called from the time when the exception was raised (handled or terminated) */ 
int ExceptionClass_StackTrace(ExceptionClass * const);
/* Returns the exception type name */
char *ExceptionClass_GetType(ExceptionClass * const);
/* Compares two exceptions based on its type, if the types equals, then returns '1', '0' otherwise */
bool ExceptionClass_Equals(const char *, ExceptionClass * const);

/**
 * Supportive.
 * 
 * Useful functions to reflect the exception handling as many other languages.
 * The basic purpose is put into the Stack Frame the exception (via raise) and the calling iteratively the backtrace functions
 * while the stack is unwinding (returning to a safe point), calling the specific destructors for objects in the frames unwound. 
 * Other utilities relies on pushing the actual context into the "StackContext" to mantain stable the Stack, avoiding any corruptions 
 * in primitive local variables.
 */

/* When a try statement is executed, a call to __except_init is realized. Sets handlers and Exception Frame for catching an exception */
void __except_init(struct sigaction *, stack_t *, ExceptionFrame *);
/* Non used */
void __pushContext(ContextFrame *);
/* Select the built in exception type and properly updates the exception local variable with the one which was created when the exception was raised */
int __chk_except_name(void **, const char *, const char *);
/* Same as chk_except_name, but this evaluates if the exception type is customized or a built in one. If the exception is a built in one, returns '0'. '1' otherwise */
int __chk_except_isBuiltin(const char *, const char *); 
/* Initializes the Stack Unwinding process by checking information from backtrace and then executes an Stack Unwind by calling the local object destructors */
int __unwindPtrHandler(void);
/* By checking dynamically the functions (Reflection), executes the respective destructors if the pointers point to the functions to the unwound frames */
int __callLocalDestructors(const char *, const char *);
/* Iterative process which calls constantly the destructors in every frame just before unwinds ocurr for that frame */
int callBacktraceUnwind(const char *);
/* Reads own executable to retrieve the memory address (Needs to be re-casted) of specific function/class method by taking a function-like string as formal parameter */
void *reflectStrFuncName(const char *);
/* Non used */
void *__exception_malloc_init(size_t, const char *);
/* Marks the associated pointer (pointed into specific frame via alloca()) as well as the function-like string and the destructor to be released if Stack Unwinding occurs */
void __exception_push_object(void *, const char *, void (*)(void));
/* MOST IMPORTANT function. Raises an exception into the Exception Frame and consequently executes unwind process. If no catch statement is given. The destructors are properly called and the terminates it */
/* If RuntimeException occurs at any time. No raise is given, instead deploys the Stack Trace and dumps CPU Registers */
void except_raise(const ExceptionClass *, const char *, int);
/* Retrieves the line where throw statement was given (Abnoral situation such as MemoryAccessException) */
static void getLastLine(unw_word_t, char *, int *);
/* Avoid any \x, where x is a special char in the string (Secures no bad meanings exists in the string) */
char *delete_char(char *, char *);
/* Using the machine context, outputs the CPU registers with their values */
void dump_regs(void);
/* In case of a signal is supposed to be raised. Handler catches it and handles it correctly in the case of FPU or SIGSEGV occurs. 
/* If SIGTERM was set. Dumps out the registers and properly terminates the process with no cleanup. Avoid any GC calls or Standard C _fini statement executed */
void handler(int, siginfo_t *, void *);
/* Upwards the function to get the line which triggered the exception */ 
static char *stepOutLine(const char *, unw_word_t *);

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
optimize(0) void __enable_customized_exception(char *message, char *__exceptionName, void *ex, void *(*ctor)(void))
{
	isCustom(message, __exceptionName);
	strcpy((*(Exception *)ex).ExceptionType, exInternal->ExceptionType);
	(*(Exception *)ex).file = exInternal->file;
	(*(Exception *)ex).line = exInternal->line;
	strcpy((*(Exception *)ex).ExceptionMessage, exInternal->ExceptionMessage);
	(*(Exception *)ex).StackTrace = exInternal->StackTrace;
	(*(Exception *)ex).GetType = exInternal->GetType;
	(*(Exception *)ex).Equals = exInternal->Equals;
	__customEx = ex;
	exInternal = (Exception *)ex; /* Necessary, don't know why */
	ctor();
	except_raise(ex, exInternal->file, exInternal->line);
	return;
}

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
optimize(0) void isCustom(char *message, char *__exceptionName)
{
	char *function;
	char *file = GC_MALLOC(256);
	int line;
	unw_word_t pc;

	function = stepOutLine(stepOut(__func__), &pc);
	getLastLine(pc, file, &line);
	exInternal = EnableException(file, line, STD_EXCEPT);
	if (!strcmp(message, ""))
	{
		char str_cmp[100];

		strcpy(str_cmp, "System threw an exception of type: ");
		strcat(str_cmp, __exceptionName);
		strcpy(exInternal->ExceptionMessage, str_cmp);
		strcpy(exInternal->ExceptionType, __exceptionName);
		strcpy(exceptionName, __exceptionName);
	}
	else
	{
		char str[50];
		char str2[50];
		strcpy(str, delete_char(message, str2));
		strcpy(exInternal->ExceptionMessage, str);
		strcpy(exInternal->ExceptionType, __exceptionName);
		strcpy(exceptionName, __exceptionName);
	}
}

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
void buildException(int typeException, char *message)
{
	char *function;
	char *file = GC_MALLOC(256);
	int line;
	struct sigaction sa;
	unw_word_t pc;

	function = stepOutLine(__func__, &pc);
	getLastLine(pc, file, &line);
	switch(typeException) 
	{ 
		case MEM_EXCEPT: 
			exInternal = EnableException(file, line, MEM_EXCEPT); 
			if(strcmp(message, "") == 0) 
			{ 
				strcpy(exceptionName, "MemoryAccessException"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "MemoryAccessException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case DIV_ZERO_EXCEPT: 
			exInternal = EnableException(file, line, DIV_ZERO_EXCEPT); 
			if(strcmp(message, "") == 0) 
			{ 
				strcpy(exceptionName, "DivideByZeroException"); 
				except_raise(exInternal, file, line); 
			} 
			else
			{ 
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "DivideByZeroException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case NOT_FOUND_EXCEPT: 
			exInternal = EnableException(file, line, NOT_FOUND_EXCEPT); 
			if(strcmp(message, "") == 0) 
			{
				strcpy(exceptionName, "FileNotFoundException"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{ 
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "FileNotFoundException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case DATA_NOT_FOUND_EXCEPT: 
			exInternal = EnableException(file, line, DATA_NOT_FOUND_EXCEPT); 
			if(strcmp(message, "") == 0)
			{ 
				strcpy(exceptionName, "DataNotFoundException"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "DataNotFoundException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case INTERRUPTED_EXCEPT:
			exInternal = EnableException(file, line, INTERRUPTED_EXCEPT); 
			if(strcmp(message, "") == 0) 
			{ 
				strcpy(exceptionName, "SystemInterruptedException"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{ 
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "SystemInterruptedException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case RUNTIME_EXCEPT: 
			exInternal = EnableException(file, line, RUNTIME_EXCEPT); 
			strcpy(exceptionName, "SystemRuntimeException"); 
			printf("Unhandled Exception.\n\n"); 
			ExceptionClass_StackTrace(exInternal); 
			/* Experimental */
			sa.sa_sigaction = &handler;
			sa.sa_flags = SA_SIGINFO;
			if (sigaction(SIGTERM, &sa, NULL) < 0)
			{
				abort();
			}
			raise(SIGTERM); 
			break; 
		case ARG_EXCEPT: 
			exInternal = EnableException(file, line, ARG_EXCEPT); 
			if(strcmp(message, "") == 0) 
			{ 
				strcpy(exceptionName, "ArgumentException"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{ 
				char str[50]; 
				char str2[50];
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "ArgumentException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case NULL_ARG_EXCEPT: 
			exInternal = EnableException(file, line, NULL_ARG_EXCEPT); 
			if(strcmp(message, "") == 0) 
			{ 
				strcpy(exceptionName, "NullArgumentException"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{ 
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "NullArgumentException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case FMT_EXCEPT: 
			exInternal = EnableException(file, line, FMT_EXCEPT); 
			if(strcmp(message, "") == 0) 
			{ 
				strcpy(exceptionName, "FormatException"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{ 
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "FormatException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case INV_CAST_EXCEPT: 
			exInternal = EnableException(file, line, INV_CAST_EXCEPT); 
			if(strcmp(message, "") == 0) 
			{ 
				strcpy(exceptionName, "InvalidCastException"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{ 
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "InvalidCastException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case UNDER_EXCEPT: 
			exInternal = EnableException(file, line, UNDER_EXCEPT); 
			if(strcmp(message, "") == 0) 
			{ 
				strcpy(exceptionName, "UnderflowException"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{ 
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "UnderflowException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case OVER_EXCEPT: 
			exInternal = EnableException(file, line, OVER_EXCEPT); 
			if(strcmp(message, "") == 0) \
			{ 
				strcpy(exceptionName, "OverflowException"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{ 
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "OverflowException"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		case STD_EXCEPT:
			exInternal = EnableException(file, line, STD_EXCEPT); 
			if(strcmp(message, "") == 0) \
			{ 
				strcpy(exceptionName, "Exception"); 
				except_raise(exInternal, file, line); 
			} 
			else 
			{ 
				char str[50]; 
				char str2[50]; 
				strcpy(str, delete_char(message, str2)); 
				strcpy(exInternal->ExceptionMessage, str); 
				strcpy(exceptionName, "Exception"); 
				except_raise(exInternal, file, line); 
			} 
			break; 
		default:
			break;
	}
}

/**
 * EnableException initializes an instance to an exception object. Sets the important general purpose exception variables. Sets the file and line,
 * and establish the reason and other properties. But, the most important utility from this function is the initialization of class methods. 
 * The methods cannot be overriden. Strictly forbidden. These methods are only inheritables but no vtable should be avalaible for 'em. 
 * Note: This exception is automatically deallocated by the Garbage Collector without the help of finalizers (Std_finalizer is used). No need for the 
 * programmer to free it. 
 * 
 * <param> file refers to the file where the exception is generated. </param>
 * <param> line refers to the line in file where the exception is generated. </param>
 * <param> check is used to switch over the multiple built in exceptions types and selecting the one is needed. </param>
 * <exception> This function should be exception safe. If Garbage Collector fails to allocate some memory, a warning is displayed. Therefore the execution is terminated. </exception>
 */
void *EnableException(const char *file, int line, int check)
{
	ExceptionClass *this = Object_create(sizeof(ExceptionClass), 3);

	switch(check)
	{	
		case 0:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "MemoryAccessException");
			strcpy(this->ExceptionMessage, "System tried to access a memory instance which is invalid");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 1:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "DivideByZeroException");
			strcpy(this->ExceptionMessage, "Division by zero was performed");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 2:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "FileNotFoundException");
			strcpy(this->ExceptionMessage, "File was not found");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 3:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "DataNotFoundException");
			strcpy(this->ExceptionMessage, "Data to be search was not found");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 4:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "SystemInterruptedException");
			strcpy(this->ExceptionMessage, "An interrupt to the system was raised");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 5:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "SystemRuntimeException");
			strcpy(this->ExceptionMessage, "System found a critical error and can not be recovered");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 6:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "ArgumentException");
			strcpy(this->ExceptionMessage, "Arguments number given to instance is invalid");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 7:	
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "NullArgumentException");
			strcpy(this->ExceptionMessage, "Null argument was provided to method");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 8:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "FormatException");
			strcpy(this->ExceptionMessage, "A DataType format is invalid");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 9:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "InvalidCastException");
			strcpy(this->ExceptionMessage, "Conversion is invalidad or could not be performed");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 10:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "UnderflowException");
			strcpy(this->ExceptionMessage, "Value is less than the minimum limit provided in C");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 11:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "OverflowException");
			strcpy(this->ExceptionMessage, "Value is greater than the maximum limit provided in C");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		case 12:
			this->line = line;
			this->file = GC_MALLOC(strlen(file) + 1);
			strcpy(this->file, file);
			strcpy(this->ExceptionType, "Exception");
			strcpy(this->ExceptionMessage, "An exception was thrown at runtime");
			FUNCTION(ExceptionClass, StackTrace, 0);
			FUNCTION(ExceptionClass, GetType, 0);
			FUNCTION(ExceptionClass, Equals, 1);
			Object_prepare(&this->object);
			break;
		default:
			break;
	}
	return this;
}

/* Exception methods */

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
int ExceptionClass_StackTrace(ExceptionClass * const this)
{
	char sym[256];
	unw_cursor_t cursor;
    unw_context_t context;

    unw_getcontext(&context);
    unw_init_local(&cursor, &context);

    printf("Exception at %s:%d\n\nCall Stack: \n", exInternal->file, exInternal->line);
    while (unw_step(&cursor) > 0) 
    {
        unw_word_t offset, pc;
        unw_get_reg(&cursor, UNW_REG_IP, &pc);
        if (pc == 0) 
        {
            break;
        }
        printf("0x%lx at", pc);
        if (unw_get_proc_name(&cursor, sym, sizeof(sym), &offset) == 0) 
        	printf(" [%s + 0x%lx]\n", sym, offset);
        else 
            return UNW_ENOINFO;
    }
    return 0;
}

/**
 * Exception class method which evaluates the exception types of the calling method and another exception type. As declared as inline, the compile interprets this definition as 
 * "macro expansion". However, the static checking is far better. Returns true of false depending on comparing the two exception types.
 * 
 * <param> this refers to the class pointer which triggers this method. Is a C convention for C++ object type. </param>
 * <returns> Returns an integer constant boolean value. One for true returning, zero otherwise. 
 * <exception> If str1 is a null constant pointer, a MemoryAccessException shall be returned. If try statement (used with finally clause or a catch between) is set, then the error 
 * shall be noticed by the programmer. Otherwise, an abort execution is generated with no further information. </exception>
 */
inline bool ExceptionClass_Equals(const char *str1, ExceptionClass * const this)
{
	return ((strcmp(str1, this->ExceptionType) == 0) ? 1 : 0);
}

/**
 * Using this pseudo-called property, returns the exception type declared previously. If the exception is customized, returns correctly its name. 
 * <param> this refers to the class pointer which triggers this method. Is a C convention for C++ object type. </param>
 * <returns> Returns a string with the exception type of the calling exception. If a null pointer constant is given, the return value equals to null. 
 * <exception> It's safe for using. No exception is thrown no matter what happens. Even a null constant pointer. </exception>
 */
char *ExceptionClass_GetType(ExceptionClass * const this)
{
	return this->ExceptionType; 
}

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
void __except_init(struct sigaction *sa, stack_t *ss, ExceptionFrame *frame)
{
	/* stack_t */
	(*ss).ss_size = 0;
	(*ss).ss_flags = 0;
	(*ss).ss_sp = GC_MALLOC(SIGSTKSZ);
	(*ss).ss_size = SIGSTKSZ;
	/* ExceptionFrame */
	(*frame).prev = stackException;
	stackException = &(*frame);
	/* Sigaction */
	if(sigaltstack(&(*ss), NULL) == -1)
	{
		abort();
	}
	(*sa).sa_sigaction = &handler;
	(*sa).sa_flags = SA_ONSTACK | SA_SIGINFO | SA_RESTART;
	if(sigaction(SIGSEGV, &(*sa), NULL) < 0)
	{
		abort();
	}
	return;
}

/**
 * This function is deprecated. No uses are related to it.
 */
__attribute__((deprecated)) void __pushContext(ContextFrame *ctxFrame)
{
	char sym[256];
	unw_cursor_t cursor;
	unw_word_t offset;
	unw_word_t pc;

	unw_init_local(&cursor, &ctxFrame->ctx_frame);
	unw_get_reg(&cursor, UNW_REG_IP, &pc);
	unw_get_proc_name(&cursor, sym, sizeof(sym), &offset);
	(*ctxFrame).prev = stackContext;
	stackContext = ctxFrame;
}

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
optimize(0) int __chk_except_name(void **local, const char *__exceptionName, const char *__exName)
{
	Exception *__internalEx;
	MemoryAccessException *__internalMem;
	DivideByZeroException *__internalDiv;
	FileNotFoundException *__internalFile;
	DataNotFoundException *__internalData;
	SystemInterruptedException *__internalInt;
	SystemRuntimeException *__internalRun;
	ArgumentException *__internalArg;
	NullArgumentException *__internalNArg;
	FormatException *__internalFormat;
	InvalidCastException *__internalInv;
	UnderflowException *__internalUnder;
	OverflowException *__internalOver;
	switch(*__exName)
	{
		case 'M':
			__internalMem = (*local);
			if (!strcmp(exInternal->GetType(), exceptionName))
			{
				(*local) = (void *)exInternal;
			}
			else
			{
				__internalMem->object = exInternal->object;
				__internalMem->line = exInternal->line;
				__internalMem->file = exInternal->file;
				__internalMem->StackTrace = exInternal->StackTrace;
				__internalMem->GetType = exInternal->GetType;
				__internalMem->Equals = exInternal->Equals;
				(*local) = __internalMem;
			}
			if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
			{
				return 0;
			}
			break;
		case 'D':
			if(__exName[1] == 'i')
			{
				__internalDiv = (*local);
				if (!strcmp(exInternal->GetType(), exceptionName))
				{
					(*local) = (void *)exInternal;
				}
				else
				{
					__internalDiv->object = exInternal->object;
					__internalDiv->line = exInternal->line;
					__internalDiv->file = exInternal->file;
					__internalDiv->StackTrace = exInternal->StackTrace;
					__internalDiv->GetType = exInternal->GetType;
					__internalDiv->Equals = exInternal->Equals;
					(*local) = __internalDiv;
				}
				if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
				{
					return 0;
				}
			}
			else
			{
				__internalData = (*local);
				if (!strcmp(exInternal->GetType(), exceptionName))
				{
					(*local) = (void *)exInternal;
				}
				else
				{
					__internalData->object = exInternal->object;
					__internalData->line = exInternal->line;
					__internalData->file = exInternal->file;
					__internalData->StackTrace = exInternal->StackTrace;
					__internalData->GetType = exInternal->GetType;
					__internalData->Equals = exInternal->Equals;
					(*local) = __internalData;
				}
				if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
				{
					return 0;
				}
			}
			break;
		case 'F':
			if(__exName[1] == 'i')
			{
				__internalFile = (*local);
				if (!strcmp(exInternal->GetType(), exceptionName))
				{
					(*local) = (void *)exInternal;
				}
				else
				{
					__internalFile->object = exInternal->object;
					__internalFile->line = exInternal->line;
					__internalFile->file = exInternal->file;
					__internalFile->StackTrace = exInternal->StackTrace;
					__internalFile->GetType = exInternal->GetType;
					__internalFile->Equals = exInternal->Equals;
					(*local) = __internalFile;
				}
				if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
				{
					return 0;
				}
			}
			else
			{
				__internalFormat = (*local);
				if (!strcmp(exInternal->GetType(), exceptionName))
				{
					(*local) = (void *)exInternal;
				}
				else
				{
					__internalFormat->object = exInternal->object;
					__internalFormat->line = exInternal->line;
					__internalFormat->file = exInternal->file;
					__internalFormat->StackTrace = exInternal->StackTrace;
					__internalFormat->GetType = exInternal->GetType;
					__internalFormat->Equals = exInternal->Equals;
					(*local) = __internalFormat;
				}
				if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
				{
					return 0;
				}
			}
			break;
		case 'S':
			if (__exName[6] == 'I')
			{
				__internalInt = (*local);
				if (!strcmp(exInternal->GetType(), exceptionName))
				{
					(*local) = (void *)exInternal;
				}
				else
				{
					__internalInt->object = exInternal->object;
					__internalInt->line = exInternal->line;
					__internalInt->file = exInternal->file;
					__internalInt->StackTrace = exInternal->StackTrace;
					__internalInt->GetType = exInternal->GetType;
					__internalInt->Equals = exInternal->Equals;
					(*local) = __internalInt;
				}
				if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
				{
					return 0;
				}
			}
			else
			{
				__internalRun = (*local);
				if (!strcmp(exInternal->GetType(), exceptionName))
				{
					(*local) = (void *)exInternal;
				}
				else
				{
					__internalRun->object = exInternal->object;
					__internalRun->line = exInternal->line;
					__internalRun->file = exInternal->file;
					__internalRun->StackTrace = exInternal->StackTrace;
					__internalRun->GetType = exInternal->GetType;
					__internalRun->Equals = exInternal->Equals;
					(*local) = __internalRun;
				}
				if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
				{
					return 0;
				}
			}
			break;
		case 'A':
			__internalArg = (*local);
			if (!strcmp(exInternal->GetType(), exceptionName))
			{
				(*local) = (void *)exInternal;
			}
			else
			{
				__internalArg->object = exInternal->object;
				__internalArg->line = exInternal->line;
				__internalArg->file = exInternal->file;
				__internalArg->StackTrace = exInternal->StackTrace;
				__internalArg->GetType = exInternal->GetType;
				__internalArg->Equals = exInternal->Equals;
				(*local) = __internalArg;
			}
			if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
			{
				return 0;
			}
			break;
		case 'N':
			__internalNArg = (*local);
			if (!strcmp(exInternal->GetType(), exceptionName))
			{
				(*local) = (void *)exInternal;
			}
			else
			{
				__internalNArg->object = exInternal->object;
				__internalNArg->line = exInternal->line;
				__internalNArg->file = exInternal->file;
				__internalNArg->StackTrace = exInternal->StackTrace;
				__internalNArg->GetType = exInternal->GetType;
				__internalNArg->Equals = exInternal->Equals;
				(*local) = __internalNArg;
			}
			if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
			{
				return 0;
			}
			break;
		case 'I':
			__internalInv = (*local);
			if (!strcmp(exInternal->GetType(), exceptionName))
			{
				(*local) = (void *)exInternal;
			}
			else
			{
				__internalInv->object = exInternal->object;
				__internalInv->line = exInternal->line;
				__internalInv->file = exInternal->file;
				__internalInv->StackTrace = exInternal->StackTrace;
				__internalInv->GetType = exInternal->GetType;
				__internalInv->Equals = exInternal->Equals;
				(*local) = __internalInv;
			}
			if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
			{
				return 0;
			}
			break;
		case 'U':
			__internalUnder = (*local);
			if (!strcmp(exInternal->GetType(), exceptionName))
			{
				(*local) = (void *)exInternal;
			}
			else
			{
				__internalUnder->object = exInternal->object;
				__internalUnder->line = exInternal->line;
				__internalUnder->file = exInternal->file;
				__internalUnder->StackTrace = exInternal->StackTrace;
				__internalUnder->GetType = exInternal->GetType;
				__internalUnder->Equals = exInternal->Equals;
				(*local) = __internalUnder;
			}
			if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
			{
				return 0;
			}
			break;
		case 'O':
			__internalOver = (*local);
			if (!strcmp(exInternal->GetType(), exceptionName))
			{
				(*local) = (void *)exInternal;
			}
			else
			{
				__internalOver->object = exInternal->object;
				__internalOver->line = exInternal->line;
				__internalOver->file = exInternal->file;
				__internalOver->StackTrace = exInternal->StackTrace;
				__internalOver->GetType = exInternal->GetType;
				__internalOver->Equals = exInternal->Equals;
				(*local) = __internalOver;
			}
			if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0))
			{
				return 0;
			}
			break;
		default:
			__internalEx = (*local);
			if (!strcmp(exInternal->GetType(), exceptionName))
			{
				(*local) = (void *)exInternal;
			}
			else
			{
				__internalEx->object = exInternal->object;
				__internalEx->line = exInternal->line;
				__internalEx->file = exInternal->file;
				__internalEx->StackTrace = exInternal->StackTrace;
				__internalEx->GetType = exInternal->GetType;
				__internalEx->Equals = exInternal->Equals;
				(*local) = __internalEx;
			}
			if ((strcmp(__exceptionName, __exName) != 0) && (strcmp(__exName, "Exception") != 0)) /* Modificar este patrón */
			{
				return 0;
			}
			break;
	}
	return 1;
}

/**
 * Performs quite famiarly as __chk_except_name but this returns zero or one depending if the type is a built in one or a customized.
 * Basically checks for the type of local variable and the raised exception. If Exception or customized type name (And matches, either) is formally passed to this function, then will return one.
 * But, if the type matches to a built in exception then returns zero. 
 * If no match occurs, zero as well is returned to the caller. 
 * 
 * <param> __exceptionName refers to the exception type name at the very moment when the execution reaches catch statement. </param>
 * <param> __exName is the exception type name for the local variable generated by catch statement. </param>
 */
optimize(0) int __chk_except_isBuiltin(const char *__exceptionName, const char *__exName)
{
	if(!strcmp(__exceptionName, "MemoryAccessException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "DivideByZeroException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "FileNotFoundException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "DataNotFoundException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "SystemInterruptedException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "SystemRuntimeException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "ArgumentException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "NullArgumentException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "FormatException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "InvalidCastException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "UnderflowException"))
	{
		return 0;
	}
	else if(!strcmp(__exceptionName, "OverflowException"))
	{
		return 0;
	}	
	/*else if((!strcmp(__exceptionName, __exName)) || (!strcmp(__exName, "Exception")))
	{
		return 1;
	} */
	else if((!strcmp(__exceptionName, __exName)) && (strcmp(__exceptionName, "Exception")) && (strcmp(__exName, "Exception")))
	{
		return 1;
	}
	else
		return 0;
}

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
int __unwindPtrHandler(void)
{
	char symRet[256];
	char sym[256];
	ucontext_t auxctx;
	unw_cursor_t cursor;
	unw_context_t context;
	unw_word_t offset;
	unw_word_t pc;
	UnwindStatus us;

	unw_init_local(&cursor, &stackContext->ctx_frame);
	unw_get_reg(&cursor, UNW_REG_IP, &pc);
	if(!unw_get_proc_name(&cursor, symRet, sizeof(symRet), &offset))
	{
		;
	}
	us = callBacktraceUnwind(symRet); 
	if((us == UnwindSuccess) || (us == UnwindMainReached))
	{
		return UnwindSuccess;
	}
	else
	{
		printf("No information could be retrieved\n");
		getcontext(&auxctx);
		__context = &auxctx;
		atexit(dump_regs);
		exit(us);
	}
	return UnwindSuccess; /* Never reached */ 
}

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
int  callBacktraceUnwind(const char *symRet)
{
	DestructorStatus ds;
	char sym[256];
	int state;
	ucontext_t auxctx;
	unw_cursor_t cursor;
	unw_context_t context;

	unw_getcontext(&context);
	unw_init_local(&cursor, &context);
	int i = 0;
	while ((state = unw_step(&cursor)) > 0)
	{
		unw_word_t offset;
		unw_word_t pc;
		unw_get_reg(&cursor, UNW_REG_IP, &pc);
		if (pc == 0)
			return UnwindNoInfo; 
		if (!unw_get_proc_name(&cursor, sym, sizeof(sym), &offset))
		{
			if (!strcmp(sym, "main"))
			{
				return UnwindMainReached; /* return UnwindMainReached */
			}
			else if((!strcmp(sym, "__unwindPtrHandler")) || (!strcmp(sym, "buildException")) || (!strcmp(sym, "except_raise")))
			{
				continue;
			}
			else
			{
				ds = __callLocalDestructors(symRet, sym);
				i++;
				if(ds == DestructorTopReached)
				{
					return UnwindSuccess;
				}
				else if((ds == DestructorFramesAvailable) && (state > 0))
				{
					continue;
				}
				else 
				{
					getcontext(&auxctx);
					__context = &auxctx;
					atexit(dump_regs);
					exit(ds);
				}
			}
		}
	}
	return UnwindSuccess; /* Never reached */
}

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
optimize(0) int __callLocalDestructors(const char *__ehRet, const char *__ehBt)
{
	void *ptr;
	void *check;

	if (reflectStrFuncName(__ehRet) == reflectStrFuncName(__ehBt))
	{
		return DestructorTopReached; 
	}
	else
	{
		for (int i = (__countAllocInit - 1); i >= 0; i--)
		{
			check = reflectStrFuncName(__ehBt);
			if(__unwindFrames[i].funcAddr == check)
			{
				if(__unwindFrames[i].statusFreed == 0)
				{
					__unwindFrames[i].dtorPtr();
					__unwindFrames[i].statusFreed = 1;
				}
			}
			else
			{
				continue;
			}
		}
		return DestructorFramesAvailable;
	}
	return DestructorNoInfo; /* DestructorTopReached */
}

/**
 * Reflection support is lightly implemented by reading its own executable. Iterates over the Symbol table (If any API has stripped symbol table, the behavior is undefined) and looks for the rightful
 * memory address for string-like function name provided to the function. If fails to retrieve any information for the ELF binary. Should terminates the execution and stderr is set marking the 
 * error as well as a message describing the error itself. 
 * 
 * <param> funcName is the string-like function name to be searched onto the Symbol Table. If parameter is null, the behavior is undefined.
 * <returns> Returns the memory address which belongs to its string-like function name. As a void pointer and allowed in Posix; it can be casted to a function pointer and then explicitly call it. 
 * <exception> No exception is thrown from this function. Yet, may terminate execution and if does it, stderr (C Standard error control) is properly set with error code and message related to it.  
 */
void *reflectStrFuncName(const char *funcName)
{
	Elf64_Shdr *shdr;
	Elf64_Ehdr *ehdr;
	Elf *elf;
	Elf_Scn *scn;
	Elf_Data *data;
	void *retAddr;
	int cnt;
	int fd = 0;
	
	if ((fd = open("/proc/self/exe", O_RDONLY)) == -1)
		exit(1);
	elf_version(EV_CURRENT);
	if ((elf = elf_begin(fd, ELF_C_READ, NULL)) == NULL)
	{
		fprintf(stderr, "No ELF binary was found\n");
		exit(1);
	}
	if (((ehdr = elf64_getehdr(elf)) == NULL) || ((scn = elf_getscn(elf, ehdr->e_shstrndx)) == NULL) || ((data = elf_getdata(scn, NULL)) == NULL))
	{
		fprintf(stderr, "An error occured by reading the ELF binary\n");
		exit(1);
	}
	for (cnt = 1, scn = NULL; scn = elf_nextscn(elf, scn); cnt++)
	{
		if ((shdr = elf64_getshdr(scn)) == NULL)
			exit(1);
		if (shdr->sh_type == SHT_SYMTAB)
		{
			char *name;
			char *strName;
			data = 0;
			if ((data = elf_getdata(scn, data)) == 0 || data->d_size == 0)
			{
				fprintf(stderr, "No symbol table is available\n");
				exit(1);
			}
			Elf64_Sym *esym = (Elf64_Sym *)data->d_buf;
			Elf64_Sym *lastsym = (Elf64_Sym *)((char *)data->d_buf + data->d_size);
			for (; esym < lastsym; esym++)
			{
				if ((esym->st_value == 0) || (ELF64_ST_BIND(esym->st_info) == STB_WEAK) || (ELF64_ST_BIND(esym->st_info) == STB_NUM) || (ELF64_ST_TYPE(esym->st_info) != STT_FUNC))
					continue;
				name = elf_strptr(elf, shdr->sh_link, (size_t)esym->st_name);
				if (!name)
				{
					fprintf(stderr, "%s\n", elf_errmsg(elf_errno()));
					exit(-1);
				}
				if (!strcmp(funcName, name))
				{
					retAddr = (void *)esym->st_value;
				}
			}
			elf_end(elf);
		}
	}
	close(fd);
	return retAddr;
}

/**
 * This function is deprecated. Shouldn't be used with anything. This use may perform quite badly. 
 */
__attribute__((deprecated)) void *__exception_malloc_init(size_t size, const char *func)
{
	static int i = 0;
	void *ptr = GC_MALLOC(size);

	if(i == __countAllocInit)
	{
		if (ptr)
		{
			__unwindFrames[i].funcAddr = reflectStrFuncName(func);
			__unwindFrames[i].addrPtr = ptr;
			__unwindFrames[i].statusFreed = 0;
			i++;
			__countAllocInit = i;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		i = __countAllocInit;
		if (ptr)
		{
			__unwindFrames[i].funcAddr = reflectStrFuncName(func);
			__unwindFrames[i].addrPtr = ptr;
			__unwindFrames[i].statusFreed = 0;
			i++;
			__countAllocInit = i;
		}
		else
		{
			return NULL;
		}
	}
	return ptr;
}

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
void __exception_push_object(void *this, const char *func, void (*dtor)(void))
{
	if(this)
	{
		__unwindFrames[__countAllocInit].funcAddr = reflectStrFuncName(func);
		__unwindFrames[__countAllocInit].addrPtr = this;
		__unwindFrames[__countAllocInit].dtorPtr = dtor;
		__unwindFrames[__countAllocInit].statusFreed = 0;
		__countAllocInit++;
	}
	else
	{
		throw new NullArgumentException(); 
	}
	return; /* End of function */
}

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
void except_raise(const ExceptionClass *e, const char *file, int line)
{
	ucontext_t auxctx;
	UnwindStatus us;
	ExceptionFrame *p;

	p = stackException;
	if(p == NULL)
	{
		printf("Unhandled Exception: ");
		if(e->ExceptionMessage)
			printf("%s. ", e->ExceptionMessage);
		else
			printf("in 0x%p. ", e);
		if(file && line > 0)
			printf("Raised at %s:%d\n", file, line);
		abort();
	}
	p->exception = e;
	p->file = file;
	p->line = line;
	us = __unwindPtrHandler();
	switch(us)
	{
		case UnwindSuccess:
			stackException = stackException->prev;
			siglongjmp(p->env, ExceptionRaised);
			break;
		case UnwindMainReached:
			stackException = stackException->prev;
			siglongjmp(p->env, ExceptionRaised);
			break;
		case UnwindNoReg:
			printf("No register was set properly\n");
			getcontext(&auxctx);
			__context = &auxctx;
			atexit(dump_regs);
			exit(-1);
			break;
		case UnwindNoInfo:
			printf("The Stack Unwinding could not find the frame information\n");
			getcontext(&auxctx);
			__context = &auxctx;
			atexit(dump_regs);
			exit(-1);
			break;
		case UnwindNoSymbol:
			printf("No global symbol is available (Function Symbol)\n");
			getcontext(&auxctx);
			__context = &auxctx;
			atexit(dump_regs);
			exit(-1);
			break;
		default:
			abort();
			break;
	}
	return; /* Never reached */
}

/**
 * When an abnormal execution is performed (either way by RuntimeException or bad Exception Handling codes), this function shows out the status of every register at the moment when the exception
 * could not be handled by the Exception Handling method. Also, shows the memory addressing associated to that value placed in the register. 
 * 
 * <exception> It's expected to be not throwable no matter what. But, SIGSEGV signal could be catch incorrectly if __context is null or the register wasn't properly set via getcontext().
 */
void dump_regs(void)
{
	printf("\nRegistros de CPU: \n\n");
	printf("RIP: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RIP], &__context->uc_mcontext.gregs[REG_RIP]);
	printf("RAX: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RAX], &__context->uc_mcontext.gregs[REG_RAX]);
	printf("RBX: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RBX], &__context->uc_mcontext.gregs[REG_RBX]);
	printf("RCX: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RCX], &__context->uc_mcontext.gregs[REG_RCX]);
	printf("RDX: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RDX], &__context->uc_mcontext.gregs[REG_RDX]);
	printf("RBP: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RBP], &__context->uc_mcontext.gregs[REG_RBP]);
	printf("RSP: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RSP], &__context->uc_mcontext.gregs[REG_RSP]);
	printf("RSI: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RSI], &__context->uc_mcontext.gregs[REG_RSI]);
	printf("RDI: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RDI], &__context->uc_mcontext.gregs[REG_RDI]);
	printf("R8: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RDI], &__context->uc_mcontext.gregs[REG_R8]); 
	printf("R9: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RDI], &__context->uc_mcontext.gregs[REG_R9]);
	printf("R10: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RDI], &__context->uc_mcontext.gregs[REG_R10]);
	printf("R11: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RDI], &__context->uc_mcontext.gregs[REG_R11]);
	printf("R12: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RDI], &__context->uc_mcontext.gregs[REG_R12]);
	printf("R13: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RDI], &__context->uc_mcontext.gregs[REG_R13]);
	printf("R14: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RDI], &__context->uc_mcontext.gregs[REG_R14]);
	printf("R15: %08lld en %p\n", __context->uc_mcontext.gregs[REG_RDI], &__context->uc_mcontext.gregs[REG_R15]); 
	return;
}

/**
 * This function is used to get the line which triggered the exception when the handler takes control. Steps back by a single jump into 
 * the Stack Frame and recovers the specific line using the address related to that function. 
 * 
 * <param> lastAddr is the memory address for the latest function-like symbol. 
 * <param> file is the pointer expected to be filled with the file name of the function-like symbol.
 * <param> line is the pointer to an integer which provides the line where the exception was triggered. 
 * <exception> It's expected to be no throw safe.  
 */
void getLastLine(unw_word_t lastAddr, char *file, int *line)
{
	static char buffer[256];
	__attribute__((unused)) char *ret;
	FILE *f;

	sprintf(buffer, "/usr/bin/addr2line -C -e ./a.out -f -i %lx", lastAddr);
	f = popen(buffer, "r");
	if(!f)
		throw new FileNotFoundException();
	else 
	{
		ret = fgets(buffer, 256, f);
		ret = fgets(buffer, 256, f);
		if((*buffer) != '?')
		{
			int l;
			char *ptr = buffer;

			while((*ptr) != ':')
			{
				ptr++;
			}
			*ptr++ = 0;
			strcpy(file, buffer);
			sscanf(ptr, "%d", line);
			(*line) -= 1;
		}
		else
		{
			throw new DataNotFoundException("Could not find the associated line to the Exception");
			(*line) = 0;
		}
	}
	pclose(f);
	return;
}

/**
 * Simple mechanism to delete any \x characters found in the string message. No further explanations are required for this supportive function in terms of Exception Handling.
 * 
 * <param> str points to the original message variable.
 * <param> str2 is the expected to be changed message. With no \x escapes characters within. 
 * <returns> Returns a char pointer with the modified values from the original messages and with '\0' if it wasn't provided. 
 */
char *delete_char(char *str, char *str2)
{
	int size, j = 0;
	char respaldo;

	size = strlen(str);
	for(int i=0; i<size; i++)
	{
		if(str[i] != '"')
		{
			respaldo = str[i];
			str2[j] = respaldo;
			j++;
		}
	}
	str2[j] = '\0';
	return str2;
}

/**
 * handler is an useful function used for catching SIGSEGV or SIGTERM signals provided in Linux or any UNIX-based. Simply put, switches over the error codes and execute the respective action for any case.
 * When a SIGSEGV is generated, by taking null memory address, pointing to undefined heap memory address or stack smash, the respective exception is thrown and the resume the execution if try->catch->finally
 * statement are properly set by the programmer and Stack Unwinding is performed. 
 * When a SIGTERM occurs (normally raised by RuntimeException), places the context given by struct sigaction (Linux specific) into the global context. Using that, dumps out the registers 
 * and its memory address.
 * If no handler is provided, then the execution shall be abort(). 
 */
void handler(int sigNum, siginfo_t *si, void *ctx)
{
	switch(sigNum)
	{
		case SIGSEGV:
			throw new MemoryAccessException(); // THIS
			break;
		case SIGTERM:
			__context = (ucontext_t *)ctx;
			dump_regs();
			break;
		default:
			abort();
			break;
	}
	return; /* Never reached */
}

/**
 * When an exception is triggered. stepOutLine function starts off from the 
 * Stack Pointer at the Stack Frame and then go back to get the lines 
 * where the execution went through. 
 */
char *stepOutLine(const char *func, unw_word_t *pc_ret)
{
	bool state = 0;
	unw_cursor_t cursor;
	unw_context_t context;
	char *sym = GC_MALLOC(256);

	unw_getcontext(&context);
	unw_init_local(&cursor, &context);
	while ((state = unw_step(&cursor)) > 0)
	{
		unw_word_t offset;
		unw_word_t pc;
		unw_get_reg(&cursor, UNW_REG_IP, &pc);
		if (!pc)
			return NULL;
		if (!unw_get_proc_name(&cursor, sym, 256, &offset))
		{
			if (!strcmp(sym, func))
			{
				unw_step(&cursor);
				unw_get_reg(&cursor, UNW_REG_IP, &pc);
				if (!pc)
					return NULL;
				if (!unw_get_proc_name(&cursor, sym, 256, &offset))
				{
					(*pc_ret) = pc;
					return sym;
				}
			}
		}
	}
	return ((char *)0);
}
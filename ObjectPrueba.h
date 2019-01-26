#ifndef OBJECTPRUEBA_H
#define OBJECTPRUEBA_H

#include <gc.h>
#include <assert.h>
#include <libelf.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>

#define optimize(val) __attribute__((optimize(token_str(O, val))))
#define stringize(x) #x
#define tokenize(x, y) stringize(x ## y)
#define paste(x, y) x ## y
#define paste2(x, y) pasteFinal(x, y)
#define pasteFinal(x, y) x ## y
#define token(x, y) paste(x, y)
#define token2(x, y) paste2(x, y)
#define token_str(x, y) stringify(x##y)
#define stringify(x) #x 
#define PP_NARG(...) PP_NARG_(_, ##__VA_ARGS__, PP_RSEQ_N())
#define PP_NARG_(...) PP_ARG_N(__VA_ARGS__)
#define PP_ARG_N(                                     \
	_1, _2, _3, _4, _5, _6, _7, _8, _9, _10,          \
	_11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
	_21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
	_31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
	_41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
	_51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
	_61, _62, _63, N, ...) N
#define PP_RSEQ_N()                             \
	62, 61, 60,                                 \
		59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
		49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
		39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
		29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
		19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#define FUNCTION(type, name, count)                                          \
	do                                                                       \
	{                                                                        \
		this->name = Object_trampoline(&this->object, type##_##name, count); \
    } while (0)
#define FUNCTION2(type, type2, nArgs, nArgs2) \
	\
	do \
	{ \
		this->token(type2, nArgs) = Object_trampoline(&this->object, type ## _ ## type2 ## nArgs, nArgs2); \
	} while(0)
#define FUNCTIONP(type, name, count)                                                           \
	do                                                                                         \
	{                                                                                          \
		this->type##Private->name = Object_trampoline(&this->type##Private->object, type##Private##_##name, count); \
	} while (0)
#define delegate(return_type, function_body) \
({ return_type __fn__ function_body \
	   __fn__; \
})
#define Instance(obj, funcCount) Object_heap(obj, funcCount)
#define stackalloc(obj, funcCount) \
	({ \
		obj *this = ({ Object *this = alloca(sizeof(obj); Object_stacked(this, 1)); (void *)this; }); \
		FUNCTION(obj, obj, funcCount); \
		Object_prepare(&this->object); \
		this; \
	})
#define Object_heap(obj, funcCount) \
({                                 \
    obj *this; \
	if(!funcCount) \
	{ \
		this = ({ Object *this = Object_create(sizeof(obj), 0); (void *)this; });             \
	} \
	else \
	{ \
		this = ({ Object *this = Object_create(sizeof(obj), funcCount); (void *)this; }); \
	} \
    FUNCTION(obj, obj ## funcCount, funcCount); \
    Object_prepare(&this->object); \
    this; \
});
#define ArgsCount(T, nArgs, args...) \
	({ \
		int __sizeBase = sizeof(T); \
		const char *str = stringify(T); \
		char add[100] = "N"; \
		switch(nArgs) \
		{ \
			case 0: \
				isList(stringize(T)) ? ({ strcat(add, str); this = getListBase(add); }) : ({ callprotect(&this->object); FUNCTION2(T, T, nArgs, nArgs); Object_prepare(&this->object); this->token2(T, nArgs)(args); }); \
				break; \
			case 1 ... 5: \
				isList(stringize(T)) ? ({ throw new SystemRuntimeException(); }) : ({ callprotect(&this->object); FUNCTION2(T, T, nArgs, nArgs); Object_prepare(&this->object); this->token2(T, nArgs)(args); }); \
				break; \
		} \
		callprotect(&this->object); \
	})
#define EvArgs(T, nArgs, args...) \
	({ \
		switch(nArgs) \
		{ \
			case 0: \
				callprotect(&this->object); \
				FUNCTION2(T, T, nArgs, 0); \
				Object_prepare(&this->object); \
				this->T(args); \
				break; \
			case 1 ... 5 : \
				callprotect(&this->object); \
				FUNCTION2(T, T, nArgs, nArgs); \
				Object_prepare(&this->object); \
				this->T(args); \
				break; \
		} \
	})
#define localBase(T, args...) EvArgs(T, PP_NARG(args), ##args)
#define base(T, args...) \
	T *base = new Instance(T, PP_NARG(args)); \
	\
	base->T(args); \
	do \
	{ \
		if(!strcmp(isPtrOnStack(this), "True")) \
		{ \
			localBase(T, args); \
		} \
		else \
		{ \
			ArgsCount(T, PP_NARG(args), args); \
		} \
	} while(0)
#define virtual(T, F, C) \
	do \
	{ \
		callprotect(&this->object); \
		if(!this->__vptrFlag) \
			__initialize_virtual_table(&this->vmt ## T, &this->__vptrFlag); \
		if(this->__vptrFlag) \
		{ \
			if(!this->vmt ## T) \
			{ \
				throw new MemoryAccessException(); \
			} \
			else \
			{ \
				FUNCTION(T, F, C); \
				__register_virtual_method(this->vmt ## T, &this->__vptrCount, tokenize(T ## _, F), this->F, &this->object); \
			} \
		} \
	} while(0)
#define override(T, F, C) __register_overriden_method(this->vmt ## T, T ## _ ## F, &this->__vptrCount, #F, C, this->F, &this->object); 
#define vtable(T) vtable *vmt ## T; 
#define __overload(type, args...) token(type, PP_NARG(args))(args)
#define overload(type, args...) __overload(type, args)
#define new 
//#define String(...) string_overload(PP_NARG(__VA_ARGS__), ##__VA_ARGS__)
//#define StringBuilder(args...) string_overload(PP_NARG(args), ##args)
//#define Int16(args...) Int16(PP_NARG(args))
#define private(T) struct T ## Private *T##Private;
#define bool uint8_t
#define true ((uint8_t)1)
#define false ((uint8_t)0)

typedef struct ObjectRecord
{
	void (*destroy)(void);
	size_t codePageSize;
	unsigned char *codePage;
	unsigned char *codePagePtr;
} Object; /* This should be an inherited class */

typedef struct vtable
{
	int __chk_v; 
	char *__func;
	void (*vptr)(); 
} vtable;

extern void *Object_trampoline(Object *, void *, int);
extern void Object_destroy(Object *);
extern void *Object_create(size_t, int);
extern void Object_prepare(Object *);
extern void callprotect(Object *);
extern void *Object_stacked(Object *, int); 
extern char *isPtrOnStack(void *); 
extern bool isList(char *); 
extern void *getListBase(const char *);
extern void *getStdPtrBase(const char *);
extern void *Object_stackAlloc(size_t, int);
extern void __initialize_virtual_table(vtable **, int *);
extern void __register_virtual_method(vtable *, int *, char *, void (*)(), Object *);
extern bool __chk_func_override(char *, char *);
extern void __register_overriden_method(vtable *, void *, int *, char *, int, void *, Object *);

static const unsigned char kTrampoline[] = {
	// MOV RDI, 0x0
	0x48, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	// JMP [RIP + 0]
	0xff, 0x25, 0x00, 0x00, 0x00, 0x00,
	// DQ 0x0
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#include "String.h"
#include "Int16.h"
#include "Int32.h"
#include "Int64.h"
#include "UInt16.h"
#include "UInt32.h"
#include "UInt64.h"
#include "Char.h"
#include "Float.h"
#include "Double.h"
#include "File.h"
#include "List.h"
#include "Stack.h"
#include "Array.h"
#include "Conversion.h"
#include "GC_Class.h"
#include "Exception.h"
#include "KeyInfo.h"
#include "Console.h"

#endif /* OBJECTPRUEBA_H */
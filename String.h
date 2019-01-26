#include "ObjectPrueba.h"

#ifndef STRING_H
#define STRING_H

typedef struct StringPrivate StringPrivate;

typedef struct string
{
	Object object;
	private(String);
	int (*CompareTo)(const char *); 
	int (*Length)(void);
    struct string *(*Concatenate)(char *);  
    char *(*Get)(void);
	struct string *(*ToString)(void);
	#define String(args...) overload(String, args);
	void *(*String0)(void);
	void *(*String1)(const char *); 
	void *(*String2)(const char *, size_t);
} String;

extern int String_CompareTo(const char *, String * const);
extern int String_Length(String * const);
extern String *String_Concatenate(const char *, String * const); 
extern char *String_GetString(String * const);
extern String *String_ToString(String * const);
/* Ctor */
extern void *String_String0(String *);
extern void *String_String1(const char *, String *);
extern void *String_String2(const char *, size_t, String *);
//extern void *string_overload(int, ...);

#endif /* STRING_H */
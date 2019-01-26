#include "List.h"

/* List */
typedef struct List_Int16Private
{
    Int16 *value;
    Int16 **List;
    List_Int16Private *next;
    List_Int16Private *prev;
    List_Int16Private *L;
} List_Int16Private;

typedef struct List_Int32Private
{
    Int32 *value;
    Int32 **List;
    List_Int32Private *next;
    List_Int32Private *prev;
    List_Int32Private *L;
} List_Int32Private;

typedef struct List_Int64Private
{
    Int64 *value;
    Int64 **List;
    List_Int64Private *next;
    List_Int64Private *prev;
    List_Int64Private *L;
} List_Int64Private;

typedef struct List_UInt16Private
{
    UInt16 *value;
    UInt16 **List;
    List_UInt16Private *next;
    List_UInt16Private *prev;
    List_UInt16Private *L;
} List_UInt16Private;

typedef struct List_UInt32Private
{
    UInt32 *value;
    UInt32 **List;
    List_UInt32Private *next;
    List_UInt32Private *prev;
    List_UInt32Private *L;
} List_UInt32Private;

typedef struct List_UInt64Private
{
    UInt64 *value;
    UInt64 **List;
    List_UInt64Private *next;
    List_UInt64Private *prev;
    List_UInt64Private *L;
} List_UInt64Private;

typedef struct List_StringPrivate
{
    String *value;
    String **List;
    List_StringPrivate *next;
    List_StringPrivate *prev;
    List_StringPrivate *L;
} List_StringPrivate;

/* ReadOnly */
typedef struct ReadOnlyList_Int16Private
{
    const Int16 *value;
    const Int16 **List;
    const List_Int16Private *next;
    const List_Int16Private *prev;
    const List_Int16Private *L;
} ReadOnlyList_Int16Private;

typedef struct ReadOnlyList_Int32Private
{
    const Int32 *value;
    const Int32 **List;
    const List_Int32Private *next;
    const List_Int32Private *prev;
    const List_Int32Private *L;
} ReadOnlyList_Int32Private;

typedef struct ReadOnlyList_Int64Private
{
    const Int64 *value;
    const Int64 **List;
    const List_Int64Private *next;
    const List_Int64Private *prev;
    const List_Int64Private *L;
} ReadOnlyList_Int64Private;

typedef struct ReadOnlyList_UInt16Private
{
    const UInt16 *value;
    const UInt16 **List;
    const List_UInt16Private *next;
    const List_UInt16Private *prev;
    const List_UInt16Private *L;
} ReadOnlyList_UInt16Private;

typedef struct ReadOnlyList_UInt32Private
{
    const UInt32 *value;
    const UInt32 **List;
    const List_UInt32Private *next;
    const List_UInt32Private *prev;
    const List_UInt32Private *L;
} ReadOnlyList_UInt32Private;

typedef struct ReadOnlyList_UInt64Private
{
    const UInt64 *value;
    const UInt64 **List;
    const List_UInt64Private *next;
    const List_UInt64Private *prev;
    const List_UInt64Private *L;
} ReadOnlyList_UInt64Private;

typedef struct ReadOnlyList_StringPrivate
{
    const String *value;
    const String **List;
    const List_StringPrivate *next;
    const List_StringPrivate *prev;
    const List_StringPrivate *L;
} ReadOnlyList_StringPrivate;

/* Static */
typedef struct StaticList_Int16Private
{
    Int16 *value;
    Int16 **List;
    List_Int16Private *next;
    List_Int16Private *prev;
    List_Int16Private *L;
} StaticList_Int16Private;

typedef struct StaticList_Int32Private
{
    Int32 *value;
    Int32 **List;
    List_Int32Private *next;
    List_Int32Private *prev;
    List_Int32Private *L;
} StaticList_Int32Private;

typedef struct StaticList_Int64Private
{
    Int64 *value;
    Int64 **List;
    List_Int64Private *next;
    List_Int64Private *prev;
    List_Int64Private *L;
} StaticList_Int64Private;

typedef struct StaticList_UInt16Private
{
    UInt16 *value;
    UInt16 **List;
    List_UInt16Private *next;
    List_UInt16Private *prev;
    List_UInt16Private *L;
} StaticList_UInt16Private;

typedef struct StaticList_UInt32Private
{
    UInt32 *value;
    UInt32 **List;
    List_UInt32Private *next;
    List_UInt32Private *prev;
    List_UInt32Private *L;
} StaticList_UInt32Private;

typedef struct StaticList_UInt64Private
{
    UInt64 *value;
    UInt64 **List;
    List_UInt64Private *next;
    List_UInt64Private *prev;
    List_UInt64Private *L;
} StaticList_UInt64Private;

typedef struct StaticList_StringPrivate
{
    String *value;
    String **List;
    List_StringPrivate *next;
    List_StringPrivate *prev;
    List_StringPrivate *L;
} StaticList_StringPrivate;

/* Constructors */
void *NList_Int16(void);
void *NList_Int32(void);
void *NList_Int64(void);
void *NList_UInt16(void);
void *NList_UInt32(void);
void *NList_UInt64(void);
void *NList_String(void);
const void *NReadOnlyList_Int16(List_Int16 *); 
const void *NReadOnlyList_Int32(List_Int32 *);
const void *NReadOnlyList_Int64(List_Int64 *);
const void *NReadOnlyList_UInt16(List_UInt16 *);
const void *NReadOnlyList_UInt32(List_UInt32 *);
const void *NReadOnlyList_UInt64(List_UInt64 *);
const void *NReadOnlyList_String(List_String *);
/* Int16 */
const void *List_Int16_AsReadOnly(List_Int16 * const);
void List_Int16_Append(Int16 *, List_Int16 * const); 
void List_Int16_Delete(int, List_Int16 * const); 
void List_Int16_Reverse(List_Int16 * const);
void List_Int16_Show(List_Int16 * const); 
void List_Int16_Clear(List_Int16 * const);
int List_Int16_Count(List_Int16 * const);
int List_Int16_BinarySearch(Int16 *, List_Int16 * const);
char *List_Int16_GetType(List_Int16 * const);
Int16 **List_Int16_ToArray(List_Int16 * const);
/* Int32 */
const void *List_Int32_AsReadOnly(List_Int32 * const);
void List_Int32_Append(Int32 *, List_Int32 * const); 
void List_Int32_Delete(int, List_Int32 * const);
void List_Int32_Reverse(List_Int32 * const); 
void List_Int32_Show(List_Int32 * const); 
void List_Int32_Clear(List_Int32 * const);
int List_Int32_Count(List_Int32 * const);
int List_Int32_BinarySearch(Int32 *, List_Int32 * const);
char *List_Int32_GetType(List_Int32 * const);
Int32 **List_Int32_ToArray(List_Int32 * const);
/* Int64 */
const void *List_Int64_AsReadOnly(List_Int64 * const);
void List_Int64_Append(Int64 *, List_Int64 * const); 
void List_Int64_Delete(int, List_Int64 * const); 
void List_Int64_Reverse(List_Int64 * const);
void List_Int64_Show(List_Int64 * const);  
void List_Int64_Clear(List_Int64 * const);
int List_Int64_Count(List_Int64 * const);
int List_Int64_BinarySearch(Int64 *, List_Int64 * const);
char *List_Int64_GetType(List_Int64 * const);
Int64 **List_Int64_ToArray(List_Int64 * const);
/* UInt16 */
const void *List_UInt16_AsReadOnly(List_UInt16 * const);
void List_UInt16_Append(UInt16 *, List_UInt16 * const); 
void List_UInt16_Delete(int, List_UInt16 * const); 
void List_UInt16_Reverse(List_UInt16 * const);
void List_UInt16_Show(List_UInt16 * const); 
void List_UInt16_Clear(List_UInt16 * const);
int List_UInt16_Count(List_UInt16 * const);
int List_UInt16_BinarySearch(UInt16 *, List_UInt16 * const);
char *List_UInt16_GetType(List_UInt16 * const);
UInt16 **List_UInt16_ToArray(List_UInt16 * const);
/* UInt32 */
const void *List_UInt32_AsReadOnly(List_UInt32 * const);
void List_UInt32_Append(UInt32 *, List_UInt32 * const); 
void List_UInt32_Delete(int, List_UInt32 * const); 
void List_UInt32_Reverse(List_UInt32 * const);
void List_UInt32_Show(List_UInt32 * const); 
void List_UInt32_Clear(List_UInt32 * const);
int List_UInt32_Count(List_UInt32 * const);
int List_UInt32_BinarySearch(UInt32 *, List_UInt32 * const);
char *List_UInt32_GetType(List_UInt32 * const);
UInt32 **List_UInt32_ToArray(List_UInt32 * const);
/* UInt64 */
const void *List_UInt64_AsReadOnly(List_UInt64 * const);
void List_UInt64_Append(UInt64 *, List_UInt64 * const); 
void List_UInt64_Delete(int, List_UInt64 * const); 
void List_UInt64_Reverse(List_UInt64 * const);
void List_UInt64_Show(List_UInt64 * const); 
void List_UInt64_Clear(List_UInt64 * const);
int List_UInt64_Count(List_UInt64 * const);
int List_UInt64_BinarySearch(UInt64 *, List_UInt64 * const);
char *List_UInt64_GetType(List_UInt64 * const);
UInt64 **List_UInt64_ToArray(List_UInt64 * const);
/* String */
const void *List_String_AsReadOnly(List_String * const);
void List_String_Append(String *, List_String * const); 
void List_String_Delete(int, List_String * const); 
void List_String_Reverse(List_String * const);
void List_String_Show(List_String * const); 
void List_String_Clear(List_String * const);
int List_String_Count(List_String * const);
int List_String_BinarySearch(String *, List_String * const);
char *List_String_GetType(List_String * const);
String **List_String_ToArray(List_String * const);
/* Const Int16 */
char *ReadOnlyList_Int16_GetType(ReadOnlyList_Int16 * const);
int ReadOnlyList_Int16_IndexOf(Int16 *, ReadOnlyList_Int16 * const);
int ReadOnlyList_Int16_Count(ReadOnlyList_Int16 * const);
bool ReadOnlyList_Int16_Contains(Int16 *, ReadOnlyList_Int16 * const);
bool ReadOnlyList_Int16_Equals(void *, ReadOnlyList_Int16 * const);
void ReadOnlyList_Int16_CopyTo(Int16 **, int, ReadOnlyList_Int16 * const); 
/* Const Int32 */
char *ReadOnlyList_Int32_GetType(ReadOnlyList_Int32 * const);
int ReadOnlyList_Int32_IndexOf(Int32 *, ReadOnlyList_Int32 * const);
int ReadOnlyList_Int32_Count(ReadOnlyList_Int32 * const);
bool ReadOnlyList_Int32_Contains(Int32 *, ReadOnlyList_Int32 * const);
bool ReadOnlyList_Int32_Equals(void *, ReadOnlyList_Int32 * const);
void ReadOnlyList_Int32_CopyTo(Int32 **, int, ReadOnlyList_Int32 * const); 
/* Const Int64 */
char *ReadOnlyList_Int64_GetType(ReadOnlyList_Int64 * const);
int ReadOnlyList_Int64_IndexOf(Int64 *, ReadOnlyList_Int64 * const);
int ReadOnlyList_Int64_Count(ReadOnlyList_Int64 * const);
bool ReadOnlyList_Int64_Contains(Int64 *, ReadOnlyList_Int64 * const);
bool ReadOnlyList_Int64_Equals(void *, ReadOnlyList_Int64 * const);
void ReadOnlyList_Int64_CopyTo(Int64 **, int, ReadOnlyList_Int64 * const); 
/* Const UInt16 */
char *ReadOnlyList_UInt16_GetType(ReadOnlyList_UInt16 * const);
int ReadOnlyList_UInt16_IndexOf(UInt16 *, ReadOnlyList_UInt16 * const);
int ReadOnlyList_UInt16_Count(ReadOnlyList_UInt16 * const);
bool ReadOnlyList_UInt16_Contains(UInt16 *, ReadOnlyList_UInt16 * const);
bool ReadOnlyList_UInt16_Equals(void *, ReadOnlyList_UInt16 * const);
void ReadOnlyList_UInt16_CopyTo(UInt16 **, int, ReadOnlyList_UInt16 * const); 
/* Const UInt32 */
char *ReadOnlyList_UInt32_GetType(ReadOnlyList_UInt32 * const);
int ReadOnlyList_UInt32_IndexOf(UInt32 *, ReadOnlyList_UInt32 * const);
int ReadOnlyList_UInt32_Count(ReadOnlyList_UInt32 * const);
bool ReadOnlyList_UInt32_Contains(UInt32 *, ReadOnlyList_UInt32 * const);
bool ReadOnlyList_UInt32_Equals(void *, ReadOnlyList_UInt32 * const);
void ReadOnlyList_UInt32_CopyTo(UInt32 **, int, ReadOnlyList_UInt32 * const); 
/* Const UInt64 */
char *ReadOnlyList_UInt64_GetType(ReadOnlyList_UInt64 * const);
int ReadOnlyList_UInt64_IndexOf(UInt64 *, ReadOnlyList_UInt64 * const);
int ReadOnlyList_UInt64_Count(ReadOnlyList_UInt64 * const);
bool ReadOnlyList_UInt64_Contains(UInt64 *, ReadOnlyList_UInt64 * const);
bool ReadOnlyList_UInt64_Equals(void *, ReadOnlyList_UInt64 * const);
void ReadOnlyList_UInt64_CopyTo(UInt64 **, int, ReadOnlyList_UInt64 * const); 
/* Const String */
char *ReadOnlyList_String_GetType(ReadOnlyList_String * const);
int ReadOnlyList_String_IndexOf(String *, ReadOnlyList_String * const);
int ReadOnlyList_String_Count(ReadOnlyList_String * const);
bool ReadOnlyList_String_Contains(String *, ReadOnlyList_String * const);
bool ReadOnlyList_String_Equals(void *, ReadOnlyList_String * const);
void ReadOnlyList_String_CopyTo(String **, int, ReadOnlyList_String * const); 
/* Supportive */
void *ctorCheckArgs(const char *, int, ...);
static int getMultiplier(int);

/* List */
void *NList_Int16(void)
{
    List_Int16 *this = Object_create(sizeof(List_Int16), 11); 

    this->List_Int16Private = GC_MALLOC(sizeof(List_Int16Private));
    this->List_Int16Private->L = NULL;
    this->List_Int16Private->List = GC_MALLOC(sizeof(Int16 *) * 1024);
    FUNCTION(List_Int16, AsReadOnly, 0);
    FUNCTION(List_Int16, Append, 1);
    FUNCTION(List_Int16, Delete, 1);
    FUNCTION(List_Int16, Reverse, 0);
    FUNCTION(List_Int16, Show, 0);
    FUNCTION(List_Int16, Clear, 0);
    FUNCTION(List_Int16, Count, 0);
    FUNCTION(List_Int16, BinarySearch, 1);
    FUNCTION(List_Int16, ToArray, 0);
    FUNCTION(List_Int16, GetType, 0);
    Object_prepare(&this->object);
    return this;
}

void *NList_Int32(void)
{
    List_Int32 *this = Object_create(sizeof(List_Int32), 11); 

    this->List_Int32Private = GC_MALLOC(sizeof(List_Int32Private));
    this->List_Int32Private->L = NULL;
    this->List_Int32Private->List = GC_MALLOC(sizeof(Int32 *) * 1024);
    FUNCTION(List_Int32, AsReadOnly, 0);
    FUNCTION(List_Int32, Append, 1);
    FUNCTION(List_Int32, Delete, 1);
    FUNCTION(List_Int32, Reverse, 0);
    FUNCTION(List_Int32, Show, 0);
    FUNCTION(List_Int32, Clear, 0);
    FUNCTION(List_Int32, Count, 0);
    FUNCTION(List_Int32, BinarySearch, 1);
    FUNCTION(List_Int32, ToArray, 0);
    FUNCTION(List_Int32, GetType, 0);
    Object_prepare(&this->object);
    return this;
}

void *NList_Int64(void)
{
    List_Int64 *this = Object_create(sizeof(List_Int64), 11); 

    this->List_Int64Private = GC_MALLOC(sizeof(List_Int64Private));
    this->List_Int64Private->L = NULL;
    this->List_Int64Private->List = GC_MALLOC(sizeof(Int64 *) * 1024);
    FUNCTION(List_Int64, AsReadOnly, 0);
    FUNCTION(List_Int64, Append, 1);
    FUNCTION(List_Int64, Delete, 1);
    FUNCTION(List_Int64, Reverse, 0);
    FUNCTION(List_Int64, Show, 0);
    FUNCTION(List_Int64, Clear, 0);
    FUNCTION(List_Int64, Count, 0);
    FUNCTION(List_Int64, BinarySearch, 1);
    FUNCTION(List_Int64, ToArray, 0);
    FUNCTION(List_Int64, GetType, 0);
    Object_prepare(&this->object);
    return this;
}

void *NList_UInt16(void)
{
    List_UInt16 *this = Object_create(sizeof(List_UInt16), 11); 

    this->List_UInt16Private = GC_MALLOC(sizeof(List_UInt16Private));
    this->List_UInt16Private->L = NULL;
    this->List_UInt16Private->List = GC_MALLOC(sizeof(UInt16 *) * 1024);
    FUNCTION(List_UInt16, AsReadOnly, 0);
    FUNCTION(List_UInt16, Append, 1);
    FUNCTION(List_UInt16, Delete, 1);
    FUNCTION(List_UInt16, Reverse, 0);
    FUNCTION(List_UInt16, Show, 0);
    FUNCTION(List_UInt16, Clear, 0);
    FUNCTION(List_UInt16, Count, 0);
    FUNCTION(List_UInt16, BinarySearch, 1);
    FUNCTION(List_UInt16, ToArray, 0);
    FUNCTION(List_UInt16, GetType, 0);
    Object_prepare(&this->object);
    return this;
}

void *NList_UInt32(void)
{
    List_UInt32 *this = Object_create(sizeof(List_UInt32), 11); 

    this->List_UInt32Private = GC_MALLOC(sizeof(List_UInt32Private));
    this->List_UInt32Private->L = NULL;
    this->List_UInt32Private->List = GC_MALLOC(sizeof(UInt32 *) * 1024);
    FUNCTION(List_UInt32, AsReadOnly, 0);
    FUNCTION(List_UInt32, Append, 1);
    FUNCTION(List_UInt32, Delete, 1);
    FUNCTION(List_UInt32, Reverse, 0);
    FUNCTION(List_UInt32, Show, 0);
    FUNCTION(List_UInt32, Clear, 0);
    FUNCTION(List_UInt32, Count, 0);
    FUNCTION(List_UInt32, BinarySearch, 1);
    FUNCTION(List_UInt32, ToArray, 0);
    FUNCTION(List_UInt32, GetType, 0);
    Object_prepare(&this->object);
    return this;
}

void *NList_UInt64(void)
{
    List_UInt64 *this = Object_create(sizeof(List_UInt64), 11); 

    this->List_UInt64Private = GC_MALLOC(sizeof(List_UInt64Private));
    this->List_UInt64Private->L = NULL;
    this->List_UInt64Private->List = GC_MALLOC(sizeof(UInt64 *) * 1024);
    FUNCTION(List_UInt64, AsReadOnly, 0);
    FUNCTION(List_UInt64, Append, 1);
    FUNCTION(List_UInt64, Delete, 1);
    FUNCTION(List_UInt64, Reverse, 0);
    FUNCTION(List_UInt64, Show, 0);
    FUNCTION(List_UInt64, Clear, 0);
    FUNCTION(List_UInt64, Count, 0);
    FUNCTION(List_UInt64, BinarySearch, 1);
    FUNCTION(List_UInt64, ToArray, 0);
    FUNCTION(List_UInt64, GetType, 0);
    Object_prepare(&this->object);
    return this;
}

void *NList_String(void)
{
    List_String *this = Object_create(sizeof(List_String), 11); 

    this->List_StringPrivate = GC_MALLOC(sizeof(List_StringPrivate));
    this->List_StringPrivate->L = NULL;
    this->List_StringPrivate->List = GC_MALLOC(sizeof(String *) * 1024);
    FUNCTION(List_String, AsReadOnly, 0);
    FUNCTION(List_String, Append, 1);
    FUNCTION(List_String, Delete, 1);
    FUNCTION(List_String, Reverse, 0);
    FUNCTION(List_String, Show, 0);
    FUNCTION(List_String, Clear, 0);
    FUNCTION(List_String, Count, 0);
    FUNCTION(List_String, BinarySearch, 1);
    FUNCTION(List_String, ToArray, 0);
    FUNCTION(List_String, GetType, 0);
    Object_prepare(&this->object);
    return this;
}

/* ReadOnly */
const void *NReadOnlyList_Int16(List_Int16 *arg)
{
	StaticList_Int16 *this = Object_create(sizeof(ReadOnlyList(Int16)), 7);

	FUNCTION(ReadOnlyList_Int16, GetType, 0);
	FUNCTION(ReadOnlyList_Int16, IndexOf, 1); 
	FUNCTION(ReadOnlyList_Int16, Count, 0);
	FUNCTION(ReadOnlyList_Int16, Contains, 1);
	FUNCTION(ReadOnlyList_Int16, Equals, 1);
	FUNCTION(ReadOnlyList_Int16, CopyTo, 2);
	this->List_Int16Private->value = arg->List_Int16Private->value; 
	this->List_Int16Private->next = arg->List_Int16Private->next; 
	this->List_Int16Private->prev = arg->List_Int16Private->prev;
	this->List_Int16Private->L = arg->List_Int16Private->L;
	this->List_Int16Private->List = arg->List_Int16Private->List;
	Object_prepare(&this->object);
	return (ReadOnlyList_Int16 *)this;
}

const void *NReadOnlyList_Int32(List_Int32 *arg)
{
	StaticList_Int32 *this = Object_create(sizeof(ReadOnlyList(Int32)), 7);

	FUNCTION(ReadOnlyList_Int32, GetType, 0);
	FUNCTION(ReadOnlyList_Int32, IndexOf, 1); 
	FUNCTION(ReadOnlyList_Int32, Count, 0);
	FUNCTION(ReadOnlyList_Int32, Contains, 1);
	FUNCTION(ReadOnlyList_Int32, Equals, 1);
	FUNCTION(ReadOnlyList_Int32, CopyTo, 2);
	this->List_Int32Private->value = arg->List_Int32Private->value; 
	this->List_Int32Private->next = arg->List_Int32Private->next; 
	this->List_Int32Private->prev = arg->List_Int32Private->prev;
	this->List_Int32Private->L = arg->List_Int32Private->L;
	this->List_Int32Private->List = arg->List_Int32Private->List;
	Object_prepare(&this->object);
	return (ReadOnlyList_Int32 *)this;
}

const void *NReadOnlyList_Int64(List_Int64 *arg)
{
	StaticList_Int64 *this = Object_create(sizeof(ReadOnlyList(Int64)), 7);

	FUNCTION(ReadOnlyList_Int64, GetType, 0);
	FUNCTION(ReadOnlyList_Int64, IndexOf, 1); 
	FUNCTION(ReadOnlyList_Int64, Count, 0);
	FUNCTION(ReadOnlyList_Int64, Contains, 1);
	FUNCTION(ReadOnlyList_Int64, Equals, 1);
	FUNCTION(ReadOnlyList_Int64, CopyTo, 2);
	this->List_Int64Private->value = arg->List_Int64Private->value; 
	this->List_Int64Private->next = arg->List_Int64Private->next; 
	this->List_Int64Private->prev = arg->List_Int64Private->prev;
	this->List_Int64Private->L = arg->List_Int64Private->L;
	this->List_Int64Private->List = arg->List_Int64Private->List;
	Object_prepare(&this->object);
	return (ReadOnlyList_Int64 *)this;
}

const void *NReadOnlyList_UInt16(List_UInt16 *arg)
{
	StaticList_UInt16 *this = Object_create(sizeof(ReadOnlyList(UInt16)), 7);

	FUNCTION(ReadOnlyList_UInt16, GetType, 0);
	FUNCTION(ReadOnlyList_UInt16, IndexOf, 1); 
	FUNCTION(ReadOnlyList_UInt16, Count, 0);
	FUNCTION(ReadOnlyList_UInt16, Contains, 1);
	FUNCTION(ReadOnlyList_UInt16, Equals, 1);
	FUNCTION(ReadOnlyList_UInt16, CopyTo, 2);
	this->List_UInt16Private->value = arg->List_UInt16Private->value; 
	this->List_UInt16Private->next = arg->List_UInt16Private->next; 
	this->List_UInt16Private->prev = arg->List_UInt16Private->prev;
	this->List_UInt16Private->L = arg->List_UInt16Private->L;
	this->List_UInt16Private->List = arg->List_UInt16Private->List;
	Object_prepare(&this->object);
	return (ReadOnlyList_UInt16 *)this;
}

const void *NReadOnlyList_UInt32(List_UInt32 *arg)
{
	StaticList_UInt32 *this = Object_create(sizeof(ReadOnlyList(UInt32)), 7);

	FUNCTION(ReadOnlyList_UInt32, GetType, 0);
	FUNCTION(ReadOnlyList_UInt32, IndexOf, 1); 
	FUNCTION(ReadOnlyList_UInt32, Count, 0);
	FUNCTION(ReadOnlyList_UInt32, Contains, 1);
	FUNCTION(ReadOnlyList_UInt32, Equals, 1);
	FUNCTION(ReadOnlyList_UInt32, CopyTo, 2);
	this->List_UInt32Private->value = arg->List_UInt32Private->value; 
	this->List_UInt32Private->next = arg->List_UInt32Private->next; 
	this->List_UInt32Private->prev = arg->List_UInt32Private->prev;
	this->List_UInt32Private->L = arg->List_UInt32Private->L;
	this->List_UInt32Private->List = arg->List_UInt32Private->List;
	Object_prepare(&this->object);
	return (ReadOnlyList_UInt32 *)this;
}

const void *NReadOnlyList_UInt64(List_UInt64 *arg)
{
	StaticList_UInt64 *this = Object_create(sizeof(ReadOnlyList(UInt64)), 7);

	FUNCTION(ReadOnlyList_UInt64, GetType, 0);
	FUNCTION(ReadOnlyList_UInt64, IndexOf, 1); 
	FUNCTION(ReadOnlyList_UInt64, Count, 0);
	FUNCTION(ReadOnlyList_UInt64, Contains, 1);
	FUNCTION(ReadOnlyList_UInt64, Equals, 1);
	FUNCTION(ReadOnlyList_UInt64, CopyTo, 2);
	this->List_UInt64Private->value = arg->List_UInt64Private->value; 
	this->List_UInt64Private->next = arg->List_UInt64Private->next; 
	this->List_UInt64Private->prev = arg->List_UInt64Private->prev;
	this->List_UInt64Private->L = arg->List_UInt64Private->L;
	this->List_UInt64Private->List = arg->List_UInt64Private->List;
	Object_prepare(&this->object);
	return (ReadOnlyList_UInt64 *)this;
}

const void *NReadOnlyList_String(List_String *arg)
{
	StaticList_String *this = Object_create(sizeof(ReadOnlyList(String)), 7);

	FUNCTION(ReadOnlyList_String, GetType, 0);
	FUNCTION(ReadOnlyList_String, IndexOf, 1); 
	FUNCTION(ReadOnlyList_String, Count, 0);
	FUNCTION(ReadOnlyList_String, Contains, 1);
	FUNCTION(ReadOnlyList_String, Equals, 1);
	FUNCTION(ReadOnlyList_String, CopyTo, 2);
	this->List_StringPrivate->value = arg->List_StringPrivate->value; 
	this->List_StringPrivate->next = arg->List_StringPrivate->next; 
	this->List_StringPrivate->prev = arg->List_StringPrivate->prev;
	this->List_StringPrivate->L = arg->List_StringPrivate->L;
	this->List_StringPrivate->List = arg->List_StringPrivate->List;
	Object_prepare(&this->object);
	return (ReadOnlyList_String *)this;
}

/* Int16 */
inline const void *List_Int16_AsReadOnly(List_Int16 * const this)
{   
    return ReadOnlyCollection(Int16, this);
}

void List_Int16_Append(Int16 *arg, List_Int16 * const this)
{
    int i;
    Int16 **__resize;

    bool (*genericAddInt16)(Int16 *, List_Int16Private **) = delegate(bool, (Int16 *arg, List_Int16Private **this) 
    {  
        List_Int16Private *aux = GC_MALLOC(sizeof(List_Int16Private));
        List_Int16Private *tail = (*this);

        aux->value = arg;
        aux->next = NULL;
        if (!(*this))
        {
            aux->prev = NULL;
            (*this) = aux;
            aux = (*this);
            return true;
        }
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = aux;
        aux->prev = tail;
        return true;
    } );
    //if(genericAddInt16(arg, &this->List_Int16Private))
    if(genericAddInt16(arg, &this->List_Int16Private->L))
    {
        i = this->Count(); 
        if((i > 0) && (i % 1024 == 0))
        {
            __resize = GC_REALLOC(this->List_Int16Private->List, (getMultiplier(i) * 1024) * sizeof(Int16 *));
            if(!__resize)
            {
                // throw new MemoryAccessException("Realloc did not find an available memory block");
                abort();
            }
            else
            {
                this->List_Int16Private->List = __resize;
                this->List_Int16Private->List[i - 1] = arg;
            }
        }
        this->List_Int16Private->List[i - 1] = arg;
    }
    else
    {
        //throw new Exception("Failed attempt to append new element to a List");
        abort();
    }
    return;
}

void List_Int16_Delete(int index, List_Int16 * const this)
{
    bool (*genericDeleteInt16)(int, List_Int16Private **) = delegate(bool, (int index, List_Int16Private **this) 
    {
        List_Int16Private *aux = (*this);
        List_Int16Private *aux_r;

        if(!(*this))
            return false;
        if(index == 0)
        {
            if(!(*this)->prev)
                (*this) = aux->next;
        }
        for(int i=0; aux != NULL && i<index; i++)
            aux = aux->next;
        aux_r = aux;
        if(aux->next != NULL)
            aux_r->next->prev = aux_r->prev;
        if(aux->prev != NULL)
            aux_r->prev->next = aux_r->next;
        GC_FREE(aux);
        return true;
    } );
    if(genericDeleteInt16(index, &this->List_Int16Private->L) == true)
    {
        if(index == 0 && (this->Count() == false))
        {
            this->List_Int16Private->List[index] = NULL;
        }
        else if(index == 0 && (this->Count() != false))
        {
            for(int i=0; i<this->Count(); i++)
                this->List_Int16Private->List[i] = this->List_Int16Private->List[i + 1];
        }
        else if(index != 0 && (index < this->Count()))
        {
            for(int i=index; i<this->Count(); i++)
            {
                this->List_Int16Private->List[i] = this->List_Int16Private->List[i + 1];
            }
        }
        else if(index > (this->Count()))
        {
            // throw new DataNotFoundException();
            abort();
        }
    }
    else
    {
        // throw new DataNotFoundException();
        abort();
    }
    return;
}

void List_Int16_Reverse(List_Int16 * const this)
{
    void (*genericReverseInt16)(List_Int16Private **) = delegate(void, (List_Int16Private **this)
    {
        List_Int16Private *__t = NULL;
        List_Int16Private *__c = (*this);

        if(!(*this))
        {
            // throw new NullArgumentException();
            return;
        }
        while(__c != NULL)
        {
            __t = __c->prev;
            __c->prev = __c->next;
            __c->next = __t;
            __c = __c->prev;
        }
        if(__t != NULL)
            (*this) = __t->prev;
    } );
    return genericReverseInt16(&this->List_Int16Private->L);
}

void List_Int16_Show(List_Int16 * const this)
{
    if(!this->List_Int16Private->L)
    {
        //throw new NullArgumentException("List is null-defined");
        return;
    }
    else
    {
        List_Int16Private *aux = this->List_Int16Private->L;
        do
        {
            printf("%i\n", aux->value->Get());
            aux = aux->next;
        } while(aux != NULL);
    }
    return;
}

void List_Int16_Clear(List_Int16 * const this)
{
    if(!this->List_Int16Private->L)
        return;
    while(this->List_Int16Private->L != NULL)
        List_Int16_Delete(0, this);
    return;
}

int List_Int16_Count(List_Int16 * const this)
{
    int i = 1;
    List_Int16Private *aux = this->List_Int16Private->L;

    if(!aux)
    {
        return 0;
    }
    do
    {
        aux = aux->next;
        i++;
    } while(aux != NULL);
    return (i - 1);
}

int List_Int16_BinarySearch(Int16 *arg, List_Int16 * const this)
{
    int __l = 0;
    int __r = this->Count() - 1;
    int __m = __l + (__r - __l) / 2;

    while(__l <= __r)
    {
        if(this->List_Int16Private->List[__m]->Get() == arg->Get())
        {
            return __m;
        }
        if(this->List_Int16Private->List[__m]->Get() < arg->Get())
            __l = __m + 1;
        else
            __r = __m - 1;
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

char *List_Int16_GetType(List_Int16 * const this)
{
    return "List(Int16)";
}

Int16 **List_Int16_ToArray(List_Int16 * const this)
{
    Int16 **__arr = GC_MALLOC(sizeof(List_Int16 *) * this->Count());
    List_Int16Private *aux = this->List_Int16Private->L;

    for(int i=0; i<this->Count(); i++)
    {
        __arr[i] = aux->value;
        aux = aux->next;
    }
    return __arr;
}

/* Int32 */
inline const void *List_Int32_AsReadOnly(List_Int32 * const this)
{   
    return ReadOnlyCollection(Int32, this);
}

void List_Int32_Append(Int32 *arg, List_Int32 * const this)
{
    int i;
    Int32 **__resize;

    bool (*genericAddInt32)(Int32 *, List_Int32Private **) = delegate(bool, (Int32 *arg, List_Int32Private **this) 
    {  
        List_Int32Private *aux = GC_MALLOC(sizeof(List_Int32Private));
        List_Int32Private *tail = (*this);

        aux->value = arg;
        aux->next = NULL;
        if (!(*this))
        {
            aux->prev = NULL;
            (*this) = aux;
            aux = (*this);
            return true;
        }
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = aux;
        aux->prev = tail;
        return true;
    } );
    //if(genericAddInt32(arg, &this->List_Int32Private))
    if(genericAddInt32(arg, &this->List_Int32Private->L))
    {
        i = this->Count(); 
        if((i > 0) && (i % 1024 == 0))
        {
            __resize = GC_REALLOC(this->List_Int32Private->List, (getMultiplier(i) * 1024) * sizeof(Int32 *));
            if(!__resize)
            {
                // throw new MemoryAccessException("Realloc did not find an available memory block");
                abort();
            }
            else
            {
                this->List_Int32Private->List = __resize;
                this->List_Int32Private->List[i - 1] = arg;
            }
        }
        this->List_Int32Private->List[i - 1] = arg;
    }
    else
    {
        //throw new Exception("Failed attempt to append new element to a List");
        abort();
    }
    return;
}

void List_Int32_Delete(int index, List_Int32 * const this)
{
    bool (*genericDeleteInt32)(int, List_Int32Private **) = delegate(bool, (int index, List_Int32Private **this) 
    {
        List_Int32Private *aux = (*this);
        List_Int32Private *aux_r;

        if(!(*this))
            return false;
        if(index == 0)
        {
            if(!(*this)->prev)
                (*this) = aux->next;
        }
        for(int i=0; aux != NULL && i<index; i++)
            aux = aux->next;
        aux_r = aux;
        if(aux->next != NULL)
            aux_r->next->prev = aux_r->prev;
        if(aux->prev != NULL)
            aux_r->prev->next = aux_r->next;
        GC_FREE(aux);
        return true;
    } );
    if(genericDeleteInt32(index, &this->List_Int32Private->L) == true)
    {
        if(index == 0 && (this->Count() == false))
        {
            this->List_Int32Private->List[index] = NULL;
        }
        else if(index == 0 && (this->Count() != false))
        {
            for(int i=0; i<this->Count(); i++)
                this->List_Int32Private->List[i] = this->List_Int32Private->List[i + 1];
        }
        else if(index != 0 && (index < this->Count()))
        {
            for(int i=index; i<this->Count(); i++)
            {
                this->List_Int32Private->List[i] = this->List_Int32Private->List[i + 1];
            }
        }
        else if(index > (this->Count()))
        {
            // throw new DataNotFoundException();
            abort();
        }
    }
    else
    {
        // throw new DataNotFoundException();
        abort();
    }
    return;
}

void List_Int32_Reverse(List_Int32 * const this)
{
    void (*genericReverseInt32)(List_Int32Private **) = delegate(void, (List_Int32Private **this)
    {
        List_Int32Private *__t = NULL;
        List_Int32Private *__c = (*this);

        if(!(*this))
        {
            // throw new NullArgumentException();
            return;
        }
        while(__c != NULL)
        {
            __t = __c->prev;
            __c->prev = __c->next;
            __c->next = __t;
            __c = __c->prev;
        }
        if(__t != NULL)
            (*this) = __t->prev;
    } );
    return genericReverseInt32(&this->List_Int32Private->L);
}

void List_Int32_Show(List_Int32 * const this)
{
    if(!this->List_Int32Private->L)
    {
        //throw new NullArgumentException("List is null-defined");
        return;
    }
    else
    {
        List_Int32Private *aux = this->List_Int32Private->L;
        do
        {
            printf("%i\n", aux->value->Get());
            aux = aux->next;
        } while(aux != NULL);
    }
    return;
}

void List_Int32_Clear(List_Int32 * const this)
{
    if(!this->List_Int32Private->L)
        return;
    while(this->List_Int32Private->L != NULL)
        List_Int32_Delete(0, this);
    return;
}

int List_Int32_Count(List_Int32 * const this)
{
    int i = 1;
    List_Int32Private *aux = this->List_Int32Private->L;

    if(!aux)
    {
        return 0;
    }
    do
    {
        aux = aux->next;
        i++;
    } while(aux != NULL);
    return (i - 1);
}

int List_Int32_BinarySearch(Int32 *arg, List_Int32 * const this)
{
    int __l = 0;
    int __r = this->Count() - 1;
    int __m = __l + (__r - __l) / 2;

    while(__l <= __r)
    {
        if(this->List_Int32Private->List[__m]->Get() == arg->Get())
        {
            return __m;
        }
        if(this->List_Int32Private->List[__m]->Get() < arg->Get())
            __l = __m + 1;
        else
            __r = __m - 1;
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

char *List_Int32_GetType(List_Int32 * const this)
{
    return "List(Int32)";
}

Int32 **List_Int32_ToArray(List_Int32 * const this)
{
    Int32 **__arr = GC_MALLOC(sizeof(List_Int32 *) * this->Count());
    List_Int32Private *aux = this->List_Int32Private->L;

    for(int i=0; i<this->Count(); i++)
    {
        __arr[i] = aux->value;
        aux = aux->next;
    }
    return __arr;
}

/* Int64 */
inline const void *List_Int64_AsReadOnly(List_Int64 * const this)
{   
    return ReadOnlyCollection(Int64, this);
}

void List_Int64_Append(Int64 *arg, List_Int64 * const this)
{
    int i;
    Int64 **__resize;

    bool (*genericAddInt64)(Int64 *, List_Int64Private **) = delegate(bool, (Int64 *arg, List_Int64Private **this) 
    {  
        List_Int64Private *aux = GC_MALLOC(sizeof(List_Int64Private));
        List_Int64Private *tail = (*this);

        aux->value = arg;
        aux->next = NULL;
        if (!(*this))
        {
            aux->prev = NULL;
            (*this) = aux;
            aux = (*this);
            return true;
        }
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = aux;
        aux->prev = tail;
        return true;
    } );
    //if(genericAddInt64(arg, &this->List_Int64Private))
    if(genericAddInt64(arg, &this->List_Int64Private->L))
    {
        i = this->Count(); 
        if((i > 0) && (i % 1024 == 0))
        {
            __resize = GC_REALLOC(this->List_Int64Private->List, (getMultiplier(i) * 1024) * sizeof(Int64 *));
            if(!__resize)
            {
                // throw new MemoryAccessException("Realloc did not find an available memory block");
                abort();
            }
            else
            {
                this->List_Int64Private->List = __resize;
                this->List_Int64Private->List[i - 1] = arg;
            }
        }
        this->List_Int64Private->List[i - 1] = arg;
    }
    else
    {
        //throw new Exception("Failed attempt to append new element to a List");
        abort();
    }
    return;
}

void List_Int64_Delete(int index, List_Int64 * const this)
{
    bool (*genericDeleteInt64)(int, List_Int64Private **) = delegate(bool, (int index, List_Int64Private **this) 
    {
        List_Int64Private *aux = (*this);
        List_Int64Private *aux_r;

        if(!(*this))
            return false;
        if(index == 0)
        {
            if(!(*this)->prev)
                (*this) = aux->next;
        }
        for(int i=0; aux != NULL && i<index; i++)
            aux = aux->next;
        aux_r = aux;
        if(aux->next != NULL)
            aux_r->next->prev = aux_r->prev;
        if(aux->prev != NULL)
            aux_r->prev->next = aux_r->next;
        GC_FREE(aux);
        return true;
    } );
    if(genericDeleteInt64(index, &this->List_Int64Private->L) == true)
    {
        if(index == 0 && (this->Count() == false))
        {
            this->List_Int64Private->List[index] = NULL;
        }
        else if(index == 0 && (this->Count() != false))
        {
            for(int i=0; i<this->Count(); i++)
                this->List_Int64Private->List[i] = this->List_Int64Private->List[i + 1];
        }
        else if(index != 0 && (index < this->Count()))
        {
            for(int i=index; i<this->Count(); i++)
            {
                this->List_Int64Private->List[i] = this->List_Int64Private->List[i + 1];
            }
        }
        else if(index > (this->Count()))
        {
            // throw new DataNotFoundException();
            abort();
        }
    }
    else
    {
        // throw new DataNotFoundException();
        abort();
    }
    return;
}

void List_Int64_Reverse(List_Int64 * const this)
{
    void (*genericReverseInt64)(List_Int64Private **) = delegate(void, (List_Int64Private **this)
    {
        List_Int64Private *__t = NULL;
        List_Int64Private *__c = (*this);

        if(!(*this))
        {
            // throw new NullArgumentException();
            return;
        }
        while(__c != NULL)
        {
            __t = __c->prev;
            __c->prev = __c->next;
            __c->next = __t;
            __c = __c->prev;
        }
        if(__t != NULL)
            (*this) = __t->prev;
    } );
    return genericReverseInt64(&this->List_Int64Private->L);
}

void List_Int64_Show(List_Int64 * const this)
{
    if(!this->List_Int64Private->L)
    {
        //throw new NullArgumentException("List is null-defined");
        return;
    }
    else
    {
        List_Int64Private *aux = this->List_Int64Private->L;
        do
        {
            printf("%ld\n", aux->value->Get());
            aux = aux->next;
        } while(aux != NULL);
    }
    return;
}

void List_Int64_Clear(List_Int64 * const this)
{
    if(!this->List_Int64Private->L)
        return;
    while(this->List_Int64Private->L != NULL)
        List_Int64_Delete(0, this);
    return;
}

int List_Int64_Count(List_Int64 * const this)
{
    int i = 1;
    List_Int64Private *aux = this->List_Int64Private->L;

    if(!aux)
    {
        return 0;
    }
    do
    {
        aux = aux->next;
        i++;
    } while(aux != NULL);
    return (i - 1);
}

int List_Int64_BinarySearch(Int64 *arg, List_Int64 * const this)
{
    int __l = 0;
    int __r = this->Count() - 1;
    int __m = __l + (__r - __l) / 2;

    while(__l <= __r)
    {
        if(this->List_Int64Private->List[__m]->Get() == arg->Get())
        {
            return __m;
        }
        if(this->List_Int64Private->List[__m]->Get() < arg->Get())
            __l = __m + 1;
        else
            __r = __m - 1;
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

char *List_Int64_GetType(List_Int64 * const this)
{
    return "List(Int64)";
}

Int64 **List_Int64_ToArray(List_Int64 * const this)
{
    Int64 **__arr = GC_MALLOC(sizeof(List_Int64 *) * this->Count());
    List_Int64Private *aux = this->List_Int64Private->L;

    for(int i=0; i<this->Count(); i++)
    {
        __arr[i] = aux->value;
        aux = aux->next;
    }
    return __arr;
}

/* UInt16 */
inline const void *List_UInt16_AsReadOnly(List_UInt16 * const this)
{   
    return ReadOnlyCollection(UInt16, this);
}

void List_UInt16_Append(UInt16 *arg, List_UInt16 * const this)
{
    int i;
    UInt16 **__resize;

    bool (*genericAddUInt16)(UInt16 *, List_UInt16Private **) = delegate(bool, (UInt16 *arg, List_UInt16Private **this) 
    {  
        List_UInt16Private *aux = GC_MALLOC(sizeof(List_UInt16Private));
        List_UInt16Private *tail = (*this);

        aux->value = arg;
        aux->next = NULL;
        if (!(*this))
        {
            aux->prev = NULL;
            (*this) = aux;
            aux = (*this);
            return true;
        }
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = aux;
        aux->prev = tail;
        return true;
    } );
    //if(genericAddUInt16(arg, &this->List_UInt16Private))
    if(genericAddUInt16(arg, &this->List_UInt16Private->L))
    {
        i = this->Count(); 
        if((i > 0) && (i % 1024 == 0))
        {
            __resize = GC_REALLOC(this->List_UInt16Private->List, (getMultiplier(i) * 1024) * sizeof(UInt16 *));
            if(!__resize)
            {
                // throw new MemoryAccessException("Realloc did not find an available memory block");
                abort();
            }
            else
            {
                this->List_UInt16Private->List = __resize;
                this->List_UInt16Private->List[i - 1] = arg;
            }
        }
        this->List_UInt16Private->List[i - 1] = arg;
    }
    else
    {
        //throw new Exception("Failed attempt to append new element to a List");
        abort();
    }
    return;
}

void List_UInt16_Delete(int index, List_UInt16 * const this)
{
    bool (*genericDeleteUInt16)(int, List_UInt16Private **) = delegate(bool, (int index, List_UInt16Private **this) 
    {
        List_UInt16Private *aux = (*this);
        List_UInt16Private *aux_r;

        if(!(*this))
            return false;
        if(index == 0)
        {
            if(!(*this)->prev)
                (*this) = aux->next;
        }
        for(int i=0; aux != NULL && i<index; i++)
            aux = aux->next;
        aux_r = aux;
        if(aux->next != NULL)
            aux_r->next->prev = aux_r->prev;
        if(aux->prev != NULL)
            aux_r->prev->next = aux_r->next;
        GC_FREE(aux);
        return true;
    } );
    if(genericDeleteUInt16(index, &this->List_UInt16Private->L) == true)
    {
        if(index == 0 && (this->Count() == false))
        {
            this->List_UInt16Private->List[index] = NULL;
        }
        else if(index == 0 && (this->Count() != false))
        {
            for(int i=0; i<this->Count(); i++)
                this->List_UInt16Private->List[i] = this->List_UInt16Private->List[i + 1];
        }
        else if(index != 0 && (index < this->Count()))
        {
            for(int i=index; i<this->Count(); i++)
            {
                this->List_UInt16Private->List[i] = this->List_UInt16Private->List[i + 1];
            }
        }
        else if(index > (this->Count()))
        {
            // throw new DataNotFoundException();
            abort();
        }
    }
    else
    {
        // throw new DataNotFoundException();
        abort();
    }
    return;
}

void List_UInt16_Reverse(List_UInt16 * const this)
{
    void (*genericReverseUInt16)(List_UInt16Private **) = delegate(void, (List_UInt16Private **this)
    {
        List_UInt16Private *__t = NULL;
        List_UInt16Private *__c = (*this);

        if(!(*this))
        {
            // throw new NullArgumentException();
            return;
        }
        while(__c != NULL)
        {
            __t = __c->prev;
            __c->prev = __c->next;
            __c->next = __t;
            __c = __c->prev;
        }
        if(__t != NULL)
            (*this) = __t->prev;
    } );
    return genericReverseUInt16(&this->List_UInt16Private->L);
}

void List_UInt16_Show(List_UInt16 * const this)
{
    if(!this->List_UInt16Private->L)
    {
        //throw new NullArgumentException("List is null-defined");
        return;
    }
    else
    {
        List_UInt16Private *aux = this->List_UInt16Private->L;
        do
        {
            printf("%i\n", aux->value->Get());
            aux = aux->next;
        } while(aux != NULL);
    }
    return;
}

void List_UInt16_Clear(List_UInt16 * const this)
{
    if(!this->List_UInt16Private->L)
        return;
    while(this->List_UInt16Private->L != NULL)
        List_UInt16_Delete(0, this);
    return;
}

int List_UInt16_Count(List_UInt16 * const this)
{
    int i = 1;
    List_UInt16Private *aux = this->List_UInt16Private->L;

    if(!aux)
    {
        return 0;
    }
    do
    {
        aux = aux->next;
        i++;
    } while(aux != NULL);
    return (i - 1);
}

int List_UInt16_BinarySearch(UInt16 *arg, List_UInt16 * const this)
{
    int __l = 0;
    int __r = this->Count() - 1;
    int __m = __l + (__r - __l) / 2;

    while(__l <= __r)
    {
        if(this->List_UInt16Private->List[__m]->Get() == arg->Get())
        {
            return __m;
        }
        if(this->List_UInt16Private->List[__m]->Get() < arg->Get())
            __l = __m + 1;
        else
            __r = __m - 1;
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

char *List_UInt16_GetType(List_UInt16 * const this)
{
    return "List(UInt16)";
}

UInt16 **List_UInt16_ToArray(List_UInt16 * const this)
{
    UInt16 **__arr = GC_MALLOC(sizeof(List_UInt16 *) * this->Count());
    List_UInt16Private *aux = this->List_UInt16Private->L;

    for(int i=0; i<this->Count(); i++)
    {
        __arr[i] = aux->value;
        aux = aux->next;
    }
    return __arr;
}

/* UInt32 */
inline const void *List_UInt32_AsReadOnly(List_UInt32 * const this)
{   
    return ReadOnlyCollection(UInt32, this);
}

void List_UInt32_Append(UInt32 *arg, List_UInt32 * const this)
{
    int i;
    UInt32 **__resize;

    bool (*genericAddUInt32)(UInt32 *, List_UInt32Private **) = delegate(bool, (UInt32 *arg, List_UInt32Private **this) 
    {  
        List_UInt32Private *aux = GC_MALLOC(sizeof(List_UInt32Private));
        List_UInt32Private *tail = (*this);

        aux->value = arg;
        aux->next = NULL;
        if (!(*this))
        {
            aux->prev = NULL;
            (*this) = aux;
            aux = (*this);
            return true;
        }
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = aux;
        aux->prev = tail;
        return true;
    } );
    //if(genericAddUInt32(arg, &this->List_UInt32Private))
    if(genericAddUInt32(arg, &this->List_UInt32Private->L))
    {
        i = this->Count(); 
        if((i > 0) && (i % 1024 == 0))
        {
            __resize = GC_REALLOC(this->List_UInt32Private->List, (getMultiplier(i) * 1024) * sizeof(UInt32 *));
            if(!__resize)
            {
                // throw new MemoryAccessException("Realloc did not find an available memory block");
                abort();
            }
            else
            {
                this->List_UInt32Private->List = __resize;
                this->List_UInt32Private->List[i - 1] = arg;
            }
        }
        this->List_UInt32Private->List[i - 1] = arg;
    }
    else
    {
        //throw new Exception("Failed attempt to append new element to a List");
        abort();
    }
    return;
}

void List_UInt32_Delete(int index, List_UInt32 * const this)
{
    bool (*genericDeleteUInt32)(int, List_UInt32Private **) = delegate(bool, (int index, List_UInt32Private **this) 
    {
        List_UInt32Private *aux = (*this);
        List_UInt32Private *aux_r;

        if(!(*this))
            return false;
        if(index == 0)
        {
            if(!(*this)->prev)
                (*this) = aux->next;
        }
        for(int i=0; aux != NULL && i<index; i++)
            aux = aux->next;
        aux_r = aux;
        if(aux->next != NULL)
            aux_r->next->prev = aux_r->prev;
        if(aux->prev != NULL)
            aux_r->prev->next = aux_r->next;
        GC_FREE(aux);
        return true;
    } );
    if(genericDeleteUInt32(index, &this->List_UInt32Private->L) == true)
    {
        if(index == 0 && (this->Count() == false))
        {
            this->List_UInt32Private->List[index] = NULL;
        }
        else if(index == 0 && (this->Count() != false))
        {
            for(int i=0; i<this->Count(); i++)
                this->List_UInt32Private->List[i] = this->List_UInt32Private->List[i + 1];
        }
        else if(index != 0 && (index < this->Count()))
        {
            for(int i=index; i<this->Count(); i++)
            {
                this->List_UInt32Private->List[i] = this->List_UInt32Private->List[i + 1];
            }
        }
        else if(index > (this->Count()))
        {
            // throw new DataNotFoundException();
            abort();
        }
    }
    else
    {
        // throw new DataNotFoundException();
        abort();
    }
    return;
}

void List_UInt32_Reverse(List_UInt32 * const this)
{
    void (*genericReverseUInt32)(List_UInt32Private **) = delegate(void, (List_UInt32Private **this)
    {
        List_UInt32Private *__t = NULL;
        List_UInt32Private *__c = (*this);

        if(!(*this))
        {
            // throw new NullArgumentException();
            return;
        }
        while(__c != NULL)
        {
            __t = __c->prev;
            __c->prev = __c->next;
            __c->next = __t;
            __c = __c->prev;
        }
        if(__t != NULL)
            (*this) = __t->prev;
    } );
    return genericReverseUInt32(&this->List_UInt32Private->L);
}

void List_UInt32_Show(List_UInt32 * const this)
{
    if(!this->List_UInt32Private->L)
    {
        //throw new NullArgumentException("List is null-defined");
        return;
    }
    else
    {
        List_UInt32Private *aux = this->List_UInt32Private->L;
        do
        {
            printf("%i\n", aux->value->Get());
            aux = aux->next;
        } while(aux != NULL);
    }
    return;
}

void List_UInt32_Clear(List_UInt32 * const this)
{
    if(!this->List_UInt32Private->L)
        return;
    while(this->List_UInt32Private->L != NULL)
        List_UInt32_Delete(0, this);
    return;
}

int List_UInt32_Count(List_UInt32 * const this)
{
    int i = 1;
    List_UInt32Private *aux = this->List_UInt32Private->L;

    if(!aux)
    {
        return 0;
    }
    do
    {
        aux = aux->next;
        i++;
    } while(aux != NULL);
    return (i - 1);
}

int List_UInt32_BinarySearch(UInt32 *arg, List_UInt32 * const this)
{
    int __l = 0;
    int __r = this->Count() - 1;
    int __m = __l + (__r - __l) / 2;

    while(__l <= __r)
    {
        if(this->List_UInt32Private->List[__m]->Get() == arg->Get())
        {
            return __m;
        }
        if(this->List_UInt32Private->List[__m]->Get() < arg->Get())
            __l = __m + 1;
        else
            __r = __m - 1;
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

char *List_UInt32_GetType(List_UInt32 * const this)
{
    return "List(UInt32)";
}

UInt32 **List_UInt32_ToArray(List_UInt32 * const this)
{
    UInt32 **__arr = GC_MALLOC(sizeof(List_UInt32 *) * this->Count());
    List_UInt32Private *aux = this->List_UInt32Private->L;

    for(int i=0; i<this->Count(); i++)
    {
        __arr[i] = aux->value;
        aux = aux->next;
    }
    return __arr;
}

/* UInt64 */
inline const void *List_UInt64_AsReadOnly(List_UInt64 * const this)
{   
    return ReadOnlyCollection(UInt64, this);
}

void List_UInt64_Append(UInt64 *arg, List_UInt64 * const this)
{
    int i;
    UInt64 **__resize;

    bool (*genericAddUInt64)(UInt64 *, List_UInt64Private **) = delegate(bool, (UInt64 *arg, List_UInt64Private **this) 
    {  
        List_UInt64Private *aux = GC_MALLOC(sizeof(List_UInt64Private));
        List_UInt64Private *tail = (*this);

        aux->value = arg;
        aux->next = NULL;
        if (!(*this))
        {
            aux->prev = NULL;
            (*this) = aux;
            aux = (*this);
            return true;
        }
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = aux;
        aux->prev = tail;
        return true;
    } );
    //if(genericAddUInt64(arg, &this->List_UInt64Private))
    if(genericAddUInt64(arg, &this->List_UInt64Private->L))
    {
        i = this->Count(); 
        if((i > 0) && (i % 1024 == 0))
        {
            __resize = GC_REALLOC(this->List_UInt64Private->List, (getMultiplier(i) * 1024) * sizeof(UInt64 *));
            if(!__resize)
            {
                // throw new MemoryAccessException("Realloc did not find an available memory block");
                abort();
            }
            else
            {
                this->List_UInt64Private->List = __resize;
                this->List_UInt64Private->List[i - 1] = arg;
            }
        }
        this->List_UInt64Private->List[i - 1] = arg;
    }
    else
    {
        //throw new Exception("Failed attempt to append new element to a List");
        abort();
    }
    return;
}

void List_UInt64_Delete(int index, List_UInt64 * const this)
{
    bool (*genericDeleteUInt64)(int, List_UInt64Private **) = delegate(bool, (int index, List_UInt64Private **this) 
    {
        List_UInt64Private *aux = (*this);
        List_UInt64Private *aux_r;

        if(!(*this))
            return false;
        if(index == 0)
        {
            if(!(*this)->prev)
                (*this) = aux->next;
        }
        for(int i=0; aux != NULL && i<index; i++)
            aux = aux->next;
        aux_r = aux;
        if(aux->next != NULL)
            aux_r->next->prev = aux_r->prev;
        if(aux->prev != NULL)
            aux_r->prev->next = aux_r->next;
        GC_FREE(aux);
        return true;
    } );
    if(genericDeleteUInt64(index, &this->List_UInt64Private->L) == true)
    {
        if(index == 0 && (this->Count() == false))
        {
            this->List_UInt64Private->List[index] = NULL;
        }
        else if(index == 0 && (this->Count() != false))
        {
            for(int i=0; i<this->Count(); i++)
                this->List_UInt64Private->List[i] = this->List_UInt64Private->List[i + 1];
        }
        else if(index != 0 && (index < this->Count()))
        {
            for(int i=index; i<this->Count(); i++)
            {
                this->List_UInt64Private->List[i] = this->List_UInt64Private->List[i + 1];
            }
        }
        else if(index > (this->Count()))
        {
            // throw new DataNotFoundException();
            abort();
        }
    }
    else
    {
        // throw new DataNotFoundException();
        abort();
    }
    return;
}

void List_UInt64_Reverse(List_UInt64 * const this)
{
    void (*genericReverseUInt64)(List_UInt64Private **) = delegate(void, (List_UInt64Private **this)
    {
        List_UInt64Private *__t = NULL;
        List_UInt64Private *__c = (*this);

        if(!(*this))
        {
            // throw new NullArgumentException();
            return;
        }
        while(__c != NULL)
        {
            __t = __c->prev;
            __c->prev = __c->next;
            __c->next = __t;
            __c = __c->prev;
        }
        if(__t != NULL)
            (*this) = __t->prev;
    } );
    return genericReverseUInt64(&this->List_UInt64Private->L);
}

void List_UInt64_Show(List_UInt64 * const this)
{
    if(!this->List_UInt64Private->L)
    {
        //throw new NullArgumentException("List is null-defined");
        return;
    }
    else
    {
        List_UInt64Private *aux = this->List_UInt64Private->L;
        do
        {
            printf("%lu\n", aux->value->Get());
            aux = aux->next;
        } while(aux != NULL);
    }
    return;
}

void List_UInt64_Clear(List_UInt64 * const this)
{
    if(!this->List_UInt64Private->L)
        return;
    while(this->List_UInt64Private->L != NULL)
        List_UInt64_Delete(0, this);
    return;
}

int List_UInt64_Count(List_UInt64 * const this)
{
    int i = 1;
    List_UInt64Private *aux = this->List_UInt64Private->L;

    if(!aux)
    {
        return 0;
    }
    do
    {
        aux = aux->next;
        i++;
    } while(aux != NULL);
    return (i - 1);
}

int List_UInt64_BinarySearch(UInt64 *arg, List_UInt64 * const this)
{
    int __l = 0;
    int __r = this->Count() - 1;
    int __m = __l + (__r - __l) / 2;

    while(__l <= __r)
    {
        if(this->List_UInt64Private->List[__m]->Get() == arg->Get())
        {
            return __m;
        }
        if(this->List_UInt64Private->List[__m]->Get() < arg->Get())
            __l = __m + 1;
        else
            __r = __m - 1;
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

char *List_UInt64_GetType(List_UInt64 * const this)
{
    return "List(UInt64)";
}

UInt64 **List_UInt64_ToArray(List_UInt64 * const this)
{
    UInt64 **__arr = GC_MALLOC(sizeof(List_UInt64 *) * this->Count());
    List_UInt64Private *aux = this->List_UInt64Private->L;

    for(int i=0; i<this->Count(); i++)
    {
        __arr[i] = aux->value;
        aux = aux->next;
    }
    return __arr;
}

/* String */
inline const void *List_String_AsReadOnly(List_String * const this)
{   
    return ReadOnlyCollection(String, this);
}

void List_String_Append(String *arg, List_String * const this)
{
    int i;
    String **__resize;

    bool (*genericAddString)(String *, List_StringPrivate **) = delegate(bool, (String *arg, List_StringPrivate **this) 
    {  
        List_StringPrivate *aux = GC_MALLOC(sizeof(List_StringPrivate));
        List_StringPrivate *tail = (*this);

        aux->value = arg;
        aux->next = NULL;
        if (!(*this))
        {
            aux->prev = NULL;
            (*this) = aux;
            aux = (*this);
            return true;
        }
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = aux;
        aux->prev = tail;
        return true;
    } );
    //if(genericAddString(arg, &this->List_StringPrivate))
    if(genericAddString(arg, &this->List_StringPrivate->L))
    {
        i = this->Count(); 
        if((i > 0) && (i % 1024 == 0))
        {
            __resize = GC_REALLOC(this->List_StringPrivate->List, (getMultiplier(i) * 1024) * sizeof(String *));
            if(!__resize)
            {
                // throw new MemoryAccessException("Realloc did not find an available memory block");
                abort();
            }
            else
            {
                this->List_StringPrivate->List = __resize;
                this->List_StringPrivate->List[i - 1] = arg;
            }
        }
        this->List_StringPrivate->List[i - 1] = arg;
    }
    else
    {
        //throw new Exception("Failed attempt to append new element to a List");
        abort();
    }
    return;
}

void List_String_Delete(int index, List_String * const this)
{
    bool (*genericDeleteString)(int, List_StringPrivate **) = delegate(bool, (int index, List_StringPrivate **this) 
    {
        List_StringPrivate *aux = (*this);
        List_StringPrivate *aux_r;

        if(!(*this))
            return false;
        if(index == 0)
        {
            if(!(*this)->prev)
                (*this) = aux->next;
        }
        for(int i=0; aux != NULL && i<index; i++)
            aux = aux->next;
        aux_r = aux;
        if(aux->next != NULL)
            aux_r->next->prev = aux_r->prev;
        if(aux->prev != NULL)
            aux_r->prev->next = aux_r->next;
        GC_FREE(aux);
        return true;
    } );
    if(genericDeleteString(index, &this->List_StringPrivate->L) == true)
    {
        if(index == 0 && (this->Count() == false))
        {
            this->List_StringPrivate->List[index] = NULL;
        }
        else if(index == 0 && (this->Count() != false))
        {
            for(int i=0; i<this->Count(); i++)
                this->List_StringPrivate->List[i] = this->List_StringPrivate->List[i + 1];
        }
        else if(index != 0 && (index < this->Count()))
        {
            for(int i=index; i<this->Count(); i++)
            {
                this->List_StringPrivate->List[i] = this->List_StringPrivate->List[i + 1];
            }
        }
        else if(index > (this->Count()))
        {
            // throw new DataNotFoundException();
            abort();
        }
    }
    else
    {
        // throw new DataNotFoundException();
        abort();
    }
    return;
}

void List_String_Reverse(List_String * const this)
{
    void (*genericReverseString)(List_StringPrivate **) = delegate(void, (List_StringPrivate **this)
    {
        List_StringPrivate *__t = NULL;
        List_StringPrivate *__c = (*this);

        if(!(*this))
        {
            // throw new NullArgumentException();
            return;
        }
        while(__c != NULL)
        {
            __t = __c->prev;
            __c->prev = __c->next;
            __c->next = __t;
            __c = __c->prev;
        }
        if(__t != NULL)
            (*this) = __t->prev;
    } );
    return genericReverseString(&this->List_StringPrivate->L);
}

void List_String_Show(List_String * const this)
{
    if(!this->List_StringPrivate->L)
    {
        //throw new NullArgumentException("List is null-defined");
        return;
    }
    else
    {
        List_StringPrivate *aux = this->List_StringPrivate->L;
        do
        {
            printf("%s\n", aux->value->Get());
            aux = aux->next;
        } while(aux != NULL);
    }
    return;
}

void List_String_Clear(List_String * const this)
{
    if(!this->List_StringPrivate->L)
        return;
    while(this->List_StringPrivate->L != NULL)
        List_String_Delete(0, this);
    return;
}

int List_String_Count(List_String * const this)
{
    int i = 1;
    List_StringPrivate *aux = this->List_StringPrivate->L;

    if(!aux)
    {
        return 0;
    }
    do
    {
        aux = aux->next;
        i++;
    } while(aux != NULL);
    return (i - 1);
}

int List_String_BinarySearch(String *arg, List_String * const this)
{
    int __l = 0;
    int __r = this->Count() - 1;
    int __m = __l + (__r - __l) / 2;

    while(__l <= __r)
    {
        if(this->List_StringPrivate->List[__m]->Get() == arg->Get())
        {
            return __m;
        }
        if(this->List_StringPrivate->List[__m]->Get() < arg->Get())
            __l = __m + 1;
        else
            __r = __m - 1;
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

char *List_String_GetType(List_String * const this)
{
    return "List(String)";
}

String **List_String_ToArray(List_String * const this)
{
    String **__arr = GC_MALLOC(sizeof(List_String *) * this->Count());
    List_StringPrivate *aux = this->List_StringPrivate->L;

    for(int i=0; i<this->Count(); i++)
    {
        __arr[i] = aux->value;
        aux = aux->next;
    }
    return __arr;
}

/* Const Int16 */
char *ReadOnlyList_Int16_GetType(ReadOnlyList_Int16 * const this)
{
    return "ReadOnlyList(Int16)";
}

int ReadOnlyList_Int16_IndexOf(Int16 *__f, ReadOnlyList_Int16 * const this)
{
    int __l = 0;
    volatile int __r = this->Count() - 1;
    int __m;

    while(__l <= __r)
    {
        __m = __l + (__r - __l) / 2;
        if(this->List_Int16Private->List[__m]->Get() == __f->Get())
        {
            return __m;
        }
        else if(this->List_Int16Private->List[__m]->Get() < __f->Get())
        {
            __l = __m + 1;
        }
        else
        {
            __r = __m - 1;
        }
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

int ReadOnlyList_Int16_Count(ReadOnlyList_Int16 * const this)
{
    int i = 1;
    List_Int16Private *aux = this->List_Int16Private->L;

    if(!aux)
    {
        return 0;
    }
    else
    {
        do
        {
            aux = aux->next;
        } while(aux != NULL);
        return (i - 1);
    }
}

bool ReadOnlyList_Int16_Contains(Int16 *arg, ReadOnlyList_Int16 * const this)
{
    Int16 **aux = this->List_Int16Private->List;

    for(int i=0; i<this->Count(); i++)
    {
        if(aux[i]->Get() == arg->Get())
            return true;
    }
    return false;
}

bool ReadOnlyList_Int16_Equals(void *__cmp, ReadOnlyList_Int16 * const this)
{
    return (__cmp == ((void *)this) ? true : false);
}

void ReadOnlyList_Int16_CopyTo(Int16 **__arr, int index, ReadOnlyList_Int16 * const this)
{   
    for(int i=0; i<this->Count(); i++)
    {
        if(i >= index)
            __arr[i] = (Int16 *)this->List_Int16Private->List[i];
        else
        {
            __arr[i] = (Int16 *)this->List_Int16Private->List[i];
            __arr[i]->Int16(0); /* Experimental */
        }
    }
    return;
}

/* Const Int32 */
char *ReadOnlyList_Int32_GetType(ReadOnlyList_Int32 * const this)
{
    return "ReadOnlyList(Int32)";
}

int ReadOnlyList_Int32_IndexOf(Int32 *__f, ReadOnlyList_Int32 * const this)
{
    int __l = 0;
    volatile int __r = this->Count() - 1;
    int __m;

    while(__l <= __r)
    {
        __m = __l + (__r - __l) / 2;
        if(this->List_Int32Private->List[__m]->Get() == __f->Get())
        {
            return __m;
        }
        else if(this->List_Int32Private->List[__m]->Get() < __f->Get())
        {
            __l = __m + 1;
        }
        else
        {
            __r = __m - 1;
        }
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

int ReadOnlyList_Int32_Count(ReadOnlyList_Int32 * const this)
{
    int i = 1;
    List_Int32Private *aux = this->List_Int32Private->L;

    if(!aux)
    {
        return 0;
    }
    else
    {
        do
        {
            aux = aux->next;
        } while(aux != NULL);
        return (i - 1);
    }
}

bool ReadOnlyList_Int32_Contains(Int32 *arg, ReadOnlyList_Int32 * const this)
{
    Int32 **aux = this->List_Int32Private->List;

    for(int i=0; i<this->Count(); i++)
    {
        if(aux[i]->Get() == arg->Get())
            return true;
    }
    return false;
}

bool ReadOnlyList_Int32_Equals(void *__cmp, ReadOnlyList_Int32 * const this)
{
    return (__cmp == ((void *)this) ? true : false);
}

void ReadOnlyList_Int32_CopyTo(Int32 **__arr, int index, ReadOnlyList_Int32 * const this)
{   
    for(int i=0; i<this->Count(); i++)
    {
        if(i >= index)
            __arr[i] = (Int32 *)this->List_Int32Private->List[i];
        else
        {
            __arr[i] = (Int32 *)this->List_Int32Private->List[i];
            __arr[i]->Int32(0); /* Experimental */
        }
    }
    return;
}

/* Const Int64 */
char *ReadOnlyList_Int64_GetType(ReadOnlyList_Int64 * const this)
{
    return "ReadOnlyList(Int64)";
}

int ReadOnlyList_Int64_IndexOf(Int64 *__f, ReadOnlyList_Int64 * const this)
{
    int __l = 0;
    volatile int __r = this->Count() - 1;
    int __m;

    while(__l <= __r)
    {
        __m = __l + (__r - __l) / 2;
        if(this->List_Int64Private->List[__m]->Get() == __f->Get())
        {
            return __m;
        }
        else if(this->List_Int64Private->List[__m]->Get() < __f->Get())
        {
            __l = __m + 1;
        }
        else
        {
            __r = __m - 1;
        }
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

int ReadOnlyList_Int64_Count(ReadOnlyList_Int64 * const this)
{
    int i = 1;
    List_Int64Private *aux = this->List_Int64Private->L;

    if(!aux)
    {
        return 0;
    }
    else
    {
        do
        {
            aux = aux->next;
        } while(aux != NULL);
        return (i - 1);
    }
}

bool ReadOnlyList_Int64_Contains(Int64 *arg, ReadOnlyList_Int64 * const this)
{
    Int64 **aux = this->List_Int64Private->List;

    for(int i=0; i<this->Count(); i++)
    {
        if(aux[i]->Get() == arg->Get())
            return true;
    }
    return false;
}

bool ReadOnlyList_Int64_Equals(void *__cmp, ReadOnlyList_Int64 * const this)
{
    return (__cmp == ((void *)this) ? true : false);
}

void ReadOnlyList_Int64_CopyTo(Int64 **__arr, int index, ReadOnlyList_Int64 * const this)
{   
    for(int i=0; i<this->Count(); i++)
    {
        if(i >= index)
            __arr[i] = (Int64 *)this->List_Int64Private->List[i];
        else
        {
            __arr[i] = (Int64 *)this->List_Int64Private->List[i];
            __arr[i]->Int64(0); /* Experimental */
        }
    }
    return;
}

/* Const UInt16 */
char *ReadOnlyList_UInt16_GetType(ReadOnlyList_UInt16 * const this)
{
    return "ReadOnlyList(UInt16)";
}

int ReadOnlyList_UInt16_IndexOf(UInt16 *__f, ReadOnlyList_UInt16 * const this)
{
    int __l = 0;
    volatile int __r = this->Count() - 1;
    int __m;

    while(__l <= __r)
    {
        __m = __l + (__r - __l) / 2;
        if(this->List_UInt16Private->List[__m]->Get() == __f->Get())
        {
            return __m;
        }
        else if(this->List_UInt16Private->List[__m]->Get() < __f->Get())
        {
            __l = __m + 1;
        }
        else
        {
            __r = __m - 1;
        }
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

int ReadOnlyList_UInt16_Count(ReadOnlyList_UInt16 * const this)
{
    int i = 1;
    List_UInt16Private *aux = this->List_UInt16Private->L;

    if(!aux)
    {
        return 0;
    }
    else
    {
        do
        {
            aux = aux->next;
        } while(aux != NULL);
        return (i - 1);
    }
}

bool ReadOnlyList_UInt16_Contains(UInt16 *arg, ReadOnlyList_UInt16 * const this)
{
    UInt16 **aux = this->List_UInt16Private->List;

    for(int i=0; i<this->Count(); i++)
    {
        if(aux[i]->Get() == arg->Get())
            return true;
    }
    return false;
}

bool ReadOnlyList_UInt16_Equals(void *__cmp, ReadOnlyList_UInt16 * const this)
{
    return (__cmp == ((void *)this) ? true : false);
}

void ReadOnlyList_UInt16_CopyTo(UInt16 **__arr, int index, ReadOnlyList_UInt16 * const this)
{   
    for(int i=0; i<this->Count(); i++)
    {
        if(i >= index)
            __arr[i] = (UInt16 *)this->List_UInt16Private->List[i];
        else
        {
            __arr[i] = (UInt16 *)this->List_UInt16Private->List[i];
            __arr[i]->UInt16(0); /* Experimental */
        }
    }
    return;
}

/* Const UInt32 */
char *ReadOnlyList_UInt32_GetType(ReadOnlyList_UInt32 * const this)
{
    return "ReadOnlyList(UInt32)";
}

int ReadOnlyList_UInt32_IndexOf(UInt32 *__f, ReadOnlyList_UInt32 * const this)
{
    int __l = 0;
    volatile int __r = this->Count() - 1;
    int __m;

    while(__l <= __r)
    {
        __m = __l + (__r - __l) / 2;
        if(this->List_UInt32Private->List[__m]->Get() == __f->Get())
        {
            return __m;
        }
        else if(this->List_UInt32Private->List[__m]->Get() < __f->Get())
        {
            __l = __m + 1;
        }
        else
        {
            __r = __m - 1;
        }
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

int ReadOnlyList_UInt32_Count(ReadOnlyList_UInt32 * const this)
{
    int i = 1;
    List_UInt32Private *aux = this->List_UInt32Private->L;

    if(!aux)
    {
        return 0;
    }
    else
    {
        do
        {
            aux = aux->next;
        } while(aux != NULL);
        return (i - 1);
    }
}

bool ReadOnlyList_UInt32_Contains(UInt32 *arg, ReadOnlyList_UInt32 * const this)
{
    UInt32 **aux = this->List_UInt32Private->List;

    for(int i=0; i<this->Count(); i++)
    {
        if(aux[i]->Get() == arg->Get())
            return true;
    }
    return false;
}

bool ReadOnlyList_UInt32_Equals(void *__cmp, ReadOnlyList_UInt32 * const this)
{
    return (__cmp == ((void *)this) ? true : false);
}

void ReadOnlyList_UInt32_CopyTo(UInt32 **__arr, int index, ReadOnlyList_UInt32 * const this)
{   
    for(int i=0; i<this->Count(); i++)
    {
        if(i >= index)
            __arr[i] = (UInt32 *)this->List_UInt32Private->List[i];
        else
        {
            __arr[i] = (UInt32 *)this->List_UInt32Private->List[i];
            __arr[i]->UInt32(0); /* Experimental */
        }
    }
    return;
}

/* Const UInt64 */
char *ReadOnlyList_UInt64_GetType(ReadOnlyList_UInt64 * const this)
{
    return "ReadOnlyList(UInt64)";
}

int ReadOnlyList_UInt64_IndexOf(UInt64 *__f, ReadOnlyList_UInt64 * const this)
{
    int __l = 0;
    volatile int __r = this->Count() - 1;
    int __m;

    while(__l <= __r)
    {
        __m = __l + (__r - __l) / 2;
        if(this->List_UInt64Private->List[__m]->Get() == __f->Get())
        {
            return __m;
        }
        else if(this->List_UInt64Private->List[__m]->Get() < __f->Get())
        {
            __l = __m + 1;
        }
        else
        {
            __r = __m - 1;
        }
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

int ReadOnlyList_UInt64_Count(ReadOnlyList_UInt64 * const this)
{
    int i = 1;
    List_UInt64Private *aux = this->List_UInt64Private->L;

    if(!aux)
    {
        return 0;
    }
    else
    {
        do
        {
            aux = aux->next;
        } while(aux != NULL);
        return (i - 1);
    }
}

bool ReadOnlyList_UInt64_Contains(UInt64 *arg, ReadOnlyList_UInt64 * const this)
{
    UInt64 **aux = this->List_UInt64Private->List;

    for(int i=0; i<this->Count(); i++)
    {
        if(aux[i]->Get() == arg->Get())
            return true;
    }
    return false;
}

bool ReadOnlyList_UInt64_Equals(void *__cmp, ReadOnlyList_UInt64 * const this)
{
    return (__cmp == ((void *)this) ? true : false);
}

void ReadOnlyList_UInt64_CopyTo(UInt64 **__arr, int index, ReadOnlyList_UInt64 * const this)
{   
    for(int i=0; i<this->Count(); i++)
    {
        if(i >= index)
            __arr[i] = (UInt64 *)this->List_UInt64Private->List[i];
        else
        {
            __arr[i] = (UInt64 *)this->List_UInt64Private->List[i];
            __arr[i]->UInt64(0); /* Experimental */
        }
    }
    return;
}

/* Const String */
char *ReadOnlyList_String_GetType(ReadOnlyList_String * const this)
{
    return "ReadOnlyList(String)";
}

int ReadOnlyList_String_IndexOf(String *__f, ReadOnlyList_String * const this)
{
    int __l = 0;
    volatile int __r = this->Count() - 1;
    int __m;

    while(__l <= __r)
    {
        __m = __l + (__r - __l) / 2;
        if(this->List_StringPrivate->List[__m]->Get() == __f->Get())
        {
            return __m;
        }
        else if(this->List_StringPrivate->List[__m]->Get() < __f->Get())
        {
            __l = __m + 1;
        }
        else
        {
            __r = __m - 1;
        }
    }
    if(__l > __r)
    {
        // throw new DataNotFoundException();
        abort();
    }
    return -1;
}

int ReadOnlyList_String_Count(ReadOnlyList_String * const this)
{
    int i = 1;
    List_StringPrivate *aux = this->List_StringPrivate->L;

    if(!aux)
    {
        return 0;
    }
    else
    {
        do
        {
            aux = aux->next;
        } while(aux != NULL);
        return (i - 1);
    }
}

bool ReadOnlyList_String_Contains(String *arg, ReadOnlyList_String * const this)
{
    String **aux = this->List_StringPrivate->List;

    for(int i=0; i<this->Count(); i++)
    {
        if(!strcmp(aux[i]->Get(), arg->Get())) 
            return true;
    }
    return false;
}

bool ReadOnlyList_String_Equals(void *__cmp, ReadOnlyList_String * const this)
{
    return (__cmp == ((void *)this) ? true : false);
}

void ReadOnlyList_String_CopyTo(String **__arr, int index, ReadOnlyList_String * const this)
{   
    for(int i=0; i<this->Count(); i++)
    {
        if(i >= index)
            __arr[i] = (String *)this->List_StringPrivate->List[i];
        else
        {
            __arr[i] = (String *)this->List_StringPrivate->List[i];
            __arr[i]->String(""); /* Experimental */
        }
    }
    return;
}

/* Supportive */
static int getMultiplier(int i)
{
    int multiplier = 1;

    if(i == 1024)
        return multiplier;
    else
    {
        while(i > 0)
        {
            i /= 1024;
            multiplier++;
        }
    }
    return multiplier;
}

void *ctorCheckArgs(const char *T, int __c, ...)
{
    void **aux;
    void *aux_l;
    void *__copy;
    void *__r;
    va_list ap;
    int i = 0;

    if(__c != 1)
    {
        // throw new ArgumentException("The number of arguments passed to the constructor are wrong");
        abort();
    }
    va_start(ap, __c);
    if(!strcmp(T, "Int16"))
    {
        aux = (void **)va_arg(ap, Int16 **);
        if(!aux)
        {
            va_end(ap);
            return new Generic(List(Int16));
        }
        else
        {
            __r = new Generic(List(Int16));
            do
            {
                ((List_Int16 *)__r)->Append(aux[i]);
            } while(aux[i] != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "Int32"))
    {
        aux = (void **)va_arg(ap, Int32 **);
        if(!aux)
        {
            va_end(ap);
            return new Generic(List(Int32));
        }
        else
        {
            __r = new Generic(List(Int32));
            do
            {
                ((List_Int32 *)__r)->Append(aux[i]);
            } while(aux[i] != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "Int64"))
    {
        aux = (void **)va_arg(ap, Int64 **);
        if(!aux)
        {
            va_end(ap);
            return new Generic(List(Int64));
        }
        else
        {
            __r = new Generic(List(Int64));
            do
            {
                ((List_Int64 *)__r)->Append(aux[i]);
            } while(aux[i] != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "UInt16"))
    {
        aux = (void **)va_arg(ap, UInt16 **);
        if(!aux)
        {
            va_end(ap);
            return new Generic(List(UInt16));
        }
        else
        {
            __r = new Generic(List(UInt16));
            do
            {
                ((List_UInt16 *)__r)->Append(aux[i]);
            } while(aux[i] != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "UInt32"))
    {
        aux = (void **)va_arg(ap, UInt32 **);
        if(!aux)
        {
            va_end(ap);
            return new Generic(List(UInt32));
        }
        else
        {
            __r = new Generic(List(UInt32));
            do
            {
                ((List_UInt32 *)__r)->Append(aux[i]);
            } while(aux[i] != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "UInt64"))
    {
        aux = (void **)va_arg(ap, UInt64 **);
        if(!aux)
        {
            va_end(ap);
            return new Generic(List(UInt64));
        }
        else
        {
            __r = new Generic(List(UInt64));
            do
            {
                ((List_UInt64 *)__r)->Append(aux[i]);
            } while(aux[i] != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "String"))
    {
        aux = (void **)va_arg(ap, String **);
        if(!aux)
        {
            va_end(ap);
            return new Generic(List(String));
        }
        else
        {
            __r = new Generic(List(String));
            do
            {
                ((List_String *)__r)->Append(aux[i]);
            } while(aux[i] != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "List(Int16)"))
    {
        aux_l = va_arg(ap, List_Int16 *);
        __r = new Generic(List(Int16));
        if(!((List_Int16 *)aux_l)->List_Int16Private->L)
        {
            return __r;
        }
        else 
        {
            __copy = aux_l;
            do
            {
                ((List_Int16 *)__r)->Append(((List_Int16 *)__copy)->List_Int16Private->L->value);
                __copy = ((List_Int16 *)__copy)->List_Int16Private->L->next;
            } while(__copy != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "List(Int32)"))
    {
        aux_l = va_arg(ap, List_Int32 *);
        __r = new Generic(List(Int32));
        if(!((List_Int32 *)aux_l)->List_Int32Private->L)
        {
            return __r;
        }
        else 
        {
            __copy = aux_l;
            do
            {
                ((List_Int32 *)__r)->Append(((List_Int32 *)__copy)->List_Int32Private->L->value);
                __copy = ((List_Int32 *)__copy)->List_Int32Private->L->next;
            } while(__copy != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "List(Int64)"))
    {
        aux_l = va_arg(ap, List_Int64 *);
        __r = new Generic(List(Int64));
        if(!((List_Int64 *)aux_l)->List_Int64Private->L)
        {
            return __r;
        }
        else 
        {
            __copy = aux_l;
            do
            {
                ((List_Int64 *)__r)->Append(((List_Int64 *)__copy)->List_Int64Private->L->value);
                __copy = ((List_Int64 *)__copy)->List_Int64Private->L->next;
            } while(__copy != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "List(UInt16)"))
    {
        aux_l = va_arg(ap, List_UInt16 *);
        __r = new Generic(List(UInt16));
        if(!((List_UInt16 *)aux_l)->List_UInt16Private->L)
        {
            return __r;
        }
        else 
        {
            __copy = aux_l;
            do
            {
                ((List_UInt16 *)__r)->Append(((List_UInt16 *)__copy)->List_UInt16Private->L->value);
                __copy = ((List_UInt16 *)__copy)->List_UInt16Private->L->next;
            } while(__copy != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "List(UInt32)"))
    {
        aux_l = va_arg(ap, List_UInt32 *);
        __r = new Generic(List(UInt32));
        if(!((List_UInt32 *)aux_l)->List_UInt32Private->L)
        {
            return __r;
        }
        else 
        {
            __copy = aux_l;
            do
            {
                ((List_UInt32 *)__r)->Append(((List_UInt32 *)__copy)->List_UInt32Private->L->value);
                __copy = ((List_UInt32 *)__copy)->List_UInt32Private->L->next;
            } while(__copy != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "List(UInt64)"))
    {
        aux_l = va_arg(ap, List_UInt64 *);
        __r = new Generic(List(UInt64));
        if(!((List_UInt64 *)aux_l)->List_UInt64Private->L)
        {
            return __r;
        }
        else 
        {
            __copy = aux_l;
            do
            {
                ((List_UInt64 *)__r)->Append(((List_UInt64 *)__copy)->List_UInt64Private->L->value);
                __copy = ((List_UInt64 *)__copy)->List_UInt64Private->L->next;
            } while(__copy != NULL);
        }
        va_end(ap);
        return __r;
    }
    else if(!strcmp(T, "List(String)"))
    {
        aux_l = va_arg(ap, List_String *);
        __r = new Generic(List(String));
        if(!((List_String *)aux_l)->List_StringPrivate->L)
        {
            return __r;
        }
        else 
        {
            __copy = aux_l;
            do
            {
                ((List_String *)__r)->Append(((List_String *)__copy)->List_StringPrivate->L->value);
                __copy = ((List_String *)__copy)->List_StringPrivate->L->next;
            } while(__copy != NULL);
        }
        va_end(ap);
        return __r;
    }
    else 
    {
        va_end(ap);
        // throw new ArgumentException("Array or a Generic Collection was expected");
        abort();
    }
    return 0;
}
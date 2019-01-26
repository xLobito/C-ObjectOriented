#include "ObjectPrueba.h"

#ifndef LIST_H
#define LIST_H

#define list(T) \
    typedef struct List_##T##Private List_##T##Private; \
    \
    typedef struct lista_##T \
    { \
        Object object; \
        private(List_##T); \
        const struct readonlylist_##T *(*AsReadOnly)(void); \
        bool (*Append)(T *); \
        bool (*Delete)(const int); \
        void (*Reverse)(void); \
        void (*Show)(void); \
        void (*Clear)(void); \
        int (*Count)(void); \
        int (*BinarySearch)(T *); \
        char *(*GetType)(void); \
        T **(*ToArray)(void); \
    } List_##T; \

#define readonlylist(T) \
    typedef struct ReadOnlyList_##T##Private ReadOnlyList_##T##Private; \
    \
    typedef struct readonlylist_##T \
    { \
        Object object; \
        private(List_##T); \
        char *(*GetType)(void); \
        int (*IndexOf)(T *); \
        int (*Count)(void); \
        bool(*Contains)(T *); \
        bool (*Equals)(void *); \
        void (*CopyTo)(T **, int); \
    } ReadOnlyList_##T; \
    \
    typedef struct StaticList_##T##Private StaticList_##T##Private; \
    \
    typedef struct staticlist_##T \
    { \
        Object object; \
        private(List_##T); \
        char *(*GetType)(void); \
        int (*IndexOf)(T *); \
        int (*Count)(void); \
        bool (*Contains)(T *); \
        bool (*Equals)(void *); \
        void (*CopyTo)(T **, int); \
    } StaticList_##T; 

#define List(T) List_##T
#define ReadOnlyList(T) const ReadOnlyList_##T
/* Encapsulate */
#define Generic(T, args...) \
    ({ \
        PP_NARG(args) == 0 ? ctorList(N, T) : ctorCheckArgs(#T, PP_NARG(args), ##args); \
    })
#define ReadOnlyCollection(T, L) ctorReadOnly(N, ReadOnlyList_, T, L)
#define ctorList(N, T) N ## T()
#define ctorReadOnly(N, S, T, L) N ## S ## T(L)

/**
 * Static predefinition.
 * 
 * Shall be avoided and used only if a specific List type is defined.
 */
list(Int16);
list(Int32);
list(Int64);
list(UInt16);
list(UInt32);
list(UInt64);
list(String);
readonlylist(Int16);
readonlylist(Int32);
readonlylist(Int64);
readonlylist(UInt16);
readonlylist(UInt32);
readonlylist(UInt64);
readonlylist(String);

/* Constructors */
extern void *NList_Int16(void);
extern void *NList_Int32(void);
extern void *NList_Int64(void);
extern void *NList_UInt16(void);
extern void *NList_UInt32(void);
extern void *NList_UInt64(void);
extern void *NList_String(void);
extern const void *NReadOnlyList_Int16(List_Int16 *); 
extern const void *NReadOnlyList_Int32(List_Int32 *);
extern const void *NReadOnlyList_Int64(List_Int64 *);
extern const void *NReadOnlyList_UInt16(List_UInt16 *);
extern const void *NReadOnlyList_UInt32(List_UInt32 *);
extern const void *NReadOnlyList_UInt64(List_UInt64 *);
extern const void *NReadOnlyList_String(List_String *);
/* Int16 */
extern const void *List_Int16_AsReadOnly(List_Int16 * const);
extern void List_Int16_Append(Int16 *, List_Int16 * const); 
extern void List_Int16_Delete(int, List_Int16 * const); 
extern void List_Int16_Reverse(List_Int16 * const);
extern void List_Int16_Show(List_Int16 * const); 
extern void List_Int16_Clear(List_Int16 * const);
extern int List_Int16_Count(List_Int16 * const);
extern int List_Int16_BinarySearch(Int16 *, List_Int16 * const);
extern char *List_Int16_GetType(List_Int16 * const);
extern Int16 **List_Int16_ToArray(List_Int16 * const);
/* Int32 */
extern const void *List_Int32_AsReadOnly(List_Int32 * const);
extern void List_Int32_Append(Int32 *, List_Int32 * const); 
extern void List_Int32_Delete(int, List_Int32 * const);
extern void List_Int32_Reverse(List_Int32 * const); 
extern void List_Int32_Show(List_Int32 * const); 
extern void List_Int32_Clear(List_Int32 * const);
extern int List_Int32_Count(List_Int32 * const);
extern int List_Int32_BinarySearch(Int32 *, List_Int32 * const);
extern char *List_Int32_GetType(List_Int32 * const);
extern Int32 **List_Int32_ToArray(List_Int32 * const);
/* Int64 */
extern const void *List_Int64_AsReadOnly(List_Int64 * const);
extern void List_Int64_Append(Int64 *, List_Int64 * const); 
extern void List_Int64_Delete(int, List_Int64 * const); 
extern void List_Int64_Reverse(List_Int64 * const);
extern void List_Int64_Show(List_Int64 * const);  
extern void List_Int64_Clear(List_Int64 * const);
extern int List_Int64_Count(List_Int64 * const);
extern int List_Int64_BinarySearch(Int64 *, List_Int64 * const);
extern char *List_Int64_GetType(List_Int64 * const);
extern Int64 **List_Int64_ToArray(List_Int64 * const);
/* UInt16 */
extern const void *List_UInt16_AsReadOnly(List_UInt16 * const);
extern void List_UInt16_Append(UInt16 *, List_UInt16 * const); 
extern void List_UInt16_Delete(int, List_UInt16 * const); 
extern void List_UInt16_Reverse(List_UInt16 * const);
extern void List_UInt16_Show(List_UInt16 * const); 
extern void List_UInt16_Clear(List_UInt16 * const);
extern int List_UInt16_Count(List_UInt16 * const);
extern int List_UInt16_BinarySearch(UInt16 *, List_UInt16 * const);
extern char *List_UInt16_GetType(List_UInt16 * const);
extern UInt16 **List_UInt16_ToArray(List_UInt16 * const);
/* UInt32 */
extern const void *List_UInt32_AsReadOnly(List_UInt32 * const);
extern void List_UInt32_Append(UInt32 *, List_UInt32 * const); 
extern void List_UInt32_Delete(int, List_UInt32 * const); 
extern void List_UInt32_Reverse(List_UInt32 * const);
extern void List_UInt32_Show(List_UInt32 * const); 
extern void List_UInt32_Clear(List_UInt32 * const);
extern int List_UInt32_Count(List_UInt32 * const);
extern int List_UInt32_BinarySearch(UInt32 *, List_UInt32 * const);
extern char *List_UInt32_GetType(List_UInt32 * const);
extern UInt32 **List_UInt32_ToArray(List_UInt32 * const);
/* UInt64 */
extern const void *List_UInt64_AsReadOnly(List_UInt64 * const);
extern void List_UInt64_Append(UInt64 *, List_UInt64 * const); 
extern void List_UInt64_Delete(int, List_UInt64 * const); 
extern void List_UInt64_Reverse(List_UInt64 * const);
extern void List_UInt64_Show(List_UInt64 * const); 
extern void List_UInt64_Clear(List_UInt64 * const);
extern int List_UInt64_Count(List_UInt64 * const);
extern int List_UInt64_BinarySearch(UInt64 *, List_UInt64 * const);
extern char *List_UInt64_GetType(List_UInt64 * const);
extern UInt64 **List_UInt64_ToArray(List_UInt64 * const);
/* String */
extern const void *List_String_AsReadOnly(List_String * const);
extern void List_String_Append(String *, List_String * const); 
extern void List_String_Delete(int, List_String * const); 
extern void List_String_Reverse(List_String * const);
extern void List_String_Show(List_String * const); 
extern void List_String_Clear(List_String * const);
extern int List_String_Count(List_String * const);
extern int List_String_BinarySearch(String *, List_String * const);
extern char *List_String_GetType(List_String * const);
extern String **List_String_ToArray(List_String * const);
/* Const Int16 */
extern char *ReadOnlyList_Int16_GetType(ReadOnlyList_Int16 * const);
extern int ReadOnlyList_Int16_IndexOf(Int16 *, ReadOnlyList_Int16 * const);
extern int ReadOnlyList_Int16_Count(ReadOnlyList_Int16 * const);
extern bool ReadOnlyList_Int16_Contains(Int16 *, ReadOnlyList_Int16 * const);
extern bool ReadOnlyList_Int16_Equals(void *, ReadOnlyList_Int16 * const);
extern void ReadOnlyList_Int16_CopyTo(Int16 **, int, ReadOnlyList_Int16 * const); 
/* Const Int32 */
extern char *ReadOnlyList_Int32_GetType(ReadOnlyList_Int32 * const);
extern int ReadOnlyList_Int32_IndexOf(Int32 *, ReadOnlyList_Int32 * const);
extern int ReadOnlyList_Int32_Count(ReadOnlyList_Int32 * const);
extern bool ReadOnlyList_Int32_Contains(Int32 *, ReadOnlyList_Int32 * const);
extern bool ReadOnlyList_Int32_Equals(void *, ReadOnlyList_Int32 * const);
extern void ReadOnlyList_Int32_CopyTo(Int32 **, int, ReadOnlyList_Int32 * const); 
/* Const Int64 */
extern char *ReadOnlyList_Int64_GetType(ReadOnlyList_Int64 * const);
extern int ReadOnlyList_Int64_IndexOf(Int64 *, ReadOnlyList_Int64 * const);
extern int ReadOnlyList_Int64_Count(ReadOnlyList_Int64 * const);
extern bool ReadOnlyList_Int64_Contains(Int64 *, ReadOnlyList_Int64 * const);
extern bool ReadOnlyList_Int64_Equals(void *, ReadOnlyList_Int64 * const);
extern void ReadOnlyList_Int64_CopyTo(Int64 **, int, ReadOnlyList_Int64 * const); 
/* Const UInt16 */
extern char *ReadOnlyList_UInt16_GetType(ReadOnlyList_UInt16 * const);
extern int ReadOnlyList_UInt16_IndexOf(UInt16 *, ReadOnlyList_UInt16 * const);
extern int ReadOnlyList_UInt16_Count(ReadOnlyList_UInt16 * const);
extern bool ReadOnlyList_UInt16_Contains(UInt16 *, ReadOnlyList_UInt16 * const);
extern bool ReadOnlyList_UInt16_Equals(void *, ReadOnlyList_UInt16 * const);
extern void ReadOnlyList_UInt16_CopyTo(UInt16 **, int, ReadOnlyList_UInt16 * const); 
/* Const UInt32 */
extern char *ReadOnlyList_UInt32_GetType(ReadOnlyList_UInt32 * const);
extern int ReadOnlyList_UInt32_IndexOf(UInt32 *, ReadOnlyList_UInt32 * const);
extern int ReadOnlyList_UInt32_Count(ReadOnlyList_UInt32 * const);
extern bool ReadOnlyList_UInt32_Contains(UInt32 *, ReadOnlyList_UInt32 * const);
extern bool ReadOnlyList_UInt32_Equals(void *, ReadOnlyList_UInt32 * const);
extern void ReadOnlyList_UInt32_CopyTo(UInt32 **, int, ReadOnlyList_UInt32 * const); 
/* Const UInt64 */
extern char *ReadOnlyList_UInt64_GetType(ReadOnlyList_UInt64 * const);
extern int ReadOnlyList_UInt64_IndexOf(UInt64 *, ReadOnlyList_UInt64 * const);
extern int ReadOnlyList_UInt64_Count(ReadOnlyList_UInt64 * const);
extern bool ReadOnlyList_UInt64_Contains(UInt64 *, ReadOnlyList_UInt64 * const);
extern bool ReadOnlyList_UInt64_Equals(void *, ReadOnlyList_UInt64 * const);
extern void ReadOnlyList_UInt64_CopyTo(UInt64 **, int, ReadOnlyList_UInt64 * const); 
/* Const String */
extern char *ReadOnlyList_String_GetType(ReadOnlyList_String * const);
extern int ReadOnlyList_String_IndexOf(String *, ReadOnlyList_String * const);
extern int ReadOnlyList_String_Count(ReadOnlyList_String * const);
extern bool ReadOnlyList_String_Contains(String *, ReadOnlyList_String * const);
extern bool ReadOnlyList_String_Equals(void *, ReadOnlyList_String * const);
extern void ReadOnlyList_String_CopyTo(String **, int, ReadOnlyList_String * const); 
/* Supportive */
extern void *ctorCheckArgs(const char *, int, ...);

#endif /* LIST_H */
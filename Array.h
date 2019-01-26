#include "ObjectPrueba.h"

#ifndef ARRAY_H
#define ARRAY_H

#include <limits.h>

#define array(T) \
    typedef struct Array_##T##Private Array_##T##Private; \
    \
    typedef struct array_##T \
    { \
        Object object; \
        private(Array_##T); \
        T *(*Get)(int); \
        struct array_##T *(*Empty)(void); \
        char *(*GetType)(void); \
        bool (*Equals)(void *); \
        T *(*IndexOf)(struct array_##T *, const T *); \
        void (*Resize)(Int32 *); \
        void (*Reverse)(void); \
        void (*SetValue)(T *, Int32 *); \
        String *(*ToString)(void); \
        const int (*Length)(void); \
    } Array_##T;

#define Array(T) Array_##T
#define Collection(T, S) ExpandArray(NArray_, T, S)
#define ExpandArray(N, T, S) N##T(S)

array(Int16);
array(Int32);
array(Int64);
array(UInt16);
array(UInt32);
array(UInt64);
array(String);

/* Constructors */
extern void *NArray_Int16(size_t);
extern void *NArray_Int32(size_t);
extern void *NArray_Int64(size_t);
extern void *NArray_UInt16(size_t);
extern void *NArray_UInt32(size_t);
extern void *NArray_UInt64(size_t);
extern void *NArray_String(size_t);
/* Int16 */
extern Int16 *Array_Int16_Get(int, Array_Int16 * const);
extern Array_Int16 *Array_Int16_Empty(Array_Int16 * const);
extern char *Array_Int16_GetType(Array_Int16 * const);
extern bool Array_Int16_Equals(void *, Array_Int16 * const);
extern Int16 *Array_Int16_IndexOf(const Int16 *, Array_Int16 * const);
extern void Array_Int16_Resize(Int32 *, Array_Int16 * const);
extern void Array_Int16_Reverse(Array_Int16 * const);
extern void Array_Int16_SetValue(Int16 *, Int32 *, Array_Int16 * const);
extern String *Array_Int16_ToString(Array_Int16 * const);
extern const int Array_Int16_Length(Array_Int16 * const);
/* Int32 */
extern Int32 *Array_Int32_Get(int, Array_Int32 * const);
extern Array_Int32 *Array_Int32_Empty(Array_Int32 * const);
extern char *Array_Int32_GetType(Array_Int32 * const);
extern bool Array_Int32_Equals(void *, Array_Int32 * const);
extern Int32 *Array_Int32_IndexOf(const Int32 *, Array_Int32 * const);
extern void Array_Int32_Resize(Int32 *, Array_Int32 * const);
extern void Array_Int32_Reverse(Array_Int32 * const);
extern void Array_Int32_SetValue(Int32 *, Int32 *, Array_Int32 * const);
extern String *Array_Int32_ToString(Array_Int32 * const);
extern const int Array_Int32_Length(Array_Int32 * const);
/* Int64 */
extern Int64 *Array_Int64_Get(int, Array_Int64 * const);
extern Array_Int64 *Array_Int64_Empty(Array_Int64 * const);
extern char *Array_Int64_GetType(Array_Int64 * const);
extern bool Array_Int64_Equals(void *, Array_Int64 * const);
extern Int64 *Array_Int64_IndexOf(const Int64 *, Array_Int64 * const);
extern void Array_Int64_Resize(Int32 *, Array_Int64 * const);
extern void Array_Int64_Reverse(Array_Int64 * const);
extern void Array_Int64_SetValue(Int64 *, Int32 *, Array_Int64 * const);
extern String *Array_Int64_ToString(Array_Int64 * const);
extern const int Array_Int64_Length(Array_Int64 * const);
/* UInt16 */
extern UInt16 *Array_UInt16_Get(int, Array_UInt16 * const);
extern Array_UInt16 *Array_UInt16_Empty(Array_UInt16 * const);
extern char *Array_UInt16_GetType(Array_UInt16 * const);
extern bool Array_UInt16_Equals(void *, Array_UInt16 * const);
extern UInt16 *Array_UInt16_IndexOf(const UInt16 *, Array_UInt16 * const);
extern void Array_UInt16_Resize(Int32 *, Array_UInt16 * const);
extern void Array_UInt16_Reverse(Array_UInt16 * const);
extern void Array_UInt16_SetValue(UInt16 *, Int32 *, Array_UInt16 * const);
extern String *Array_UInt16_ToString(Array_UInt16 * const);
extern const int Array_UInt16_Length(Array_UInt16 * const);
/* UInt32 */
extern UInt32 *Array_UInt32_Get(int, Array_UInt32 * const);
extern Array_UInt32 *Array_UInt32_Empty(Array_UInt32 * const);
extern char *Array_UInt32_GetType(Array_UInt32 * const);
extern bool Array_UInt32_Equals(void *, Array_UInt32 * const);
extern UInt32 *Array_UInt32_IndexOf(const UInt32 *, Array_UInt32 * const);
extern void Array_UInt32_Resize(Int32 *, Array_UInt32 * const);
extern void Array_UInt32_Reverse(Array_UInt32 * const);
extern void Array_UInt32_SetValue(UInt32 *, Int32 *, Array_UInt32 * const);
extern String *Array_UInt32_ToString(Array_UInt32 * const);
extern const int Array_UInt32_Length(Array_UInt32 * const);
/* UInt64 */
extern UInt64 *Array_UInt64_Get(int, Array_UInt64 * const);
extern Array_UInt64 *Array_UInt64_Empty(Array_UInt64 * const);
extern char *Array_UInt64_GetType(Array_UInt64 * const);
extern bool Array_UInt64_Equals(void *, Array_UInt64 * const);
extern UInt64 *Array_UInt64_IndexOf(const UInt64 *, Array_UInt64 * const);
extern void Array_UInt64_Resize(Int32 *, Array_UInt64 * const);
extern void Array_UInt64_Reverse(Array_UInt64 * const);
extern void Array_UInt64_SetValue(UInt64 *, Int32 *, Array_UInt64 * const);
extern String *Array_UInt64_ToString(Array_UInt64 * const);
extern const int Array_UInt64_Length(Array_UInt64 * const);
/* String */
extern String *Array_String_Get(int, Array_String * const);
extern Array_String *Array_String_Empty(Array_String * const);
extern char *Array_String_GetType(Array_String * const);
extern bool Array_String_Equals(void *, Array_String * const);
extern String *Array_String_IndexOf(const String *, Array_String * const);
extern void Array_String_Resize(Int32 *, Array_String * const);
extern void Array_String_Reverse(Array_String * const);
extern void Array_String_SetValue(String *, Int32 *, Array_String * const);
extern String *Array_String_ToString(Array_String * const);
extern const int Array_String_Length(Array_String * const);

#endif /* ARRAY_H */
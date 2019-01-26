#include "ObjectPrueba.h"

#ifndef CONVERSION_H
#define CONVERSION_H

#define typename(T) \
    _Generic((T), \
        float *: "float", \
        double *: "double", \
        short *: "short", \
        int *: "int", \
        long *: "long", \
        unsigned short *: "unsigned short", \
        unsigned int *: "unsigned int", \
        unsigned long *: "unsigned long", \
        char *: "char pointer", \
        Char *: "Char", \
        Float *: "Double", \
        Double *: "Double", \
        Int16 *: "Int16", \
        Int32 *: "Int32", \
        Int64 *: "Int64", \
        UInt16 *: "UInt16", \
        UInt32 *: "UInt32", \
        UInt64 *: "UInt64", \
        String *: "String" \
    )
/* Encapsulate */
#define ToCharEx(T) ToChar_Internal(T, typename(T))
#define ToFloatEx(T) ToFloat_Internal(T, typename(T))
#define ToDoubleEx(T) ToDouble_Internal(T, typename(T))
#define ToInt16Ex(T) ToInt16_Internal(T, typename(T))
#define ToInt32Ex(T) ToInt32_Internal(T, typename(T))
#define ToInt64Ex(T) ToInt64_Internal(T, typename(T))
#define ToUInt16Ex(T) ToUInt16_Internal(T, typename(T))
#define ToUInt32Ex(T) ToUInt32_Internal(T, typename(T))
#define ToUInt64Ex(T) ToUInt64_Internal(T, typename(T))
#define ToStringEx(T) ToString_Internal(T, typename(T))

typedef struct SystemConvertPrivate SystemConvertPrivate;

typedef struct SystemConvert
{
    Object object;
    private(SystemConvert);
    void *(*Convert)(void); /* Experimental */
    char *(*GetType)(void);
    struct
    {
        Char *(*ToChar_Internal)(void *, const char *);
        Char *(*ToChar_Class)(void *, ...);
        Char *(*ToChar_Integral)(void *, ...);
        Float *(*ToFloat_Internal)(void *, const char *);
        Float *(*ToFloat_Class)(void *, ...);
        Float *(*ToFloat_Integral)(void *, ...);
        Double *(*ToDouble_Internal)(void *, const char *);
        Double *(*ToDouble_Class)(void *, ...);
        Double *(*ToDouble_Integral)(void *, ...);
        Int16 *(*ToInt16_Internal)(void *, const char *);
        Int16 *(*ToInt16_Class)(void *, ...);
        Int16 *(*ToInt16_Integral)(void *, ...);
        Int32 *(*ToInt32_Internal)(void *, const char *);
        Int32 *(*ToInt32_Class)(void *, ...);
        Int32 *(*ToInt32_Integral)(void *, ...);
        Int64 *(*ToInt64_Internal)(void *, const char *);
        Int64 *(*ToInt64_Class)(void *, ...);
        Int64 *(*ToInt64_Integral)(void *, ...);
        UInt16 *(*ToUInt16_Internal)(void *, const char *);
        UInt16 *(*ToUInt16_Class)(void *, ...);
        UInt16 *(*ToUInt16_Integral)(void *, ...);
        UInt32 *(*ToUInt32_Internal)(void *, const char *);
        UInt32 *(*ToUInt32_Class)(void *, ...);
        UInt32 *(*ToUInt32_Integral)(void *, ...);
        UInt64 *(*ToUInt64_Internal)(void *, const char *);
        UInt64 *(*ToUInt64_Class)(void *, ...);
        UInt64 *(*ToUInt64_Integral)(void *, ...);
        String *(*ToString_Internal)(void *, const char *);
        String *(*ToString_Class)(void *, ...);
        String *(*ToString_Integral)(void *, ...);
    };
    #define ToChar(T) ToCharEx(T)
    #define ToFloat(T) ToFloatEx(T) 
    #define ToDouble(T) ToDoubleEx(T)
    #define ToInt16(T) ToInt16Ex(T)
    #define ToInt32(T) ToInt32Ex(T)
    #define ToInt64(T) ToInt64Ex(T)
    #define ToUInt16(T) ToUInt16Ex(T)
    #define ToUInt32(T) ToUInt32Ex(T)
    #define ToUInt64(T) ToUInt64Ex(T)
    #define ToString(T) ToStringEx(T)
} SystemConvert;

SystemConvert *Convert;

extern void *SystemConvert_new(void);
extern char *SystemConvert_GetType(void);
extern Char *SystemConvert_ToChar_Internal(void *, const char *, SystemConvert * const);
extern Char *SystemConvert_ToChar_Class(void *, ...);
extern Char *SystemConvert_ToChar_Integral(void *, ...);
extern Float *SystemConvert_ToFloat_Internal(void *, const char *, SystemConvert * const);
extern Float *SystemConvert_ToFloat_Class(void *, ...);
extern Float *SystemConvert_ToFloat_Integral(void *, ...);
extern Double *SystemConvert_ToDouble_Internal(void *, const char *, SystemConvert * const);
extern Double *SystemConvert_ToDouble_Class(void *, ...);
extern Double *SystemConvert_ToDouble_Integral(void *, ...);
extern Int16 *SystemConvert_ToInt16_Internal(void *, const char *, SystemConvert * const);
extern Int16 *SystemConvert_ToInt16_Class(void *, ...);
extern Int16 *SystemConvert_ToInt16_Integral(void *, ...);
extern Int32 *SystemConvert_ToInt32_Internal(void *, const char *, SystemConvert * const);
extern Int32 *SystemConvert_ToInt32_Class(void *, ...);
extern Int32 *SystemConvert_ToInt32_Integral(void *, ...);
extern Int64 *SystemConvert_ToInt64_Internal(void *, const char *, SystemConvert * const);
extern Int64 *SystemConvert_ToInt64_Class(void *, ...);
extern Int64 *SystemConvert_ToInt64_Integral(void *, ...);
extern UInt16 *SystemConvert_ToUInt16_Internal(void *, const char *, SystemConvert * const);
extern UInt16 *SystemConvert_ToUInt16_Class(void *, ...);
extern UInt16 *SystemConvert_ToUInt16_Integral(void *, ...);
extern UInt32 *SystemConvert_ToUInt32_Internal(void *, const char *, SystemConvert * const);
extern UInt32 *SystemConvert_ToUInt32_Class(void *, ...);
extern UInt32 *SystemConvert_ToUInt32_Integral(void *, ...);
extern UInt64 *SystemConvert_ToUInt64_Internal(void *, const char *, SystemConvert * const);
extern UInt64 *SystemConvert_ToUInt64_Class(void *, ...);
extern UInt64 *SystemConvert_ToUInt64_Integral(void *, ...);
extern String *SystemConvert_ToString_Internal(void *, const char *, SystemConvert * const);
extern String *SystemConvert_ToString_Class(void *, ...);
extern String *SystemConvert_ToString_Integral(void *, ...);

#endif /* CONVERSION_H */
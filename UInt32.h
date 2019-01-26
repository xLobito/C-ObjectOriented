#include "ObjectPrueba.h"

#ifndef UINT32_H
#define UINT32_H

typedef struct UInt32Private UInt32Private;

typedef struct uint32
{
    Object object;
    private(UInt32);
    short (*Get)(void);
    struct Uint32 *(*Parse)(struct string *);
    //Char *(*ToChar)(void);
    struct string *(*ToString)(void);
    bool (*ReferenceEquality)(void *);
    bool (*Equals)(struct uint32 *); 
    #define UInt32(args...) overload(UInt32, args)
    void *(*UInt320)(void);
    void *(*UInt321)(int);
} UInt32;

extern unsigned int UInt32_Get(UInt32 * const);
extern UInt32 *UInt32_Parse(struct string *, UInt32 * const);
extern struct string *UInt32_ToString(UInt32 * const);
extern bool UInt32_ReferenceEquality(void *, UInt32 * const); 
extern bool UInt32_Equals(UInt32 *, UInt32 * const);
/* Ctor */
extern void *UInt32_UInt320(UInt32 *);
extern void *UInt32_UInt321(unsigned int, UInt32 *);

#endif /* UINT32_H */

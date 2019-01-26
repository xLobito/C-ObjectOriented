#include "ObjectPrueba.h"

#ifndef UINT64_H
#define UINT64_H

typedef struct UInt64Private UInt64Private;

typedef struct uint64
{
    Object object;
    private(UInt64);
    unsigned long (*Get)(void);
    struct Uint64 *(*Parse)(struct string *);
    //Char *(*ToChar)(void);
    struct string *(*ToString)(void);
    bool (*ReferenceEquality)(void *);
    bool (*Equals)(struct uint64 *); 
    #define UInt64(args...) overload(UInt64, args)
    void *(*UInt640)(void);
    void *(*UInt641)(unsigned long);
} UInt64;

extern unsigned long UInt64_Get(UInt64 * const);
extern UInt64 *UInt64_Parse(struct string *, UInt64 * const);
extern struct string *UInt64_ToString(UInt64 * const);
extern bool UInt64_ReferenceEquality(void *, UInt64 * const); 
extern bool UInt64_Equals(UInt64 *, UInt64 * const);
/* Ctor */
extern void *UInt64_UInt640(UInt64 *);
extern void *UInt64_UInt641(unsigned long, UInt64 *);

#endif /* UINT64_H */

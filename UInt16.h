#include "ObjectPrueba.h"

#ifndef UINT16_H
#define UINT16_H

typedef struct UInt16Private UInt16Private;

typedef struct uint16
{
    Object object;
    private(UInt16);
    short (*Get)(void);
    struct Uint16 *(*Parse)(struct string *);
    //Char *(*ToChar)(void);
    struct string *(*ToString)(void);
    bool (*ReferenceEquality)(void *);
    bool (*Equals)(struct uint16 *); 
    #define UInt16(args...) overload(UInt16, args)
    void *(*UInt160)(void);
    void *(*UInt161)(short);
} UInt16;

extern unsigned short UInt16_Get(UInt16 * const);
extern UInt16 *UInt16_Parse(struct string *, UInt16 * const);
extern struct string *UInt16_ToString(UInt16 * const);
extern bool UInt16_ReferenceEquality(void *, UInt16 * const); 
extern bool UInt16_Equals(UInt16 *, UInt16 * const);
/* Ctor */
extern void *UInt16_UInt160(UInt16 *);
extern void *UInt16_UInt161(unsigned short, UInt16 *);

#endif /* UINT16_H */

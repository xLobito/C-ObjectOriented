#include "ObjectPrueba.h"

#ifndef INT16_H
#define INT16_H

typedef struct Int16Private Int16Private;

typedef struct int16
{
    Object object;
    private(Int16);
    short (*Get)(void);
    struct int16 *(*Parse)(struct string *);
    //Char *(*ToChar)(void);
    struct string *(*ToString)(void);
    bool (*ReferenceEquality)(void *);
    bool (*Equals)(struct int16 *); 
    #define Int16(args...) overload(Int16, args)
    void *(*Int160)(void);
    void *(*Int161)(short);
} Int16;

extern short Int16_Get(Int16 * const);
extern Int16 *Int16_Parse(struct string *, Int16 * const);
extern struct string *Int16_ToString(Int16 * const);
extern bool Int16_ReferenceEquality(void *, Int16 * const); 
extern bool Int16_Equals(Int16 *, Int16 * const);
/* Ctor */
extern void *Int16_Int160(Int16 *);
extern void *Int16_Int161(short, Int16 *);

#endif /* INT16_H */
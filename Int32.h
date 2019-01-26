#include "ObjectPrueba.h"

#ifndef INT32_H
#define INT32_H

typedef struct Int32Private Int32Private;

typedef struct int32
{
    Object object;
    private(Int32);
    int (*Get)(void);
    struct int32 *(*Parse)(struct string *);
    struct string *(*ToString)(void);
    bool (*ReferenceEquality)(void *);
    bool (*Equals)(struct int32 *);
    #define Int32(args...) overload(Int32, args)
    void *(*Int320)(void);
    void *(*Int321)(int); 
} Int32;

extern int Int32_Get(Int32 * const);
extern Int32 *Int32_Parse(struct string *, Int32 * const);
extern struct string *Int32_ToString(Int32 * const);
extern bool Int32_ReferenceEquality(void *, Int32 * const);
extern bool Int32_Equals(Int32 *, Int32 * const);
/* Ctor */
extern void *Int32_Int320(Int32 *);
extern void *Int32_Int321(int, Int32 *);

#endif /* INT32_H */
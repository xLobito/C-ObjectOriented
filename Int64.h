#include "ObjectPrueba.h"

#ifndef INT64_H
#define INT64_H

typedef struct Int64Private Int64Private;

typedef struct int64
{
    Object object;
    private(Int64);
    long (*Get)(void);
    struct int64 *(*Parse)(struct string *);
    struct string *(*ToString)(void);
    bool (*ReferenceEquality)(void *);
    bool (*Equals)(struct int64 *);
    #define Int64(args...) overload(Int64, args)
    void *(*Int640)(void);
    void *(*Int641)(long); 
} Int64;

extern long Int64_Get(Int64 * const);
extern Int64 *Int64_Parse(struct string *, Int64 * const);
extern struct string *Int64_ToString(Int64 * const);
extern bool Int64_ReferenceEquality(void *, Int64 * const);
extern bool Int64_Equals(Int64 *, Int64 * const);
/* Ctor */
extern void *Int64_Int640(Int64 *);
extern void *Int64_Int641(long, Int64 *);

#endif /* INT32_H */
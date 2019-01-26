#include "ObjectPrueba.h"

#ifndef FLOAT_H
#define FLOAT_H

typedef struct FloatPrivate FloatPrivate;

typedef struct floatClass
{
    Object object;
    private(Float);
    float (*Get)(void);
    bool (*Equals)(struct floatClass *);
    struct string *(*ToString)(void);
    char *(*GetType)(void);
    #define Float(args...) overload(Float, args);
    void *(*Float0)(void);
    void *(*Float1)(const float);
} Float;

/* Public */
extern float Float_Get(Float *);
extern bool Float_Equals(Float *, Float *); 
extern struct string *Float_ToString(Float *);
extern struct string *Float_GetType(Float *);
/* Ctor */
extern void *Float_Float0(Float *);
extern void *Float_Float1(const float, Float *);

#endif /* FLOAT_H */
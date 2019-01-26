#include "ObjectPrueba.h"

#ifndef DOUBLE_H
#define DOUBLE_H

typedef struct DoublePrivate DoublePrivate;

typedef struct doubleClass
{
    Object object;
    private(Double);
    double (*Get)(void);
    bool (*Equals)(struct doubleClass *);
    struct doubleClass *(*Parse)(struct string *);
    struct string *(*ToString)(void);
    char *(*GetType)(void);
    #define Double(args...) overload(Double, args);
    void *(*Double0)(void);
    void *(*Double1)(double);
} Double;

/* Public */
extern double Double_Get(Double * const);
extern bool Double_Equals(Double *, Double * const);
extern Double *Double_Parse(struct string *, Double * const);
extern struct string *Double_ToString(Double * const);
extern char *Double_GetType(Double * const);
/* Ctor */
extern void *Double_Double0(Double *);
extern void *Double_Double1(double, Double *);

#endif /* DOUBLE_H */
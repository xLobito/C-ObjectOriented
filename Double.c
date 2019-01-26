#include "Double.h"

typedef struct DoublePrivate
{
    Object object;
    double value;
    void (*Set)(double);
} DoublePrivate;

/* Public */
double Double_Get(Double * const);
bool Double_Equals(Double *, Double * const);
Double *Double_Parse(struct string *, Double * const);
struct string *Double_ToString(Double * const);
char *Double_GetType(Double * const);
/* Ctor */
void *Double_Double0(Double *);
void *Double_Double1(double, Double *);
/* Private */
static void DoublePrivate_Set(double, DoublePrivate * const);

double Double_Get(Double * const this)
{
    return this->DoublePrivate->value;
}

bool Double_Equals(Double *__cmp, Double * const this)
{
    return (__cmp->Get() == this->Get()) ? true : false;
}

Double *Double_Parse(struct string *__fmt, Double * const this)
{
    Double *ret = new Instance(Double, 1);

    ret->Double(atof(__fmt->Get()));
    return ret;
}

struct string *Double_ToString(Double * const this)
{
    char *__s = GC_MALLOC(255);
    String *ret = new Instance(String, 1);

    (void)sprintf(__s, "%lf", this->Get());
    ret->String(__s);
    return ret;
}

char *Double_GetType(Double * const this)
{
    String *ret = new Instance(String, 1);

    ret->String("Double");
    return ret->Get();
}

void *Double_Double0(Double *this)
{
    /* Encapsulate */
    void *__this;
    void *__save_fp = (void *)this->Double0;
    __this = Object_create(sizeof(*this), 8);
    callprotect(&this->object);
    memcpy(this, __this, sizeof(*this));
    FUNCTION(Double, Get, 0);
    FUNCTION(Double, Equals, 1);
    FUNCTION(Double, Parse, 1);
    FUNCTION(Double, ToString, 0);
    FUNCTION(Double, GetType, 0);
    FUNCTION(Double, Double1, 1);
    this->Double0 = __save_fp;
    this->DoublePrivate = Object_create(sizeof(DoublePrivate), 1);
    FUNCTIONP(Double, Set, 1);
    Object_prepare(&this->DoublePrivate->object);
    this->DoublePrivate->Set(0.0);
    Object_prepare(&this->object);
    return 0;
}

void *Double_Double1(double value, Double *this)
{
    /* Encapsulate */
    void *__this;
    void *__save_fp = (void *)this->Double1;
    __this = Object_create(sizeof(*this), 8);
    callprotect(&this->object);
    memcpy(this, __this, sizeof(*this));
    FUNCTION(Double, Get, 0);
    FUNCTION(Double, Equals, 1);
    FUNCTION(Double, Parse, 1);
    FUNCTION(Double, ToString, 0);
    FUNCTION(Double, GetType, 0);
    FUNCTION(Double, Double0, 0);
    this->Double1 = __save_fp;
    this->DoublePrivate = Object_create(sizeof(DoublePrivate), 1);
    FUNCTIONP(Double, Set, 1);
    Object_prepare(&this->DoublePrivate->object);
    this->DoublePrivate->Set(value);
    Object_prepare(&this->object);
    return 0;
}

static void DoublePrivate_Set(double value, DoublePrivate * const this)
{
    this->value = value;
    return;
}
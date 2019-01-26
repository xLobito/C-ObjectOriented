#include "Float.h"

typedef struct FloatPrivate
{
    Object object;
    float value;
    void (*Set)(float);
} FloatPrivate;

/* Public */
float Float_Get(Float *);
bool Float_Equals(Float *, Float *); 
struct string *Float_ToString(Float *);
struct string *Float_GetType(Float *);
/* Ctor */
void *Float_Float0(Float *);
void *Float_Float1(float, Float *);
/* Private */
static void FloatPrivate_Set(float, FloatPrivate * const);

float Float_Get(Float *this)
{
    return this->FloatPrivate->value;
}

bool Float_Equals(Float *__cmp, Float *this)
{
    return (__cmp->Get() == this->Get()) ? true : false;
}

struct string *Float_ToString(Float *this)
{
    float __f = this->Get();
    char *__fmt = GC_MALLOC(sizeof(float));
    String *ret = new Instance(String, 1);
    
    (void)sprintf(__fmt, "%f", __f);
    ret->String(__fmt);
    return ret;
}   

struct string *Float_GetType(Float *this)
{
    String *ret = new Instance(String, 1);

    ret->String("Float");
    return ret;
}

optimize(0) void *Float_Float0(Float *this)
{
    /* Encapsulate */
    void *__this;
    void *__save_fp = (void *)this->Float0;
    callprotect(&this->object);
    __this = Object_create(sizeof(*this), 7);
    memcpy(this, __this, sizeof(*this));
    FUNCTION(Float, Get, 0);
    FUNCTION(Float, Equals, 1);
    FUNCTION(Float, ToString, 0);
    FUNCTION(Float, GetType, 0);
    FUNCTION(Float, Float1, 1);
    this->Float0 = __save_fp;
    this->FloatPrivate = Object_create(sizeof(FloatPrivate), 1);
    FUNCTIONP(Float, Set, 0);
    Object_prepare(&this->FloatPrivate->object);
    this->FloatPrivate->Set(0.0);
    Object_prepare(&this->object);
    return 0;
}

/* Revisar */
optimize(0) void *Float_Float1(float value, Float *this)
{
    /* Encapsulate */
    void *__this;
    void *__save_fp = (void *)this->Float1;
    callprotect(&this->object);
    __this = Object_create(sizeof(*this), 7);
    memcpy(this, __this, sizeof(*this));
    FUNCTION(Float, Get, 0);
    FUNCTION(Float, Equals, 1);
    FUNCTION(Float, ToString, 0);
    FUNCTION(Float, GetType, 0);
    FUNCTION(Float, Float0, 0);
    this->Float1 = __save_fp;
    this->FloatPrivate = Object_create(sizeof(FloatPrivate), 1);
    FUNCTIONP(Float, Set, 1);
    Object_prepare(&this->FloatPrivate->object);
    this->FloatPrivate->Set(value);
    Object_prepare(&this->object);
    return 0;
}

/* Revisar */
static void FloatPrivate_Set(float value, FloatPrivate * const this)
{
    this->value = value;
    return;
}
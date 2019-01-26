#include "Char.h"
#include <ctype.h>

typedef struct CharPrivate
{
    Object object;
    char c;
    void (*Set)(const char);
} CharPrivate;

/* Public */
char Char_Get(Char *);
int Char_CompareTo(Char *, Char *);
bool Char_Equals(Char *, Char *);
String *Char_GetType(Char *);
bool Char_IsDigit(Char *, Char *);
bool Char_IsLetter(Char *, Char *);
bool Char_IsLower(Char *, Char *);
bool Char_IsUpper(Char *, Char *);
Char *Char_ToLower(Char *, Char *);
Char *Char_ToUpper(Char *, Char *);
String *Char_ToString(Char *);
/* Ctor */
void *Char_Char0(Char *);
void *Char_Char1(const char, Char *);
/* Private */
static void CharPrivate_Set(const char, CharPrivate *);

char Char_Get(Char *this)
{
    return this->CharPrivate->c;
}

int Char_CompareTo(Char *__cmp, Char *this)
{
    return (const unsigned char)__cmp->Get() - (const unsigned char)this->Get();
}

bool Char_Equals(Char *__cmp, Char *this)
{
    return (__cmp->Get() == this->Get()) ? true : false;
}

String *Char_GetType(Char *this)
{
    String *ret = new Instance(String, 1);

    ret->String("Char");
    return ret;
}

bool Char_IsDigit(Char *__eval, Char *this)
{
    return isdigit(__eval->Get()) > 0 ? true : false;
}

bool Char_IsLetter(Char *__eval, Char *this)
{
    return isalpha(__eval->Get()) > 0 ? true : false;
}

bool Char_IsLower(Char *__eval, Char *this)
{
    return islower(__eval->Get()) > 0 ? true : false;
}

bool Char_IsUpper(Char *__eval, Char *this)
{
    return isupper(__eval->Get()) > 0 ? true : false;
}

Char *Char_ToLower(Char *__chg, Char *this)
{
    char ret;

    ret = tolower(__chg->Get());
    __chg->CharPrivate->Set(ret);
    return __chg;
}

Char *Char_ToUpper(Char *__chg, Char *this)
{
    char ret;

    ret = toupper(__chg->Get());
    __chg->CharPrivate->Set(ret);
    return __chg;
}

optimize(0) String *Char_ToString(Char *this)
{
    String *ret = new Instance(String, 1);
    char *__fmt = GC_malloc(1);
    char __c = this->Get();

    (*__fmt) = __c;
    ret->String(__fmt);
    return ret;
}

/* Ctor */
void *Char_Char0(Char *this)
{
    /* Encapsulate */
    void *__this;
    void *__save_fp = (void *)this->Char0;
    callprotect(&this->object);
    __this = Object_create(sizeof(*this), 14);
    memcpy(this, __this, sizeof(*this));
    FUNCTION(Char, Get, 0);
    FUNCTION(Char, CompareTo, 1);
    FUNCTION(Char, Equals, 1);
    FUNCTION(Char, GetType, 0);
    FUNCTION(Char, IsDigit, 1);
    FUNCTION(Char, IsLetter, 1);
    FUNCTION(Char, IsLower, 1);
    FUNCTION(Char, IsUpper, 1);
    FUNCTION(Char, ToLower, 1);
    FUNCTION(Char, ToUpper, 1);
    FUNCTION(Char, ToString, 0);
    FUNCTION(Char, Char1, 1);
    this->Char0 = __save_fp;
    this->CharPrivate = Object_create(sizeof(CharPrivate), 1);
    FUNCTIONP(Char, Set, 1);
    Object_prepare(&this->CharPrivate->object);
    this->CharPrivate->Set('\0');
    Object_prepare(&this->object);
    return 0;
}

void *Char_Char1(const char c, Char *this)
{
    /* Encapsulate */
    void *__this;
    void *__save_fp = (void *)this->Char1;
    callprotect(&this->object);
    __this = Object_create(sizeof(*this), 14);
    memcpy(this, __this, sizeof(*this));
    FUNCTION(Char, Get, 0);
    FUNCTION(Char, CompareTo, 1);
    FUNCTION(Char, Equals, 1);
    FUNCTION(Char, GetType, 0);
    FUNCTION(Char, IsDigit, 1);
    FUNCTION(Char, IsLetter, 1);
    FUNCTION(Char, IsLower, 1);
    FUNCTION(Char, IsUpper, 1);
    FUNCTION(Char, ToLower, 1);
    FUNCTION(Char, ToUpper, 1);
    FUNCTION(Char, ToString, 0);
    FUNCTION(Char, Char0, 1);
    this->Char1 = __save_fp;
    this->CharPrivate = Object_create(sizeof(CharPrivate), 1);
    FUNCTIONP(Char, Set, 1);
    Object_prepare(&this->CharPrivate->object);
    this->CharPrivate->Set(c);
    Object_prepare(&this->object);
    return 0;
}

/* Private */
static void CharPrivate_Set(const char c, CharPrivate *this)
{
    this->c = c;
    return;
}
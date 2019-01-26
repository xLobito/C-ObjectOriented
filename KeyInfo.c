#include "KeyInfo.h"

extern void *KeyInfo_new(void);
extern bool KeyInfo_Equals(KeyInfo *, KeyInfo * const);
extern char *KeyInfo_GetType(KeyInfo * const);

void *KeyInfo_new(void)
{
    KeyInfo *this = Object_create(sizeof(KeyInfo), 2);

    FUNCTION(KeyInfo, Equals, 1);
    FUNCTION(KeyInfo, GetType, 0);
    Object_prepare(&this->object);
    return this;
}

bool KeyInfo_Equals(KeyInfo *__cmp, KeyInfo * const this)
{
    return (__cmp == this) ? true : false;
}

char *KeyInfo_GetType(KeyInfo * const this)
{
    return "KeyInfo";
}
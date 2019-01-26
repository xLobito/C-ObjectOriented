#include "ObjectPrueba.h"

#ifndef KEY_INFO_H
#define KEY_INFO_H

#define KeyInfo() KeyInfo_new()

typedef struct keyword
{
    Object object;
    int asciiNumber;
    char asciiKey;
    bool (*Equals)(struct keyword *);
    char *(*GetType)(void);
} KeyInfo;

extern void *KeyInfo_new(void);
extern bool KeyInfo_Equals(KeyInfo *, KeyInfo * const);
extern char *KeyInfo_GetType(KeyInfo * const);

#endif /* KEY_INFO_H */
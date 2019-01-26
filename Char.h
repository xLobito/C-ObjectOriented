#include "ObjectPrueba.h"

#ifndef CHAR_H
#define CHAR_H

typedef struct CharPrivate CharPrivate;

typedef struct charClass
{
    Object object;
    private(Char);
    char (*Get)(void);
    int (*CompareTo)(struct charClass *);
    bool (*Equals)(struct charClass *);
    struct string *(*GetType)(void); /* Virtual */
    bool (*IsDigit)(struct charClass *);
    bool (*IsLetter)(struct charClass *);
    bool (*IsLower)(struct charClass *);
    bool (*IsUpper)(struct charClass *);
    struct charClass (*ToLower)(struct charClass *);
    struct charClass (*ToUpper)(struct charClass *);
    struct string *(*ToString)(void);
    #define Char(args...) overload(Char, args);
    void *(*Char0)(void);
    void *(*Char1)(const char);
} Char;

/* Public */
extern int Char_CompareTo(Char *, Char *);
extern bool Char_Equals(Char *, Char *);
extern struct string *Char_GetType(Char *);
extern bool Char_IsDigit(Char *, Char *);
extern bool Char_IsLetter(Char *, Char *);
extern bool Char_IsLower(Char *, Char *);
extern bool Char_IsUpper(Char *, Char *);
extern Char *Char_ToLower(Char *, Char *);
extern Char *Char_ToUpper(Char *, Char *);
extern struct string *Char_ToString(Char *);
/* Ctor */
extern void *Char_Char0(Char *);
extern void *Char_Char1(const char, Char *);

#endif /* CHAR_H */
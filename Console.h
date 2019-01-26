#include "ObjectPrueba.h"

#ifndef CONSOLE_H
#define CONSOLE_H

#define FUNCTIONPARAM(T, N) \
    do \
    { \
        this->N = &T ## _ ## N; \
    } while(0);

typedef struct systemConsole
{
    Object object;
    int argc;
    char **argv; 
    void (*ClearConsole)(void);
    Array(String) *(*GetArgv)(void); 
    Int32 *(*Read)(void);
    KeyInfo *(*ReadKey)(void);
    String *(*ReadLine)(void);
    void (*Write)(Char *);
    void (*WriteLine)(const char *, ...);
} SystemConsole;

/* Static class */
static void StaticConsole(int, char **);
extern SystemConsole *SystemConsole_new(void);
extern void SystemConsole_ClearConsole(SystemConsole * const);
extern Array(String) *SystemConsole_GetArgv(SystemConsole * const);
extern Int32 *SystemConsole_Read(SystemConsole * const);
extern KeyInfo *SystemConsole_ReadKey(SystemConsole * const);
extern String *SystemConsole_ReadLine(SystemConsole * const);
extern void SystemConsole_Write(Char *, SystemConsole * const);
extern void SystemConsole_WriteLine(const char *, ...);
extern void SystemConsole_VaWriteLine(const char *, va_list);

/* Global Variables */
SystemConsole *Console;
__attribute__((section(".preinit_array"), used)) static __typeof__(StaticConsole) *ctorConsole = &StaticConsole;

/* Section */
static void StaticConsole(int argc, char **argv)
{
    Console = new SystemConsole_new();
    
    Console->argc = argc;
    Console->argv = argv;
    return;
}

#endif /* CONSOLE_H */
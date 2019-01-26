#include "Console.h"

extern SystemConsole *SystemConsole_new(void);
extern void SystemConsole_ClearConsole(SystemConsole * const);
extern Array(String) *SystemConsole_GetArgv(SystemConsole * const);
extern Int32 *SystemConsole_Read(SystemConsole * const);
extern KeyInfo *SystemConsole_ReadKey(SystemConsole * const);
extern String *SystemConsole_ReadLine(SystemConsole * const);
extern void SystemConsole_Write(Char *, SystemConsole * const);
extern void SystemConsole_WriteLine(const char *, ...);
extern void SystemConsole_VaWriteLine(const char *, va_list);

SystemConsole *SystemConsole_new(void)
{
    SystemConsole *this = Object_create(sizeof(SystemConsole), 6);
    
    FUNCTION(SystemConsole, ClearConsole, 0);
    FUNCTION(SystemConsole, GetArgv, 0);
    FUNCTION(SystemConsole, Read, 0);
    FUNCTION(SystemConsole, ReadKey, 0);
    FUNCTION(SystemConsole, ReadLine, 0);
    FUNCTION(SystemConsole, Write, 1);
    FUNCTIONPARAM(SystemConsole, WriteLine);
    Object_prepare(&this->object);
    return this;
}

void SystemConsole_ClearConsole(SystemConsole * const this)
{
    int ret __attribute__((unused));
    
    ret = system("clear");
    return;
}

Array(String) *SystemConsole_GetArgv(SystemConsole * const this) /* Puede generar MemoryAccessException() */
{   
    Array(String) *aux = new Collection(String, this->argc);
    int len = aux->Length();
    String **__s = GC_MALLOC(sizeof(String *) * len);
    String *__s2 = new Instance(String, 1);
    
    if(!aux)
    {
        throw new MemoryAccessException("No memory is available to be allocated");
    }
    else
    {
        for(int i=0; i<Console->argc; i++)
        {
            if(!aux->Get(i)->Get())
            {
                throw new MemoryAccessException("No memory is available to be allocated");
            }
            else
            {
                __s[i] = aux->Get(i);
                __s2->String(Console->argv[i]);
                __s[i] = __s2;
            }
        }
    }
    return aux;
}

Int32 *SystemConsole_Read(SystemConsole * const this) 
{
    Int32 *aux = new Instance(Int32, 1);
    
    if(!aux)
    {
        throw new MemoryAccessException("No memory is available");
    }
    else
    {
        aux->Int32(getchar());
    }
    return aux;
}

KeyInfo *SystemConsole_ReadKey(SystemConsole * const this)
{
    KeyInfo *ret = KeyInfo_new();

    ret->asciiKey = getchar();
    ret->asciiNumber = (int)ret->asciiKey;
    return ret;
}

String *SystemConsole_ReadLine(SystemConsole * const this)
{
    char *ignored __attribute__((unused));
    String *aux = new Instance(String, 1);
    char *__r = GC_MALLOC(255);

    if(!aux)
    {
        throw new MemoryAccessException("No memory is available");
    }
    else
    {
        ignored = fgets(__r, 255, stdin);
        aux->String(__r);
    }
    return aux;
}

void SystemConsole_Write(Char *c, SystemConsole * const this)
{
    if(!c)
    {
        throw new NullArgumentException();
    }
    return (void)printf("%c\n", c->Get());
}

void SystemConsole_WriteLine(const char *format, ...)
{
    va_list ap;
    char *__newline = GC_MALLOC(strlen(format) + 2); /* Avoid explicit C cast. Const cast required for away constness */

    va_start(ap, format);
    strcpy(__newline, format);
    __newline[strlen(format)] = '\n';
    __newline[strlen(format) + 1] = '\0';
    vprintf(__newline, ap);
    va_end(ap);
    return;
}
#include "Conversion.h"
#include <ctype.h>

typedef struct SystemConvertPrivate
{
    short MinValue;
    short MaxValue;
} SystemConvertPrivate;

void *SystemConvert_new(void);
char *SystemConvert_GetType(void);
Char *SystemConvert_ToChar_Internal(void *, const char *, SystemConvert * const);
Char *SystemConvert_ToChar_Class(void *, ...);
Char *SystemConvert_ToChar_Integral(void *, ...);
Float *SystemConvert_ToFloat_Internal(void *, const char *, SystemConvert * const);
Float *SystemConvert_ToFloat_Class(void *, ...);
Float *SystemConvert_ToFloat_Integral(void *, ...);
Double *SystemConvert_ToDouble_Internal(void *, const char *, SystemConvert * const);
Double *SystemConvert_ToDouble_Class(void *, ...);
Double *SystemConvert_ToDouble_Integral(void *, ...);
Int16 *SystemConvert_ToInt16_Internal(void *, const char *, SystemConvert * const);
Int16 *SystemConvert_ToInt16_Class(void *, ...);
Int16 *SystemConvert_ToInt16_Integral(void *, ...);
Int32 *SystemConvert_ToInt32_Internal(void *, const char *, SystemConvert * const);
Int32 *SystemConvert_ToInt32_Class(void *, ...);
Int32 *SystemConvert_ToInt32_Integral(void *, ...);
Int64 *SystemConvert_ToInt64_Internal(void *, const char *, SystemConvert * const);
Int64 *SystemConvert_ToInt64_Class(void *, ...);
Int64 *SystemConvert_ToInt64_Integral(void *, ...);
UInt16 *SystemConvert_ToUInt16_Internal(void *, const char *, SystemConvert * const);
UInt16 *SystemConvert_ToUInt16_Class(void *, ...);
UInt16 *SystemConvert_ToUInt16_Integral(void *, ...);
UInt32 *SystemConvert_ToUInt32_Internal(void *, const char *, SystemConvert * const);
UInt32 *SystemConvert_ToUInt32_Class(void *, ...);
UInt32 *SystemConvert_ToUInt32_Integral(void *, ...);
UInt64 *SystemConvert_ToUInt64_Internal(void *, const char *, SystemConvert * const);
UInt64 *SystemConvert_ToUInt64_Class(void *, ...);
UInt64 *SystemConvert_ToUInt64_Integral(void *, ...);
String *SystemConvert_ToString_Internal(void *, const char *, SystemConvert * const);
String *SystemConvert_ToString_Class(void *, ...);
String *SystemConvert_ToString_Integral(void *, ...);

void *SystemConvert_new(void)
{
    SystemConvert *this = Object_create(sizeof(SystemConvert), 31);

    this->SystemConvertPrivate = GC_MALLOC(sizeof(SystemConvertPrivate));
    this->SystemConvertPrivate->MinValue = 0;
    this->SystemConvertPrivate->MaxValue = 65535;
    FUNCTION(SystemConvert, GetType, 0);
    FUNCTION(SystemConvert, ToChar_Internal, 2);
    FUNCTION(SystemConvert, ToChar_Integral, 2);
    FUNCTION(SystemConvert, ToChar_Class, 2);
    FUNCTION(SystemConvert, ToFloat_Internal, 2);
    FUNCTION(SystemConvert, ToFloat_Integral, 2);
    FUNCTION(SystemConvert, ToFloat_Class, 2);
    FUNCTION(SystemConvert, ToDouble_Internal, 2);
    FUNCTION(SystemConvert, ToDouble_Integral, 2);
    FUNCTION(SystemConvert, ToDouble_Class, 2);
    FUNCTION(SystemConvert, ToInt16_Internal, 2);
    FUNCTION(SystemConvert, ToInt16_Integral, 2);
    FUNCTION(SystemConvert, ToInt16_Class, 2);
    FUNCTION(SystemConvert, ToInt32_Internal, 2);
    FUNCTION(SystemConvert, ToInt32_Integral, 2);
    FUNCTION(SystemConvert, ToInt32_Class, 2);
    FUNCTION(SystemConvert, ToInt64_Internal, 2);
    FUNCTION(SystemConvert, ToInt64_Integral, 2);
    FUNCTION(SystemConvert, ToInt64_Class, 2);
    FUNCTION(SystemConvert, ToUInt16_Internal, 2);
    FUNCTION(SystemConvert, ToUInt16_Integral, 2);
    FUNCTION(SystemConvert, ToUInt16_Class, 2);
    FUNCTION(SystemConvert, ToUInt32_Internal, 2);
    FUNCTION(SystemConvert, ToUInt32_Integral, 2);
    FUNCTION(SystemConvert, ToUInt32_Class, 2);
    FUNCTION(SystemConvert, ToUInt64_Internal, 2);
    FUNCTION(SystemConvert, ToUInt64_Integral, 2);
    FUNCTION(SystemConvert, ToUInt64_Class, 2);
    FUNCTION(SystemConvert, ToString_Internal, 2);
    FUNCTION(SystemConvert, ToString_Integral, 2);
    FUNCTION(SystemConvert, ToString_Class, 2);
    Object_prepare(&this->object);
    return this;
}

char *SystemConvert_GetType(void)
{
    return "Convert";
}

Char *SystemConvert_ToChar_Internal(void *arg, const char *T, SystemConvert * const this)
{
    Char *ret;
    char integralType[9][20] = {{ "float" }, { "double" }, { "short" }, { "int" }, { "long" }, { "unsigned short" }, { "unsigned int" }, { "unsigned long" }, { "char pointer" }};
    /* Evaluar object */
    char classType[10][20] = {{ "Char" }, { "Float" }, { "Double" }, { "Int16" }, { "Int32" }, { "Int64" }, { "UInt16"}, { "UInt32" }, { "UInt64" }, { "String"}};

    if(isupper(T[0]) != 0)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(classType[i], T) == 0)
            {
                ret = this->ToChar_Class(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    else
    {   
        for(int i=0; i<9; i++)
        {
            if(strcmp(integralType[i], T) == 0)
            {
                ret = this->ToChar_Integral(arg, i);
                return ret;
            }
        }
        //throw new InvalidCastException(); /* InvalidCastException */
        abort();
    }
    /* Fallthrough */   
    return ((Char *)0);
}

Char *SystemConvert_ToChar_Class(void *arg, ...)
{
    Char *ret = new Instance(Char, 1);
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret = (Char *)arg;
            break;
        case 1:
            //throw new InvalidCastException();
            abort();
            break;
        case 2:
            //throw new InvalidCastException();
            abort();
            break;
        case 3:
            if(((Int16 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); /* Debe ser UnderflowException */
            }
            else 
            {
                ret->Char((char)((Int16 *)arg)->Get());
            }
            break;
        case 4:
            if(((Int32 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); /* Debe ser UnderflowException */
            }
            else if(((Int32 *)arg)->Get() > 65535)
            {
                abort();
                //throw new OverflowException(); /* Debe ser OverflowException */
            }
            else
            {
                ret->Char((char)((Int32 *)arg)->Get());
            }
            break;
        case 5:
            if(((Int64 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); /* Debe ser UnderflowException */
            }
            else if(((Int64 *)arg)->Get() > 65535)
            {
                abort();
                //throw new OverflowException(); /* Debe ser OverflowException */
            }
            else
            {
                ret->Char((char)((Int64 *)arg)->Get());
            }
            break;
        case 6:
            if(((UInt16 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); /* Debe ser UnderflowException */
            }
            else 
            {
                ret->Char((char)((UInt16 *)arg)->Get());
            }
            break;
        case 7:
            if(((UInt32 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); /* Debe ser UnderflowException */
            }
            else if(((UInt32 *)arg)->Get() > 65535)
            {
                abort();
                //throw new OverflowException(); /* Debe ser OverflowException */
            }
            else
            {
                ret->Char((char)((UInt32 *)arg)->Get());
                //ret = new Char((char)((UInt32 *)arg)->value);
            }
            break;
        case 8:
            if(((UInt64 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); /* Debe ser UnderflowException */
            }
            else if(((UInt64 *)arg)->Get() > 65535)
            {
                abort();
                //throw new OverflowException(); /* Debe ser OverflowException */
            }
            else
            {
                ret->Char((char)((UInt64 *)arg)->Get());
            }
            break;
        case 9:
            ret->Char((char)((String *)arg)->Get()[0]);
            break;
        default:
            abort();
            break;
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

Char *SystemConvert_ToChar_Integral(void *arg, ...)
{
    Char *ret = new Instance(Char, 1);
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            // throw new InvalidCastException();
            abort();
            break;
        case 1:
            // throw new InvalidCastException();
            abort();
            break;
        case 2:
            if((*(short *)arg) < 0)
            {
                abort();
                // throw new UnderflowException(); /* Debe ser UnderflowException */
            }
            else 
            {
                ret->Char((char)(*(short *)arg));
            }
            break;
        case 3:
            if((*(int *)arg) < 0)
            {
                // throw new UnderflowException(); /* Debe ser UnderflowException */
                abort();
            }
            else if((*(int *)arg) > 65535)
            {
                // throw new OverflowException(); /* Debe ser OverflowException */
                abort();
            }
            else 
            {
                ret->Char((char)(*(int *)arg));
            }
            break;
        case 4:
            if((*(long *)arg) < 0)
            {
                // throw new UnderflowException(); /* Debe ser UnderflowException */
                abort();
            }
            else if((*(long *)arg) > 65535)
            {
                // throw new OverflowException(); /* Debe ser OverflowException */
                abort();
            }
            else 
            {
                ret->Char((char)(*(long *)arg));
            }
            break;
        case 5:
            if((*(unsigned short *)arg) < 0)
            {
               // throw new UnderflowException(); /* Debe ser UnderflowException */
                abort();
            }
            else 
            {
                ret->Char((char)(*(unsigned short *)arg));
            }
            break;
        case 6:
            if((*(unsigned int *)arg) < 0)
            {
                //throw new UnderflowException(); /* Debe ser UnderflowException */
                abort();
            }
            else if((*(unsigned int *)arg) > 65535)
            {
                abort();
                //throw new OverflowException(); /* Debe ser OverflowException */
            }
            else 
            {
                ret->Char((char)(*(unsigned int *)arg));
            }
            break;
        case 7:
            if((*(unsigned long *)arg) < 0)
            {
                abort();
                //throw new UnderflowException(); /* Debe ser UnderflowException */
            }
            else if((*(unsigned long *)arg) > 65535)
            {
                abort();
                //throw new OverflowException(); /* Debe ser OverflowException */
            }
            else 
            {
                ret->Char((char)(*(unsigned long *)arg));
            }
            break;
        case 8:
            ret->Char((*(char *)arg));
            break;
        default:
            abort();
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

Float *SystemConvert_ToFloat_Internal(void *arg, const char *T, SystemConvert * const this)
{
    Float *ret = new Instance(Float, 1);
    char integralType[9][20] = {{ "float" }, { "double" }, { "short" }, { "int" }, { "long" }, { "unsigned short" }, { "unsigned int" }, { "unsigned long" }, { "char pointer" }};
    /* Evaluar object */
    char classType[10][20] = {{ "Char" }, { "Float" }, { "Double" }, { "Int16" }, { "Int32" }, { "Int64" }, { "UInt16"}, { "UInt32" }, { "UInt64" }, { "String" }};

    if(isupper(T[0]) != 0)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(classType[i], T) == 0)
            {
                ret = this->ToFloat_Class(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    else
    {   
        for(int i=0; i<9; i++)
        {
            if(strcmp(integralType[i], T) == 0)
            {
                ret = this->ToFloat_Integral(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    /* Fallthrough */   
    return ((Float *)0);
}

Float *SystemConvert_ToFloat_Class(void *arg, ...)
{
    Float *ret = new Instance(Float, 1);
    char *checkConversion;
    float checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            abort();
            //throw new InvalidCastException();
            break;
        case 1:
            ret = (Float *)arg;
            break;
        case 2:
            ret->Float((float)((Double *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            break;
        case 3:
            ret->Float((float)((Int16 *)arg)->Get());
            break;
        case 4:
            ret->Float((float)((Int32 *)arg)->Get());
            break;
        case 5:
            ret->Float((float)((Int64 *)arg)->Get());
            break;
        case 6:
            ret->Float((float)((UInt16 *)arg)->Get());
            break;
        case 7:
            ret->Float((float)((UInt32 *)arg)->Get());
            break;
        case 8:
            ret->Float((float)((Int64 *)arg)->Get());
            break;
        case 9:
            checkRet = strtof(((String *)arg)->Get(), &checkConversion);
            if(!(*checkConversion))
            {
                ret->Float(checkRet);
            }
            else
            {
                //throw new FormatException("La conversión de String a Double es inválida");
                abort();
            }
            break;
        default:
            //throw new InvalidCastException();
            abort();
            break;
    }
    va_end(ap);
    return ret;
}

Float *SystemConvert_ToFloat_Integral(void *arg, ...)
{
    Float *ret = new Instance(Float, 1);
    char *checkConversion;
    float checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->Float((*(float *)arg));
            break;
        case 1:
            ret->Float((float)(*(double *)arg)); /* Añadir Underflow y Overflow para double */
            break;
        case 2:
            ret->Float((float)(*(short *)arg));
            break;
        case 3:
            ret->Float((float)(*(int *)arg));
            break;
        case 4:
            ret->Float((float)(*(long *)arg));
            break;
        case 5:
            ret->Float((float)(*(unsigned short *)arg));
            break;
        case 6:
            ret->Float((float)(*(unsigned int *)arg));
            break;
        case 7:
            ret->Float((float)(*(unsigned long *)arg));
            break;
        case 8:
            checkRet = strtof(arg, &checkConversion);
            if(!(*checkConversion))
            {
                ret->Float(checkRet);
            }
            else
            {
                //throw new FormatException("La conversión de String a Double es inválida");
                abort();
            }
            break;
        default:
            //throw new InvalidCastException();
            abort();
            break;
    }
    va_end(ap);
    return ret;
}

Double *SystemConvert_ToDouble_Internal(void *arg, const char *T, SystemConvert * const this)
{
    Double *ret;
    char integralType[9][20] = {{ "float" }, { "double" }, { "short" }, { "int" }, { "long" }, { "unsigned short" }, { "unsigned int" }, { "unsigned long" }, { "char pointer" }};
    /* Evaluar object */
    char classType[10][20] = {{ "Char" }, { "Float" }, { "Double" }, { "Int16" }, { "Int32" }, { "Int64" }, { "UInt16"}, { "UInt32" }, { "UInt64" }, { "String" }};

    if(isupper(T[0]) != 0)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(classType[i], T) == 0)
            {
                ret = this->ToDouble_Class(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    else
    {   
        for(int i=0; i<9; i++)
        {
            if(strcmp(integralType[i], T) == 0)
            {
                ret = this->ToDouble_Integral(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    /* Fallthrough */   
    return ((Double *)0);
}

Double *SystemConvert_ToDouble_Class(void *arg, ...)
{
    Double *ret = new Instance(Double, 1);
    char *checkConversion;
    double checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            //throw new InvalidCastException();
            abort();
            break;
        case 1:
            ret->Double((double)((Float *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            break;
        case 2:
            ret = (Double *)arg;
            break;
        case 3:
            ret->Double((double)((Int16 *)arg)->Get());
            break;
        case 4:
            ret->Double((double)((Int32 *)arg)->Get());
            break;
        case 5:
            ret->Double((double)((Int64 *)arg)->Get());
            break;
        case 6:
            ret->Double((double)((UInt16 *)arg)->Get());
            break;
        case 7:
            ret->Double((double)((UInt32 *)arg)->Get());
            break;
        case 8:
            ret->Double((double)((Int64 *)arg)->Get());
            break;
        case 9:
            checkRet = strtod(((String *)arg)->Get(), &checkConversion);
            if(!(*checkConversion))
            {
                ret->Double(checkRet);
            }
            else
            {
                abort();
                //throw new FormatException("La conversión de String a Double es inválida");
            }
            break;
        default:
            abort();
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

Double *SystemConvert_ToDouble_Integral(void *arg, ...)
{
    Double *ret = new Instance(Double, 1);
    char *checkConversion;
    double checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->Double(*(float *)arg);
            break;
        case 1:
            ret->Double(*(double *)arg); /* Añadir Underflow y Overflow para double */
            break;
        case 2:
            ret->Double((double)(*(short *)arg));
            break;
        case 3:
            ret->Double((double)(*(int *)arg));
            break;
        case 4:
            ret->Double((double)(*(long *)arg));
            break;
        case 5:
            ret->Double((double)(*(unsigned short *)arg));
            break;
        case 6:
            ret->Double((double)(*(unsigned int *)arg));
            break;
        case 7:
            ret->Double((double)(*(unsigned long *)arg));
            break;
        case 8:
            checkRet = strtod(arg, &checkConversion);
            if(!(*checkConversion))
            {
                ret->Double(checkRet);
            }
            else
            {
                abort();
                //throw new FormatException("La conversión de String a Double es inválida");
            }
            break;
        default:
            abort();
            break;
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

Int16 *SystemConvert_ToInt16_Internal(void *arg, const char *T, SystemConvert * const this)
{
    Int16 *ret;
    char integralType[9][20] = {{ "float" }, { "double" }, { "short" }, { "int" }, { "long" }, { "unsigned short" }, { "unsigned int" }, { "unsigned long" }, { "char pointer" }};
    /* Evaluar object */
    char classType[10][20] = {{ "Char" }, { "Float" }, { "Double" }, { "Int16" }, { "Int32" }, { "Int64" }, { "UInt16"}, { "UInt32" }, { "UInt64" }, { "String" }};

    if(isupper(T[0]) != 0)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(classType[i], T) == 0)
            {
                ret = this->ToInt16_Class(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    else
    {   
        for(int i=0; i<9; i++)
        {
            if(strcmp(integralType[i], T) == 0)
            {
                ret = this->ToInt16_Integral(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    /* Fallthrough */   
    return ((Int16 *)0);
}

Int16 *SystemConvert_ToInt16_Class(void *arg, ...)
{
    Int16 *ret = new Instance(Int16, 1);
    char *checkConversion;
    long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->Int16((short)((Char *)arg)->Get());
            break;
        case 1:
            ret->Int16((short)((Float *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            break;
        case 2:
            ret->Int16((short)((Double *)arg)->Get());
            break;
        case 3:
            ret = (Int16 *)arg;
            break;
        case 4:
            if(((Int32 *)arg)->Get() < SHRT_MIN)
            {
                abort();
                //throw new UnderflowException();
            }
            else if(((Int32 *)arg)->Get() > SHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->Int16((short)((Int32 *)arg)->Get()); 
            }
            break;
        case 5:
            if(((Int64 *)arg)->Get() < SHRT_MIN)
            {
                abort();
                //throw new UnderflowException();
            }
            else if(((Int64 *)arg)->Get() > SHRT_MAX)
            {
                abort();
               //throw new OverflowException();
            }
            else
            {
                ret->Int16((short)((Int64 *)arg)->Get()); 
            }
            break;
        case 6:
            ret->Int16((short)((UInt16 *)arg)->Get());
            break;
        case 7:
            if(((UInt32 *)arg)->Get() > SHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->Int16((short)((UInt32 *)arg)->Get()); 
            }
            break;
        case 8:
            if(((UInt64 *)arg)->Get() > SHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->Int16((short)((UInt64 *)arg)->Get()); 
            }
            break;
        case 9:
            checkRet = strtol(((String *)arg)->Get(), &checkConversion, 16);
            if(!(*checkConversion))
            {
                if(checkRet < SHRT_MIN)
                {
                    abort();
                    //throw new UnderflowException();
                }
                else if(checkRet > SHRT_MAX)
                {
                    abort();
                    //throw new OverflowException();
                }
                else
                {
                    ret->Int16(checkRet);
                }
            }
            else
            {
                abort();
                //throw new FormatException("String from String to Int16 is invalid");
            }
            break;
        default:
            abort();
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

Int16 *SystemConvert_ToInt16_Integral(void *arg, ...)
{
    Int16 *ret = new Instance(Int16, 1);
    char *checkConversion;
    long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->Int16((short)(*(float *)arg));
            break;
        case 1:
            ret->Int16((short)(*(double *)arg)); /* Añadir Underflow y Overflow para double */
            break;
        case 2:
            ret->Int16(*(short *)arg);
            break;
        case 3:
            if((*(int *)arg) < SHRT_MIN)
            {
                abort();
                //throw new UnderflowException();
            }
            else if((*(int *)arg) > SHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->Int16((short)(*(int *)arg)); 
            }
            break;
        case 4:
            if((*(long *)arg) < SHRT_MIN)
            {
                abort();
                //throw new UnderflowException();
            }
            else if((*(long *)arg) > SHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->Int16((short)(*(long *)arg)); 
            }
            break;
        case 5:
            ret->Int16((short)(*(unsigned short *)arg));
            break;
        case 6:
            if((*(unsigned int *)arg) > SHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->Int16((short)(*(unsigned int *)arg)); 
            }
            break;
        case 7:
            if((*(unsigned long *)arg) > SHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->Int16((short)(*(unsigned long *)arg)); 
            }
            break;
        case 8:
            checkRet = strtol(arg, &checkConversion, 16);
            if(!(*checkConversion))
            {
                if(checkRet < SHRT_MIN)
                {
                    abort();
                    //throw new UnderflowException();
                }
                else if(checkRet > SHRT_MAX)
                {
                    abort();
                    //throw new OverflowException();
                }
                else
                {
                    ret->Int16(checkRet);
                }
            }
            else
            {
                //throw new FormatException("Conversion from String to Int16 is invalid");
                abort();
            }
            break;
        default:
            abort();
            break;
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

Int32 *SystemConvert_ToInt32_Internal(void *arg, const char *T, SystemConvert * const this)
{
    Int32 *ret;
    char integralType[9][20] = {{ "float" }, { "double" }, { "short" }, { "int" }, { "long" }, { "unsigned short" }, { "unsigned int" }, { "unsigned long" }, { "char pointer" }};
    /* Evaluar object */
    char classType[10][20] = {{ "Char" }, { "Float" }, { "Double" }, { "Int16" }, { "Int32" }, { "Int64" }, { "UInt16"}, { "UInt32" }, { "UInt64" }, { "String" }};

    if(isupper(T[0]) != 0)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(classType[i], T) == 0)
            {
                ret = this->ToInt32_Class(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    else
    {   
        for(int i=0; i<9; i++)
        {
            if(strcmp(integralType[i], T) == 0)
            {
                ret = this->ToInt32_Integral(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    /* Fallthrough */   
    return ((Int32 *)0);
}

Int32 *SystemConvert_ToInt32_Class(void *arg, ...)
{
    Int32 *ret = new Instance(Int32, 1);
    char *checkConversion;
    long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->Int32((int)((Char *)arg)->Get());
            break;
        case 1:
            ret->Int32((int)((Float *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            break;
        case 2:
            ret->Int32((int)((Double *)arg)->Get());
            break;
        case 3:
            ret->Int32((int)((Int16 *)arg)->Get());
            break;
        case 4:
            ret = (Int32 *)arg;
            break;
        case 5:
            if(((Int64 *)arg)->Get() < INT_MIN)
            {
                abort();
                //throw new UnderflowException();
            }
            else if(((Int64 *)arg)->Get() > INT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->Int32((int)((Int64 *)arg)->Get()); 
            }
            break;
        case 6:
            ret->Int32((int)((UInt16 *)arg)->Get());
            break;
        case 7:
            ret->Int32((int)((UInt32 *)arg)->Get());
            break;
        case 8:
            if(((UInt64 *)arg)->Get() > INT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->Int32((int)((UInt64 *)arg)->Get()); 
            }
            break;
        case 9:
            checkRet = strtol(((String *)arg)->Get(), &checkConversion, 16);
            if(!(*checkConversion))
            {
                if(checkRet < INT_MIN)
                {
                    abort();
                    //throw new UnderflowException();
                }
                else if(checkRet > INT_MAX)
                {
                    abort();
                    //throw new OverflowException();
                }
                else
                {
                    ret->Int32(checkRet);
                }
            }
            else
            {
                abort();
                //throw new FormatException("La conversión de String a Int32 es inválida");
            }
            break;
        default:
            abort();
            break;
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

Int32 *SystemConvert_ToInt32_Integral(void *arg, ...)
{
    Int32 *ret = new Instance(Int32, 1);
    char *checkConversion;
    long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->Int32((int)(*(float *)arg));
            break;
        case 1:
            ret->Int32((int)(*(double *)arg)); /* Añadir Underflow y Overflow para double */
            break;
        case 2:
            ret->Int32((int)(*(short *)arg));
            break;
        case 3:
            ret->Int32(*(int *)arg);
            break;
        case 4:
            if((*(long *)arg) < INT_MIN)
            {
                //throw new UnderflowException();
                abort();
            }
            else if((*(long *)arg) > INT_MAX)
            {
                //throw new OverflowException();
                abort();
            }
            else
            {
                ret->Int32((int)(*(long *)arg)); 
            }
            break;
        case 5:
            ret->Int32((int)(*(unsigned short *)arg));
            break;
        case 6:
            ret->Int32((int)(*(unsigned int *)arg));
            break;
        case 7:
            if((*(unsigned long *)arg) > INT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                abort();
                ret->Int32((int)(*(unsigned long *)arg)); 
            }
            break;
        case 8:
            checkRet = strtol(arg, &checkConversion, 16);
            if(!(*checkConversion))
            {
                if(checkRet < INT_MIN)
                {
                    abort();
                    //throw new UnderflowException();
                }
                else if(checkRet > INT_MAX)
                {
                    abort();
                    //throw new OverflowException();
                }
                else
                {
                    ret->Int32(checkRet);
                }
            }
            else
            {
                //throw new FormatException("Conversion from String to Int32 is invalid");
                abort();
            }
            break;
        default:
            //throw new InvalidCastException();
            abort();
    }
    va_end(ap);
    return ret;
}

Int64 *SystemConvert_ToInt64_Internal(void *arg, const char *T, SystemConvert * const this)
{
    Int64 *ret;
    char integralType[9][20] = {{ "float" }, { "double" }, { "short" }, { "int" }, { "long" }, { "unsigned short" }, { "unsigned int" }, { "unsigned long" }, { "char pointer" }};
    /* Evaluar object */
    char classType[10][20] = {{ "Char" }, { "Float" }, { "Double" }, { "Int16" }, { "Int32" }, { "Int64" }, { "UInt16"}, { "UInt32" }, { "UInt64" }, { "String" }};

    if(isupper(T[0]) != 0)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(classType[i], T) == 0)
            {
                ret = this->ToInt64_Class(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    else
    {   
        for(int i=0; i<9; i++)
        {
            if(strcmp(integralType[i], T) == 0)
            {
                ret = this->ToInt64_Integral(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    /* Fallthrough */   
    return ((Int64 *)0);
}

Int64 *SystemConvert_ToInt64_Class(void *arg, ...)
{
    Int64 *ret = new Instance(Int64, 1);
    char *checkConversion;
    long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->Int64((long)((Char *)arg)->Get());
            break;
        case 1:
            ret->Int64((long)((Float *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            break;
        case 2:
            ret->Int64((long)((Double *)arg)->Get());
            break;
        case 3:
            ret->Int64((long)((Int16 *)arg)->Get());
            break;
        case 4:
            ret->Int64((long)((Int32 *)arg)->Get());
            break;
        case 5:
            ret = (Int64 *)arg;
            break;
        case 6:
            ret->Int64((long)((UInt16 *)arg)->Get());
            break;
        case 7:
            ret->Int64((long)((UInt32 *)arg)->Get());
            break;
        case 8:
            ret->Int64((long)((UInt64 *)arg)->Get());
            break;
        case 9:
            checkRet = strtol(((String *)arg)->Get(), &checkConversion, 16);
            if(!(*checkConversion))
            {
                if(checkRet < LONG_MIN)
                {
                    abort();
                    //throw new UnderflowException();
                }
                else if(checkRet > LONG_MAX)
                {
                    abort();
                    //throw new OverflowException();
                }
                else
                {
                    ret->Int64(checkRet);
                }
            }
            else
            {
                abort();
                //throw new FormatException("Conversion from String to Int64 is invalid");
            }
            break;
        default:
            abort();
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

Int64 *SystemConvert_ToInt64_Integral(void *arg, ...)
{
    Int64 *ret = new Instance(Int64, 1);
    char *checkConversion;
    long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->Int64((long)(*(float *)arg));
            break;
        case 1:
            ret->Int64((long)(*(double *)arg)); /* Añadir Underflow y Overflow para double */
            break;
        case 2:
            ret->Int64((long)(*(short *)arg));
            break;
        case 3:
            ret->Int64((long)(*(int *)arg));
            break;
        case 4:
            ret->Int64(*(long *)arg); 
            break;
        case 5:
            ret->Int64((long)(*(unsigned short *)arg));
            break;
        case 6:
            ret->Int64((long)(*(unsigned int *)arg));
            break;
        case 7:
            ret->Int64((long)(*(unsigned long *)arg));
            break;
        case 8:
            checkRet = strtol(arg, &checkConversion, 16);
            if(!(*checkConversion))
            {
                if(checkRet < LONG_MIN)
                {
                    abort();
                    //throw new UnderflowException();
                }
                else if(checkRet > LONG_MAX)
                {
                    abort();
                    //throw new OverflowException();
                }
                else
                {
                    ret->Int64(checkRet);
                }
            }
            else
            {
                //throw new FormatException("Conversion from String to Int64 is invalid");
                abort();
            }
            break;
        default:
            abort();
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

UInt16 *SystemConvert_ToUInt16_Internal(void *arg, const char *T, SystemConvert * const this)
{
    UInt16 *ret;
    char integralType[9][20] = {{ "float" }, { "double" }, { "short" }, { "int" }, { "long" }, { "unsigned short" }, { "unsigned int" }, { "unsigned long" }, { "char pointer" }};
    /* Evaluar object */
    char classType[10][20] = {{ "Char" }, { "Float" }, { "Double" }, { "Int16" }, { "Int32" }, { "Int64" }, { "UInt16"}, { "UInt32" }, { "UInt64" }, { "String" }};

    if(isupper(T[0]) != 0)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(classType[i], T) == 0)
            {
                ret = this->ToUInt16_Class(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    else
    {   
        for(int i=0; i<9; i++)
        {
            if(strcmp(integralType[i], T) == 0)
            {
                ret = this->ToUInt16_Integral(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    /* Fallthrough */   
    return ((UInt16 *)0);
}

UInt16 *SystemConvert_ToUInt16_Class(void *arg, ...)
{
    UInt16 *ret = new Instance(UInt16, 1);
    char *checkConversion;
    unsigned long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->UInt16((unsigned short)((Char *)arg)->Get());
            break;
        case 1:
            if(((Float *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if(((Float *)arg)->Get() > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)((Float *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            }
            break;
        case 2:
            if(((Double *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if(((Double *)arg)->Get() > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)((Double *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            }
            break;
        case 3:
            if(((Int16 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else
            {
                ret->UInt16((unsigned short)((Int16 *)arg)->Get());
            }
            break;
        case 4:
            if(((Int32 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else if(((Int32 *)arg)->Get() > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)((Int32 *)arg)->Get()); 
            }
            break;
        case 5:
            if(((Int64 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else if(((Int64 *)arg)->Get() > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)((Int64 *)arg)->Get()); 
            }
            break;
        case 6:
            ret = (UInt16 *)arg;
            break;
        case 7:
            if(((UInt32 *)arg)->Get() > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)((UInt32 *)arg)->Get()); 
            }
            break;
        case 8:
            if(((UInt64 *)arg)->Get() > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)((UInt64 *)arg)->Get()); 
            }
            break;
        case 9:
            checkRet = strtoul(((String *)arg)->Get(), &checkConversion, 16);
            if(!(*checkConversion))
            {
                if(checkRet > USHRT_MAX)
                {
                    abort();
                    //throw new OverflowException();
                }
                else
                {
                    ret->UInt16(checkRet);
                }
            }
            else
            {
                abort();
                //throw new FormatException("Conversion from String to UInt16 is invalid");
            }
            break;
        default:
            abort();
            break;
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

UInt16 *SystemConvert_ToUInt16_Integral(void *arg, ...)
{
    UInt16 *ret = new Instance(UInt16, 1);
    char *checkConversion;
    unsigned long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            if((*(float *)arg) < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if((*(float *)arg) > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)(*(float *)arg));
            }
            break;
        case 1:
            if((*(double *)arg) < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if((*(double *)arg) > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)(*(double *)arg));
            }
            break;
        case 2:
            if((*(short *)arg) < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else if((*(short *)arg) > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)(*(short *)arg));
            }
            break;
        case 3:
            if((*(int *)arg) < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else if((*(int *)arg) > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)(*(int *)arg)); 
            }
            break;
        case 4:
            if((*(long *)arg) < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else if((*(long *)arg) > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)(*(long *)arg)); 
            }
            break;
        case 5:
            ret->UInt16(*(unsigned short *)arg);
            break;
        case 6:
            if((*(unsigned int *)arg) > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)(*(unsigned int *)arg)); 
            }
            break;
        case 7:
            if((*(unsigned long *)arg) > USHRT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt16((unsigned short)(*(unsigned long *)arg)); 
            }
            break;
        case 8:
            checkRet = strtoul(arg, &checkConversion, 16);
            if(!(*checkConversion))
            {
                if(checkRet > USHRT_MAX)
                {   
                    abort();
                    //throw new OverflowException();
                }
                else
                {
                    ret->UInt16(checkRet);
                }
            }
            else
            {
                abort();
                //throw new FormatException("Conversion from String to UInt16 is invalid");
            }
            break;
        default:
            abort();
            break;
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

UInt32 *SystemConvert_ToUInt32_Internal(void *arg, const char *T, SystemConvert * const this)
{
    UInt32 *ret;
    char integralType[9][20] = {{ "float" }, { "double" }, { "short" }, { "int" }, { "long" }, { "unsigned short" }, { "unsigned int" }, { "unsigned long" }, { "char pointer" }};
    /* Evaluar object */
    char classType[10][20] = {{ "Char" }, { "Float" }, { "Double" }, { "Int16" }, { "Int32" }, { "Int64" }, { "UInt16"}, { "UInt32" }, { "UInt64" }, { "String" }};

    if(isupper(T[0]) != 0)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(classType[i], T) == 0)
            {
                ret = this->ToUInt32_Class(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    else
    {   
        for(int i=0; i<9; i++)
        {
            if(strcmp(integralType[i], T) == 0)
            {
                ret = this->ToUInt32_Integral(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    /* Fallthrough */   
    return ((UInt32 *)0);
}

UInt32 *SystemConvert_ToUInt32_Class(void *arg, ...)
{
    UInt32 *ret = new Instance(UInt32, 1);
    char *checkConversion;
    unsigned long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->UInt32((unsigned int)((Char *)arg)->Get());
            break;
        case 1:
            if(((Float *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if(((Float *)arg)->Get() > UINT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt32((unsigned int)((Float *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            }
            break;
        case 2:
            if(((Double *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if(((Double *)arg)->Get() > UINT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt32((unsigned int)((Double *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            }
            break;
        case 3:
            if(((Int16 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else
            {
                ret->UInt32((unsigned int)((Int16 *)arg)->Get());
            }
            break;
        case 4:
            if(((Int32 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else
            {
                ret->UInt32((unsigned int)((Int32 *)arg)->Get()); 
            }
            break;
        case 5:
            if(((Int64 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else if(((Int64 *)arg)->Get() > UINT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt32((unsigned int)((Int64 *)arg)->Get()); 
            }
            break;
        case 6:
            ret->UInt32((unsigned int)((UInt16 *)arg)->Get());
            break;
        case 7:
            ret = (UInt32 *)arg;
            break;
        case 8:
            if(((UInt64 *)arg)->Get() > UINT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt32((unsigned int)((UInt64 *)arg)->Get()); 
            }
            break;
        case 9:
            checkRet = strtoul(((String *)arg)->Get(), &checkConversion, 16);
            if(!(*checkConversion))
            {
                if(checkRet > UINT_MAX)
                {
                    abort();
                    //throw new OverflowException();
                }
                else
                {
                    ret->UInt32(checkRet);
                }
            }
            else
            {
                abort();
                //throw new FormatException("Conversion from String to UInt32 is invalid");
            }
            break;
        default:
            abort();
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

UInt32 *SystemConvert_ToUInt32_Integral(void *arg, ...)
{
    UInt32 *ret = new Instance(UInt32, 1);
    char *checkConversion;
    unsigned long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            if((*(float *)arg) < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if((*(float *)arg) > UINT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt32((unsigned int)(*(float *)arg));
            }
            break;
        case 1:
            if((*(double *)arg) < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if((*(double *)arg) > UINT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt32((unsigned int)(*(double *)arg));
            }
            break;
        case 2:
            if((*(short *)arg) < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else if((*(short *)arg) > UINT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt32((unsigned int)(*(short *)arg));
            }
            break;
        case 3:
            ret->UInt32((unsigned int)(*(int *)arg)); 
            break;
        case 4:
            if((*(long *)arg) < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else if((*(long *)arg) > UINT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt32((unsigned int)(*(long *)arg)); 
            }
            break;
        case 5:
            ret->UInt32(*(unsigned short *)arg);
            break;
        case 6:
            ret->UInt32((*(unsigned int *)arg)); 
            break;
        case 7:
            if((*(unsigned long *)arg) > UINT_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt32((unsigned int)(*(unsigned long *)arg)); 
            }
            break;
        case 8:
            checkRet = strtoul(arg, &checkConversion, 16);
            if(!(*checkConversion))
            {
                if(checkRet > UINT_MAX)
                {
                    abort();
                    //throw new OverflowException();
                }
                else
                {
                    ret->UInt32(checkRet);
                }
            }
            else
            {
                abort();
                //throw new FormatException("Conversion from String to UInt32 is invalid");
            }
            break;
        default:
            abort();
            break;
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

UInt64 *SystemConvert_ToUInt64_Internal(void *arg, const char *T, SystemConvert * const this)
{
    UInt64 *ret;
    char integralType[9][20] = {{ "float" }, { "double" }, { "short" }, { "int" }, { "long" }, { "unsigned short" }, { "unsigned int" }, { "unsigned long" }, { "char pointer" }};
    /* Evaluar object */
    char classType[10][20] = {{ "Char" }, { "Float" }, { "Double" }, { "Int16" }, { "Int32" }, { "Int64" }, { "UInt16"}, { "UInt32" }, { "UInt64" }, { "String" }};

    if(isupper(T[0]) != 0)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(classType[i], T) == 0)
            {
                ret = this->ToUInt64_Class(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    else
    {   
        for(int i=0; i<9; i++)
        {
            if(strcmp(integralType[i], T) == 0)
            {
                ret = this->ToUInt64_Integral(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    /* Fallthrough */   
    return ((UInt64 *)0);
}

UInt64 *SystemConvert_ToUInt64_Class(void *arg, ...)
{
    UInt64 *ret = new Instance(UInt64, 1);
    char *checkConversion;
    unsigned long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            ret->UInt64((unsigned long)((Char *)arg)->Get());
            break;
        case 1:
            if(((Float *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if(((Float *)arg)->Get() > ULONG_MAX)
            {
                //throw new OverflowException();
            }
            else
            {
                ret->UInt64((unsigned long)((Float *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            }
            break;
        case 2:
            if(((Double *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if(((Double *)arg)->Get() > ULONG_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt64((unsigned long)((Double *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            }
            break;
        case 3:
            if(((Int16 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else
            {
                ret->UInt64((unsigned long)((Int16 *)arg)->Get());
            }
            break;
        case 4:
            if(((Int32 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else
            {
                ret->UInt64((unsigned long)((Int32 *)arg)->Get()); 
            }
            break;
        case 5:
            if(((Int64 *)arg)->Get() < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else
            {
                ret->UInt64((unsigned long)((Int64 *)arg)->Get());
            }
            break;
        case 6:
            ret->UInt64((unsigned long)((UInt16 *)arg)->Get());
            break;
        case 7:
            ret->UInt64((unsigned long)((UInt32 *)arg)->Get()); 
            break;
        case 8:
            ret->UInt64((unsigned long)((UInt64 *)arg)->Get()); 
            break;
        case 9:
            checkRet = strtoul(((String *)arg)->Get(), &checkConversion, 16);
            if(!(*checkConversion))
            {
                ret->UInt64(checkRet);
            }
            else
            {
                abort();
                //throw new FormatException("Conversion from String to UInt64 is invalid");
            }
            break;
        default:
            abort();
            break;
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

UInt64 *SystemConvert_ToUInt64_Integral(void *arg, ...)
{
    UInt64 *ret = new Instance(UInt64, 1);
    char *checkConversion;
    unsigned long checkRet;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            if((*(float *)arg) < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if((*(float *)arg) > ULONG_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt64((unsigned long)(*(float *)arg));
            }
            break;
        case 1:
            if((*(double *)arg) < 0)
            {
                abort();
                //throw new UnderflowException(); 
            }
            else if((*(double *)arg) > ULONG_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt64((unsigned long)(*(double *)arg));
            }
            break;
        case 2:
            if((*(short *)arg) < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else if((*(short *)arg) > ULONG_MAX)
            {
                abort();
                //throw new OverflowException();
            }
            else
            {
                ret->UInt64((unsigned long)(*(short *)arg));
            }
            break;
        case 3:
            ret->UInt64((unsigned long)(*(int *)arg)); 
            break;
        case 4:
            if((*(long *)arg) < 0)
            {
                abort();
                //throw new UnderflowException();
            }
            else
            {
                ret->UInt64((unsigned long)(*(long *)arg)); 
            }
            break;
        case 5:
            ret->UInt64((unsigned long)(*(unsigned short *)arg));
            break;
        case 6:
            ret->UInt64((unsigned long)(*(unsigned int *)arg)); 
            break;
        case 7:
            ret->UInt64((*(unsigned long *)arg)); 
            break;
        case 8:
            checkRet = strtoul(arg, &checkConversion, 16);
            if(!(*checkConversion))
            {
                ret->UInt64(checkRet);
            }
            else
            {
                abort();
                //throw new FormatException("Conversion from String to UInt64 is invalid");
            }
            break;
        default:
            abort();
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

String *SystemConvert_ToString_Internal(void *arg, const char *T, SystemConvert * const this)
{
    String *ret;
    char integralType[9][20] = {{ "float" }, { "double" }, { "short" }, { "int" }, { "long" }, { "unsigned short" }, { "unsigned int" }, { "unsigned long" }, { "char pointer" }};
    /* Evaluar object */
    char classType[10][20] = {{ "Char" }, { "Float" }, { "Double" }, { "Int16" }, { "Int32" }, { "Int64" }, { "UInt16"}, { "UInt32" }, { "UInt64" }, { "String" }};

    if(isupper(T[0]) != 0)
    {
        for(int i=0; i<10; i++)
        {
            if(strcmp(classType[i], T) == 0)
            {
                ret = this->ToString_Class(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    else
    {   
        for(int i=0; i<9; i++)
        {
            if(strcmp(integralType[i], T) == 0)
            {
                ret = this->ToString_Integral(arg, i);
                return ret;
            }
        }
        abort();
        //throw new InvalidCastException(); /* InvalidCastException */
    }
    /* Fallthrough */   
    return ((String *)0);
}

String *SystemConvert_ToString_Class(void *arg, ...)
{
    String *ret = new Instance(String, 1);
    char *__parse;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            sprintf(__parse, "%c", ((Char *)arg)->Get());
            ret->String(__parse);
            break;
        case 1:
            sprintf(__parse, "%f", ((Float *)arg)->Get());
            ret->String(__parse);
            break;
        case 2:
            sprintf(__parse, "%lf", ((Double *)arg)->Get()); /* Añadir Underflow y Overflow para double */
            ret->String(__parse);
            break;
        case 3:
            sprintf(__parse, "%d", ((Int16 *)arg)->Get());
            ret->String(__parse);
            break;
        case 4:
            sprintf(__parse, "%d", ((Int32 *)arg)->Get());
            ret->String(__parse);
            break;
        case 5:
            sprintf(__parse, "%ld", ((Int64 *)arg)->Get());
            break;
        case 6:
            sprintf(__parse, "%u", ((UInt16 *)arg)->Get());
            break;
        case 7:
            sprintf(__parse, "%u", ((UInt32 *)arg)->Get());
            break;
        case 8:
            sprintf(__parse, "%lu", ((UInt64 *)arg)->Get());
            break;
        case 9:
            ret = (String *)arg;
            break;
        default:
            abort();
            break;
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}

String *SystemConvert_ToString_Integral(void *arg, ...)
{
    String *ret = new Instance(String, 1);
    char *__parse;
    int typeID;
    va_list ap;

    va_start(ap, arg);
    typeID = va_arg(ap, int);
    switch(typeID)
    {
        case 0:
            sprintf(__parse, "%f", *(float *)arg);
            ret->String(__parse);
            break;
        case 1:
            sprintf(__parse, "%lf", *(double *)arg);
            ret->String(__parse);
            break;
        case 2:
            sprintf(__parse, "%d", *(short *)arg);
            ret->String(__parse);
            break;
        case 3:
            sprintf(__parse, "%d", *(int *)arg);
            ret->String(__parse);
            break;
        case 4:
            sprintf(__parse, "%ld", *(long *)arg);
            ret->String(__parse);
            break;
        case 5:
            sprintf(__parse, "%u", *(unsigned short *)arg);
            ret->String(__parse);
            break;
        case 6:
            sprintf(__parse, "%u", *(unsigned int *)arg);
            ret->String(__parse);
            break;
        case 7:
            sprintf(__parse, "%lu", *(unsigned long *)arg);
            ret->String(__parse);
            break;
        case 8:
            sprintf(__parse, "%s", (char *)arg);
            ret->String(__parse);
            break;
        default:
            abort();
            break;
            //throw new InvalidCastException();
    }
    va_end(ap);
    return ret;
}
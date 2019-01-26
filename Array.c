#include "Array.h"

/* Array */
typedef struct Array_Int16Private
{
    Int16 **array;
    size_t sizeArray;
} Array_Int16Private;

typedef struct Array_Int32Private
{
    Int32 **array;
    size_t sizeArray;
} Array_Int32Private;

typedef struct Array_Int64Private
{
    Int64 **array;
    size_t sizeArray;
} Array_Int64Private;

typedef struct Array_UInt16Private
{
    UInt16 **array;
    size_t sizeArray;
} Array_UInt16Private;

typedef struct Array_UInt32Private
{
    UInt32 **array;
    size_t sizeArray;
} Array_UInt32Private;

typedef struct Array_UInt64Private
{
    UInt64 **array;
    size_t sizeArray;
} Array_UInt64Private;

typedef struct Array_StringPrivate
{
    String **array;
    size_t sizeArray;
} Array_StringPrivate;

/* Constructors */
void *NArray_Int16(size_t);
void *NArray_Int32(size_t);
void *NArray_Int64(size_t);
void *NArray_UInt16(size_t);
void *NArray_UInt32(size_t);
void *NArray_UInt64(size_t);
void *NArray_String(size_t);
/* Int16 */
Int16 *Array_Int16_Get(int, Array_Int16 * const);
Array_Int16 *Array_Int16_Empty(Array_Int16 * const);
char *Array_Int16_GetType(Array_Int16 * const);
bool Array_Int16_Equals(void *, Array_Int16 * const);
Int16 *Array_Int16_IndexOf(const Int16 *, Array_Int16 * const);
void Array_Int16_Resize(Int32 *, Array_Int16 * const);
void Array_Int16_Reverse(Array_Int16 * const);
void Array_Int16_SetValue(Int16 *, Int32 *, Array_Int16 * const);
String *Array_Int16_ToString(Array_Int16 * const);
const int Array_Int16_Length(Array_Int16 * const);
/* Int32 */
Int32 *Array_Int32_Get(int, Array_Int32 * const);
Array_Int32 *Array_Int32_Empty(Array_Int32 * const);
char *Array_Int32_GetType(Array_Int32 * const);
bool Array_Int32_Equals(void *, Array_Int32 * const);
Int32 *Array_Int32_IndexOf(const Int32 *, Array_Int32 * const);
void Array_Int32_Resize(Int32 *, Array_Int32 * const);
void Array_Int32_Reverse(Array_Int32 * const);
void Array_Int32_SetValue(Int32 *, Int32 *, Array_Int32 * const);
String *Array_Int32_ToString(Array_Int32 * const);
const int Array_Int32_Length(Array_Int32 * const);
/* Int64 */
Int64 *Array_Int64_Get(int, Array_Int64 * const);
Array_Int64 *Array_Int64_Empty(Array_Int64 * const);
char *Array_Int64_GetType(Array_Int64 * const);
bool Array_Int64_Equals(void *, Array_Int64 * const);
Int64 *Array_Int64_IndexOf(const Int64 *, Array_Int64 * const);
void Array_Int64_Resize(Int32 *, Array_Int64 * const);
void Array_Int64_Reverse(Array_Int64 * const);
void Array_Int64_SetValue(Int64 *, Int32 *, Array_Int64 * const);
String *Array_Int64_ToString(Array_Int64 * const);
const int Array_Int64_Length(Array_Int64 * const);
/* UInt16 */
UInt16 *Array_UInt16_Get(int, Array_UInt16 * const);
Array_UInt16 *Array_UInt16_Empty(Array_UInt16 * const);
char *Array_UInt16_GetType(Array_UInt16 * const);
bool Array_UInt16_Equals(void *, Array_UInt16 * const);
UInt16 *Array_UInt16_IndexOf(const UInt16 *, Array_UInt16 * const);
void Array_UInt16_Resize(Int32 *, Array_UInt16 * const);
void Array_UInt16_Reverse(Array_UInt16 * const);
void Array_UInt16_SetValue(UInt16 *, Int32 *, Array_UInt16 * const);
String *Array_UInt16_ToString(Array_UInt16 * const);
const int Array_UInt16_Length(Array_UInt16 * const);
/* UInt32 */
UInt32 *Array_UInt32_Get(int, Array_UInt32 * const);
Array_UInt32 *Array_UInt32_Empty(Array_UInt32 * const);
char *Array_UInt32_GetType(Array_UInt32 * const);
bool Array_UInt32_Equals(void *, Array_UInt32 * const);
UInt32 *Array_UInt32_IndexOf(const UInt32 *, Array_UInt32 * const);
void Array_UInt32_Resize(Int32 *, Array_UInt32 * const);
void Array_UInt32_Reverse(Array_UInt32 * const);
void Array_UInt32_SetValue(UInt32 *, Int32 *, Array_UInt32 * const);
String *Array_UInt32_ToString(Array_UInt32 * const);
const int Array_UInt32_Length(Array_UInt32 * const);
/* UInt64 */
UInt64 *Array_UInt64_Get(int, Array_UInt64 * const);
Array_UInt64 *Array_UInt64_Empty(Array_UInt64 * const);
char *Array_UInt64_GetType(Array_UInt64 * const);
bool Array_UInt64_Equals(void *, Array_UInt64 * const);
UInt64 *Array_UInt64_IndexOf(const UInt64 *, Array_UInt64 * const);
void Array_UInt64_Resize(Int32 *, Array_UInt64 * const);
void Array_UInt64_Reverse(Array_UInt64 * const);
void Array_UInt64_SetValue(UInt64 *, Int32 *, Array_UInt64 * const);
String *Array_UInt64_ToString(Array_UInt64 * const);
const int Array_UInt64_Length(Array_UInt64 * const);
/* String */
String *Array_String_Get(int, Array_String * const);
Array_String *Array_String_Empty(Array_String * const);
char *Array_String_GetType(Array_String * const);
bool Array_String_Equals(void *, Array_String * const);
String *Array_String_IndexOf(const String *, Array_String * const);
void Array_String_Resize(Int32 *, Array_String * const);
void Array_String_Reverse(Array_String * const);
void Array_String_SetValue(String *, Int32 *, Array_String * const);
String *Array_String_ToString(Array_String * const);
const int Array_String_Length(Array_String * const);

/* Array */
void *NArray_Int16(size_t size)
{
    Array_Int16 *this = Object_create(sizeof(Array_Int16), 11);

    if(!size || size >= SIZE_MAX)
    {
        // throw new ArgumentException("The size is greater than SIZE_MAX limit");
        abort();
    }
    this->Array_Int16Private = GC_MALLOC(sizeof(Array_Int16Private));
    if(!this->Array_Int16Private)
    {
        GC_FREE(this);
        // throw new MemoryAccessException("No memory available to be allocated");
        abort();
    }
    else 
    {
        this->Array_Int16Private->array = GC_MALLOC(sizeof(Int16 *) * size); 
        if(!this->Array_Int16Private->array)
        {
            GC_FREE(this->Array_Int16Private);
            GC_FREE(this);
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();    
        }
        else 
        {
            for(int i=0; i<size; i++)
            {
                this->Array_Int16Private->array[i] = new Instance(Int16, 0);
                this->Array_Int16Private->array[i]->Int16();
            }
            this->Array_Int16Private->sizeArray = size;
            FUNCTION(Array_Int16, Get, 1);
            FUNCTION(Array_Int16, Empty, 0);
            FUNCTION(Array_Int16, GetType, 0);
            FUNCTION(Array_Int16, Equals, 1);
            FUNCTION(Array_Int16, IndexOf, 1);
            FUNCTION(Array_Int16, Resize, 1);
            FUNCTION(Array_Int16, Reverse, 0);
            FUNCTION(Array_Int16, SetValue, 2);
            FUNCTION(Array_Int16, ToString, 0);
            FUNCTION(Array_Int16, Length, 0);
            Object_prepare(&this->object);
            return this;
        }
    }
    return 0;
}

void *NArray_Int32(size_t size)
{
    Array_Int32 *this = Object_create(sizeof(Array_Int32), 11);

    if(!size || size >= SIZE_MAX)
    {
        // throw new ArgumentException("The size is greater than SIZE_MAX limit");
        abort();
    }
    this->Array_Int32Private = GC_MALLOC(sizeof(Array_Int32Private));
    if(!this->Array_Int32Private)
    {
        GC_FREE(this);
        // throw new MemoryAccessException("No memory available to be allocated");
        abort();
    }
    else 
    {
        this->Array_Int32Private->array = GC_MALLOC(sizeof(Int32 *) * size); 
        if(!this->Array_Int32Private->array)
        {
            GC_FREE(this->Array_Int32Private);
            GC_FREE(this);
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();    
        }
        else 
        {
            for(int i=0; i<size; i++)
            {
                this->Array_Int32Private->array[i] = new Instance(Int32, 0);
                this->Array_Int32Private->array[i]->Int32();
            }
            this->Array_Int32Private->sizeArray = size;
            FUNCTION(Array_Int32, Get, 1);
            FUNCTION(Array_Int32, Empty, 0);
            FUNCTION(Array_Int32, GetType, 0);
            FUNCTION(Array_Int32, Equals, 1);
            FUNCTION(Array_Int32, IndexOf, 1);
            FUNCTION(Array_Int32, Resize, 1);
            FUNCTION(Array_Int32, Reverse, 0);
            FUNCTION(Array_Int32, SetValue, 2);
            FUNCTION(Array_Int32, ToString, 0);
            FUNCTION(Array_Int32, Length, 0);
            Object_prepare(&this->object);
            return this;
        }
    }
    return 0;
}

void *NArray_Int64(size_t size)
{
    Array_Int64 *this = Object_create(sizeof(Array_Int64), 11);

    if(!size || size >= SIZE_MAX)
    {
        // throw new ArgumentException("The size is greater than SIZE_MAX limit");
        abort();
    }
    this->Array_Int64Private = GC_MALLOC(sizeof(Array_Int64Private));
    if(!this->Array_Int64Private)
    {
        GC_FREE(this);
        // throw new MemoryAccessException("No memory available to be allocated");
        abort();
    }
    else 
    {
        this->Array_Int64Private->array = GC_MALLOC(sizeof(Int64 *) * size); 
        if(!this->Array_Int64Private->array)
        {
            GC_FREE(this->Array_Int64Private);
            GC_FREE(this);
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();    
        }
        else 
        {
            for(int i=0; i<size; i++)
            {
                this->Array_Int64Private->array[i] = new Instance(Int64, 0);
                this->Array_Int64Private->array[i]->Int64();
            }
            this->Array_Int64Private->sizeArray = size;
            FUNCTION(Array_Int64, Get, 1);
            FUNCTION(Array_Int64, Empty, 0);
            FUNCTION(Array_Int64, GetType, 0);
            FUNCTION(Array_Int64, Equals, 1);
            FUNCTION(Array_Int64, IndexOf, 1);
            FUNCTION(Array_Int64, Resize, 1);
            FUNCTION(Array_Int64, Reverse, 0);
            FUNCTION(Array_Int64, SetValue, 2);
            FUNCTION(Array_Int64, ToString, 0);
            FUNCTION(Array_Int64, Length, 0);
            Object_prepare(&this->object);
            return this;
        }
    }
    return 0;
}

void *NArray_UInt16(size_t size)
{
    Array_UInt16 *this = Object_create(sizeof(Array_UInt16), 11);

    if(!size || size >= SIZE_MAX)
    {
        // throw new ArgumentException("The size is greater than SIZE_MAX limit");
        abort();
    }
    this->Array_UInt16Private = GC_MALLOC(sizeof(Array_UInt16Private));
    if(!this->Array_UInt16Private)
    {
        GC_FREE(this);
        // throw new MemoryAccessException("No memory available to be allocated");
        abort();
    }
    else 
    {
        this->Array_UInt16Private->array = GC_MALLOC(sizeof(UInt16 *) * size); 
        if(!this->Array_UInt16Private->array)
        {
            GC_FREE(this->Array_UInt16Private);
            GC_FREE(this);
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();    
        }
        else 
        {
            for(int i=0; i<size; i++)
            {
                this->Array_UInt16Private->array[i] = new Instance(UInt16, 0);
                this->Array_UInt16Private->array[i]->UInt16();
            }
            this->Array_UInt16Private->sizeArray = size;
            FUNCTION(Array_UInt16, Get, 1);
            FUNCTION(Array_UInt16, Empty, 0);
            FUNCTION(Array_UInt16, GetType, 0);
            FUNCTION(Array_UInt16, Equals, 1);
            FUNCTION(Array_UInt16, IndexOf, 1);
            FUNCTION(Array_UInt16, Resize, 1);
            FUNCTION(Array_UInt16, Reverse, 0);
            FUNCTION(Array_UInt16, SetValue, 2);
            FUNCTION(Array_UInt16, ToString, 0);
            FUNCTION(Array_UInt16, Length, 0);
            Object_prepare(&this->object);
            return this;
        }
    }
    return 0;
}

void *NArray_UInt32(size_t size)
{
    Array_UInt32 *this = Object_create(sizeof(Array_UInt32), 11);

    if(!size || size >= SIZE_MAX)
    {
        // throw new ArgumentException("The size is greater than SIZE_MAX limit");
        abort();
    }
    this->Array_UInt32Private = GC_MALLOC(sizeof(Array_UInt32Private));
    if(!this->Array_UInt32Private)
    {
        GC_FREE(this);
        // throw new MemoryAccessException("No memory available to be allocated");
        abort();
    }
    else 
    {
        this->Array_UInt32Private->array = GC_MALLOC(sizeof(UInt32 *) * size); 
        if(!this->Array_UInt32Private->array)
        {
            GC_FREE(this->Array_UInt32Private);
            GC_FREE(this);
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();    
        }
        else 
        {
            for(int i=0; i<size; i++)
            {
                this->Array_UInt32Private->array[i] = new Instance(UInt32, 0);
                this->Array_UInt32Private->array[i]->UInt32();
            }
            this->Array_UInt32Private->sizeArray = size;
            FUNCTION(Array_UInt32, Get, 1);
            FUNCTION(Array_UInt32, Empty, 0);
            FUNCTION(Array_UInt32, GetType, 0);
            FUNCTION(Array_UInt32, Equals, 1);
            FUNCTION(Array_UInt32, IndexOf, 1);
            FUNCTION(Array_UInt32, Resize, 1);
            FUNCTION(Array_UInt32, Reverse, 0);
            FUNCTION(Array_UInt32, SetValue, 2);
            FUNCTION(Array_UInt32, ToString, 0);
            FUNCTION(Array_UInt32, Length, 0);
            Object_prepare(&this->object);
            return this;
        }
    }
    return 0;
}

void *NArray_UInt64(size_t size)
{
    Array_UInt64 *this = Object_create(sizeof(Array_UInt64), 11);

    if(!size || size >= SIZE_MAX)
    {
        // throw new ArgumentException("The size is greater than SIZE_MAX limit");
        abort();
    }
    this->Array_UInt64Private = GC_MALLOC(sizeof(Array_UInt64Private));
    if(!this->Array_UInt64Private)
    {
        GC_FREE(this);
        // throw new MemoryAccessException("No memory available to be allocated");
        abort();
    }
    else 
    {
        this->Array_UInt64Private->array = GC_MALLOC(sizeof(UInt64 *) * size); 
        if(!this->Array_UInt64Private->array)
        {
            GC_FREE(this->Array_UInt64Private);
            GC_FREE(this);
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();    
        }
        else 
        {
            for(int i=0; i<size; i++)
            {
                this->Array_UInt64Private->array[i] = new Instance(UInt64, 0);
                this->Array_UInt64Private->array[i]->UInt64();
            }
            this->Array_UInt64Private->sizeArray = size;
            FUNCTION(Array_UInt64, Get, 1);
            FUNCTION(Array_UInt64, Empty, 0);
            FUNCTION(Array_UInt64, GetType, 0);
            FUNCTION(Array_UInt64, Equals, 1);
            FUNCTION(Array_UInt64, IndexOf, 1);
            FUNCTION(Array_UInt64, Resize, 1);
            FUNCTION(Array_UInt64, Reverse, 0);
            FUNCTION(Array_UInt64, SetValue, 2);
            FUNCTION(Array_UInt64, ToString, 0);
            FUNCTION(Array_UInt64, Length, 0);
            Object_prepare(&this->object);
            return this;
        }
    }
    return 0;
}

void *NArray_String(size_t size)
{
    Array_String *this = Object_create(sizeof(Array_String), 11);

    if(!size || size >= SIZE_MAX)
    {
        // throw new ArgumentException("The size is greater than SIZE_MAX limit");
        abort();
    }
    this->Array_StringPrivate = GC_MALLOC(sizeof(Array_StringPrivate));
    if(!this->Array_StringPrivate)
    {
        GC_FREE(this);
        // throw new MemoryAccessException("No memory available to be allocated");
        abort();
    }
    else 
    {
        this->Array_StringPrivate->array = GC_MALLOC(sizeof(String *) * size); 
        if(!this->Array_StringPrivate->array)
        {
            GC_FREE(this->Array_StringPrivate);
            GC_FREE(this);
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();    
        }
        else 
        {
            for(int i=0; i<size; i++)
            {
                this->Array_StringPrivate->array[i] = new Instance(String, 0);
                this->Array_StringPrivate->array[i]->String();
            }
            this->Array_StringPrivate->sizeArray = size;
            FUNCTION(Array_String, Get, 1);
            FUNCTION(Array_String, Empty, 0);
            FUNCTION(Array_String, GetType, 0);
            FUNCTION(Array_String, Equals, 1);
            FUNCTION(Array_String, IndexOf, 1);
            FUNCTION(Array_String, Resize, 1);
            FUNCTION(Array_String, Reverse, 0);
            FUNCTION(Array_String, SetValue, 2);
            FUNCTION(Array_String, ToString, 0);
            FUNCTION(Array_String, Length, 0);
            Object_prepare(&this->object);
            return this;
        }
    }
    return 0;
}

/* Int16 */
Int16 *Array_Int16_Get(int index, Array_Int16 * const this)
{
    return this->Array_Int16Private->array[index];
}

Array_Int16 *Array_Int16_Empty(Array_Int16 * const this)
{
    static int i = 0;

    while(i < this->Array_Int16Private->sizeArray)
    {
        this->Array_Int16Private->array[i]->Int16(); /* Experimental */
        i++;
    }
    i = 0;
    return this;
}

char *Array_Int16_GetType(Array_Int16 * const this)
{
    return "Array(Int16)";
}

bool Array_Int16_Equals(void *object, Array_Int16 * const this)
{
    return (object == (void *)this) ? true : false;
}

Int16 *Array_Int16_IndexOf(const Int16 *__val, Array_Int16 * const this)
{
    Int16 *ret = new Instance(Int16, 1);

    for(int i=0; i<this->Array_Int16Private->sizeArray; i++)
    {
        if(this->Array_Int16Private->array[i]->Get() == __val->Get())
        {
            ret->Int16(i);
        }
    }
    return ret;
}

void Array_Int16_Resize(Int32 *__s, Array_Int16 * const this)
{
    Int16 **__t;

    if(__s->Get() < 0 || __s->Get() == 0 || __s->Get() > SHRT_MAX)
    {
        // throw new ArgumentException();
        abort();
    }
    else if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        __t = GC_REALLOC(this->Array_Int16Private->array, sizeof(Int16 *) * __s->Get());
        if(__t)
        {
            this->Array_Int16Private->array = __t;
            for(int i=this->Array_Int16Private->sizeArray; i<__s->Get(); i++)
            {
                this->Array_Int16Private->array[i] = new Instance(Int16, 0);
                this->Array_Int16Private->array[i]->Int16();
            }
            this->Array_Int16Private->sizeArray = __s->Get();
        }
        else 
        {
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();
        }
    }
    return;
}

void Array_Int16_Reverse(Array_Int16 * const this)
{
    Int16 *__t;
    int j = this->Array_Int16Private->sizeArray - 1;

    if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_Int16Private->array) 
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        for(int i=0; i<this->Array_Int16Private->sizeArray; i++, j--)
        {
            __t = this->Array_Int16Private->array[i];
            this->Array_Int16Private->array[j] = __t;
        }
    }
    return;
}

void Array_Int16_SetValue(Int16 *__obj, Int32 *__index, Array_Int16 * const this)
{
    if((!__obj) || (!__index) || (!this))
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_Int16Private->array)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        if(__obj->Get() > SHRT_MAX || __index->Get() > this->Array_Int16Private->sizeArray)
        {
            // throw new ArgumentException();
            abort();
        }
        this->Array_Int16Private->array[__index->Get()] = __obj;
    }
    return;
}

String *Array_Int16_ToString(Array_Int16 * const this)
{
    static char __ccat[256][256];
    String *ret = new Instance(String, 0);

    ret->String();
    for(int i=0; i<this->Array_Int16Private->sizeArray; i++)
    {
        (void)sprintf(__ccat[i], "%d ", this->Array_Int16Private->array[i]->Get());
        strcat(ret->Get(), __ccat[i]);
    }
    return ret;
}

const int Array_Int16_Length(Array_Int16 * const this)
{
    return this->Array_Int16Private->sizeArray;
}

/* Int32 */
Int32 *Array_Int32_Get(int index, Array_Int32 * const this)
{
    return this->Array_Int32Private->array[index];
}

Array_Int32 *Array_Int32_Empty(Array_Int32 * const this)
{
    static int i = 0;

    while(i < this->Array_Int32Private->sizeArray)
    {
        this->Array_Int32Private->array[i]->Int32(); /* Experimental */
        i++;
    }
    i = 0;
    return this;
}

char *Array_Int32_GetType(Array_Int32 * const this)
{
    return "Array(Int32)";
}

bool Array_Int32_Equals(void *object, Array_Int32 * const this)
{
    return (object == (void *)this) ? true : false;
}

Int32 *Array_Int32_IndexOf(const Int32 *__val, Array_Int32 * const this)
{
    Int32 *ret = new Instance(Int32, 1);

    for(int i=0; i<this->Array_Int32Private->sizeArray; i++)
    {
        if(this->Array_Int32Private->array[i]->Get() == __val->Get())
        {
            ret->Int32(i);
        }
    }
    return ret;
}

void Array_Int32_Resize(Int32 *__s, Array_Int32 * const this)
{
    Int32 **__t;

    if(__s->Get() < 0 || __s->Get() == 0 || __s->Get() > INT_MAX)
    {
        // throw new ArgumentException();
        abort();
    }
    else if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        __t = GC_REALLOC(this->Array_Int32Private->array, sizeof(Int32 *) * __s->Get());
        if(__t)
        {
            this->Array_Int32Private->array = __t;
            for(int i=this->Array_Int32Private->sizeArray; i<__s->Get(); i++)
            {
                this->Array_Int32Private->array[i] = new Instance(Int32, 0);
                this->Array_Int32Private->array[i]->Int32();
            }
            this->Array_Int32Private->sizeArray = __s->Get();
        }
        else 
        {
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();
        }
    }
    return;
}

void Array_Int32_Reverse(Array_Int32 * const this)
{
    Int32 *__t;
    int j = this->Array_Int32Private->sizeArray - 1;

    if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_Int32Private->array) 
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        for(int i=0; i<this->Array_Int32Private->sizeArray; i++, j--)
        {
            __t = this->Array_Int32Private->array[i];
            this->Array_Int32Private->array[j] = __t;
        }
    }
    return;
}

void Array_Int32_SetValue(Int32 *__obj, Int32 *__index, Array_Int32 * const this)
{
    if((!__obj) || (!__index) || (!this))
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_Int32Private->array)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        if(__obj->Get() > INT_MAX || __index->Get() > this->Array_Int32Private->sizeArray)
        {
            // throw new ArgumentException();
            abort();
        }
        this->Array_Int32Private->array[__index->Get()] = __obj;
    }
    return;
}

String *Array_Int32_ToString(Array_Int32 * const this)
{
    static char __ccat[256][256];
    String *ret = new Instance(String, 0);

    ret->String();
    for(int i=0; i<this->Array_Int32Private->sizeArray; i++)
    {
        (void)sprintf(__ccat[i], "%d ", this->Array_Int32Private->array[i]->Get());
        strcat(ret->Get(), __ccat[i]);
    }
    return ret;
}

const int Array_Int32_Length(Array_Int32 * const this)
{
    return this->Array_Int32Private->sizeArray;
}

/* Int64 */
Int64 *Array_Int64_Get(int index, Array_Int64 * const this)
{
    return this->Array_Int64Private->array[index];
}

Array_Int64 *Array_Int64_Empty(Array_Int64 * const this)
{
    static int i = 0;

    while(i < this->Array_Int64Private->sizeArray)
    {
        this->Array_Int64Private->array[i]->Int64(); /* Experimental */
        i++;
    }
    i = 0;
    return this;
}

char *Array_Int64_GetType(Array_Int64 * const this)
{
    return "Array(Int64)";
}

bool Array_Int64_Equals(void *object, Array_Int64 * const this)
{
    return (object == (void *)this) ? true : false;
}

Int64 *Array_Int64_IndexOf(const Int64 *__val, Array_Int64 * const this)
{
    Int64 *ret = new Instance(Int64, 1);

    for(int i=0; i<this->Array_Int64Private->sizeArray; i++)
    {
        if(this->Array_Int64Private->array[i]->Get() == __val->Get())
        {
            ret->Int64(i);
        }
    }
    return ret;
}

void Array_Int64_Resize(Int32 *__s, Array_Int64 * const this)
{
    Int64 **__t;

    if(__s->Get() < 0 || __s->Get() == 0 || __s->Get() > LONG_MAX)
    {
        // throw new ArgumentException();
        abort();
    }
    else if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        __t = GC_REALLOC(this->Array_Int64Private->array, sizeof(Int64 *) * __s->Get());
        if(__t)
        {
            this->Array_Int64Private->array = __t;
            for(int i=this->Array_Int64Private->sizeArray; i<__s->Get(); i++)
            {
                this->Array_Int64Private->array[i] = new Instance(Int64, 0);
                this->Array_Int64Private->array[i]->Int64();
            }
            this->Array_Int64Private->sizeArray = __s->Get();
        }
        else 
        {
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();
        }
    }
    return;
}

void Array_Int64_Reverse(Array_Int64 * const this)
{
    Int64 *__t;
    int j = this->Array_Int64Private->sizeArray - 1;

    if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_Int64Private->array) 
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        for(int i=0; i<this->Array_Int64Private->sizeArray; i++, j--)
        {
            __t = this->Array_Int64Private->array[i];
            this->Array_Int64Private->array[j] = __t;
        }
    }
    return;
}

void Array_Int64_SetValue(Int64 *__obj, Int32 *__index, Array_Int64 * const this)
{
    if((!__obj) || (!__index) || (!this))
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_Int64Private->array)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        if(__obj->Get() > LONG_MAX || __index->Get() > this->Array_Int64Private->sizeArray)
        {
            // throw new ArgumentException();
            abort();
        }
        this->Array_Int64Private->array[__index->Get()] = __obj;
    }
    return;
}

String *Array_Int64_ToString(Array_Int64 * const this)
{
    static char __ccat[256][256];
    String *ret = new Instance(String, 0);

    ret->String();
    for(int i=0; i<this->Array_Int64Private->sizeArray; i++)
    {
        (void)sprintf(__ccat[i], "%ld ", this->Array_Int64Private->array[i]->Get());
        strcat(ret->Get(), __ccat[i]);
    }
    return ret;
}

const int Array_Int64_Length(Array_Int64 * const this)
{
    return this->Array_Int64Private->sizeArray;
}

/* UInt16 */
UInt16 *Array_UInt16_Get(int index, Array_UInt16 * const this)
{
    return this->Array_UInt16Private->array[index];
}

Array_UInt16 *Array_UInt16_Empty(Array_UInt16 * const this)
{
    static int i = 0;

    while(i < this->Array_UInt16Private->sizeArray)
    {
        this->Array_UInt16Private->array[i]->UInt16(); /* Experimental */
        i++;
    }
    i = 0;
    return this;
}

char *Array_UInt16_GetType(Array_UInt16 * const this)
{
    return "Array(UInt16)";
}

bool Array_UInt16_Equals(void *object, Array_UInt16 * const this)
{
    return (object == (void *)this) ? true : false;
}

UInt16 *Array_UInt16_IndexOf(const UInt16 *__val, Array_UInt16 * const this)
{
    UInt16 *ret = new Instance(UInt16, 1);

    for(int i=0; i<this->Array_UInt16Private->sizeArray; i++)
    {
        if(this->Array_UInt16Private->array[i]->Get() == __val->Get())
        {
            ret->UInt16(i);
        }
    }
    return ret;
}

void Array_UInt16_Resize(Int32 *__s, Array_UInt16 * const this)
{
    UInt16 **__t;

    if(__s->Get() < 0 || __s->Get() == 0 || __s->Get() > USHRT_MAX)
    {
        // throw new ArgumentException();
        abort();
    }
    else if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        __t = GC_REALLOC(this->Array_UInt16Private->array, sizeof(UInt16 *) * __s->Get());
        if(__t)
        {
            this->Array_UInt16Private->array = __t;
            for(int i=this->Array_UInt16Private->sizeArray; i<__s->Get(); i++)
            {
                this->Array_UInt16Private->array[i] = new Instance(UInt16, 0);
                this->Array_UInt16Private->array[i]->UInt16();
            }
            this->Array_UInt16Private->sizeArray = __s->Get();
        }
        else 
        {
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();
        }
    }
    return;
}

void Array_UInt16_Reverse(Array_UInt16 * const this)
{
    UInt16 *__t;
    int j = this->Array_UInt16Private->sizeArray - 1;

    if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_UInt16Private->array) 
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        for(int i=0; i<this->Array_UInt16Private->sizeArray; i++, j--)
        {
            __t = this->Array_UInt16Private->array[i];
            this->Array_UInt16Private->array[j] = __t;
        }
    }
    return;
}

void Array_UInt16_SetValue(UInt16 *__obj, Int32 *__index, Array_UInt16 * const this)
{
    if((!__obj) || (!__index) || (!this))
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_UInt16Private->array)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        if(__obj->Get() > USHRT_MAX || __index->Get() > this->Array_UInt16Private->sizeArray)
        {
            // throw new ArgumentException();
            abort();
        }
        this->Array_UInt16Private->array[__index->Get()] = __obj;
    }
    return;
}

String *Array_UInt16_ToString(Array_UInt16 * const this)
{
    static char __ccat[256][256];
    String *ret = new Instance(String, 0);

    ret->String();
    for(int i=0; i<this->Array_UInt16Private->sizeArray; i++)
    {
        (void)sprintf(__ccat[i], "%d ", this->Array_UInt16Private->array[i]->Get());
        strcat(ret->Get(), __ccat[i]);
    }
    return ret;
}

const int Array_UInt16_Length(Array_UInt16 * const this)
{
    return this->Array_UInt16Private->sizeArray;
}

/* UInt32 */
UInt32 *Array_UInt32_Get(int index, Array_UInt32 * const this)
{
    return this->Array_UInt32Private->array[index];
}

Array_UInt32 *Array_UInt32_Empty(Array_UInt32 * const this)
{
    static int i = 0;

    while(i < this->Array_UInt32Private->sizeArray)
    {
        this->Array_UInt32Private->array[i]->UInt32(); /* Experimental */
        i++;
    }
    i = 0;
    return this;
}

char *Array_UInt32_GetType(Array_UInt32 * const this)
{
    return "Array(UInt32)";
}

bool Array_UInt32_Equals(void *object, Array_UInt32 * const this)
{
    return (object == (void *)this) ? true : false;
}

UInt32 *Array_UInt32_IndexOf(const UInt32 *__val, Array_UInt32 * const this)
{
    UInt32 *ret = new Instance(UInt32, 1);

    for(int i=0; i<this->Array_UInt32Private->sizeArray; i++)
    {
        if(this->Array_UInt32Private->array[i]->Get() == __val->Get())
        {
            ret->UInt32(i);
        }
    }
    return ret;
}

void Array_UInt32_Resize(Int32 *__s, Array_UInt32 * const this)
{
    UInt32 **__t;

    if(__s->Get() < 0 || __s->Get() == 0 || __s->Get() > UINT_MAX)
    {
        // throw new ArgumentException();
        abort();
    }
    else if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        __t = GC_REALLOC(this->Array_UInt32Private->array, sizeof(UInt32 *) * __s->Get());
        if(__t)
        {
            this->Array_UInt32Private->array = __t;
            for(int i=this->Array_UInt32Private->sizeArray; i<__s->Get(); i++)
            {
                this->Array_UInt32Private->array[i] = new Instance(UInt32, 0);
                this->Array_UInt32Private->array[i]->UInt32();
            }
            this->Array_UInt32Private->sizeArray = __s->Get();
        }
        else 
        {
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();
        }
    }
    return;
}

void Array_UInt32_Reverse(Array_UInt32 * const this)
{
    UInt32 *__t;
    int j = this->Array_UInt32Private->sizeArray - 1;

    if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_UInt32Private->array) 
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        for(int i=0; i<this->Array_UInt32Private->sizeArray; i++, j--)
        {
            __t = this->Array_UInt32Private->array[i];
            this->Array_UInt32Private->array[j] = __t;
        }
    }
    return;
}

void Array_UInt32_SetValue(UInt32 *__obj, Int32 *__index, Array_UInt32 * const this)
{
    if((!__obj) || (!__index) || (!this))
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_UInt32Private->array)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        if(__obj->Get() > UINT_MAX || __index->Get() > this->Array_UInt32Private->sizeArray)
        {
            // throw new ArgumentException();
            abort();
        }
        this->Array_UInt32Private->array[__index->Get()] = __obj;
    }
    return;
}

String *Array_UInt32_ToString(Array_UInt32 * const this)
{
    static char __ccat[256][256];
    String *ret = new Instance(String, 0);

    ret->String();
    for(int i=0; i<this->Array_UInt32Private->sizeArray; i++)
    {
        (void)sprintf(__ccat[i], "%d ", this->Array_UInt32Private->array[i]->Get());
        strcat(ret->Get(), __ccat[i]);
    }
    return ret;
}

const int Array_UInt32_Length(Array_UInt32 * const this)
{
    return this->Array_UInt32Private->sizeArray;
}

/* UInt64 */
UInt64 *Array_UInt64_Get(int index, Array_UInt64 * const this)
{
    return this->Array_UInt64Private->array[index];
}

Array_UInt64 *Array_UInt64_Empty(Array_UInt64 * const this)
{
    static int i = 0;

    while(i < this->Array_UInt64Private->sizeArray)
    {
        this->Array_UInt64Private->array[i]->UInt64(); /* Experimental */
        i++;
    }
    i = 0;
    return this;
}

char *Array_UInt64_GetType(Array_UInt64 * const this)
{
    return "Array(UInt64)";
}

bool Array_UInt64_Equals(void *object, Array_UInt64 * const this)
{
    return (object == (void *)this) ? true : false;
}

UInt64 *Array_UInt64_IndexOf(const UInt64 *__val, Array_UInt64 * const this)
{
    UInt64 *ret = new Instance(UInt64, 1);

    for(int i=0; i<this->Array_UInt64Private->sizeArray; i++)
    {
        if(this->Array_UInt64Private->array[i]->Get() == __val->Get())
        {
            ret->UInt64(i);
        }
    }
    return ret;
}

void Array_UInt64_Resize(Int32 *__s, Array_UInt64 * const this)
{
    UInt64 **__t;

    if(__s->Get() < 0 || __s->Get() == 0 || __s->Get() > ULONG_MAX)
    {
        // throw new ArgumentException();
        abort();
    }
    else if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        __t = GC_REALLOC(this->Array_UInt64Private->array, sizeof(UInt64 *) * __s->Get());
        if(__t)
        {
            this->Array_UInt64Private->array = __t;
            for(int i=this->Array_UInt64Private->sizeArray; i<__s->Get(); i++)
            {
                this->Array_UInt64Private->array[i] = new Instance(UInt64, 0);
                this->Array_UInt64Private->array[i]->UInt64();
            }
            this->Array_UInt64Private->sizeArray = __s->Get();
        }
        else 
        {
            // throw new MemoryAccessException("No memory available to be allocated");
            abort();
        }
    }
    return;
}

void Array_UInt64_Reverse(Array_UInt64 * const this)
{
    UInt64 *__t;
    int j = this->Array_UInt64Private->sizeArray - 1;

    if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_UInt64Private->array) 
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        for(int i=0; i<this->Array_UInt64Private->sizeArray; i++, j--)
        {
            __t = this->Array_UInt64Private->array[i];
            this->Array_UInt64Private->array[j] = __t;
        }
    }
    return;
}

void Array_UInt64_SetValue(UInt64 *__obj, Int32 *__index, Array_UInt64 * const this)
{
    if((!__obj) || (!__index) || (!this))
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_UInt64Private->array)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        if(__obj->Get() > ULONG_MAX || __index->Get() > this->Array_UInt64Private->sizeArray)
        {
            // throw new ArgumentException();
            abort();
        }
        this->Array_UInt64Private->array[__index->Get()] = __obj;
    }
    return;
}

String *Array_UInt64_ToString(Array_UInt64 * const this)
{
    static char __ccat[256][256];
    String *ret = new Instance(String, 0);

    ret->String();
    for(int i=0; i<this->Array_UInt64Private->sizeArray; i++)
    {
        (void)sprintf(__ccat[i], "%lu ", this->Array_UInt64Private->array[i]->Get());
        strcat(ret->Get(), __ccat[i]);
    }
    return ret;
}

const int Array_UInt64_Length(Array_UInt64 * const this)
{
    return this->Array_UInt64Private->sizeArray;
}

/* String */
String *Array_String_Get(int index, Array_String * const this)
{
    return this->Array_StringPrivate->array[index];
}

Array_String *Array_String_Empty(Array_String * const this)
{
    static int i = 0;

    while(i < this->Array_StringPrivate->sizeArray)
    {
        this->Array_StringPrivate->array[i]->String(); /* Experimental */
        i++;
    }
    i = 0;
    return this;
}

char *Array_String_GetType(Array_String * const this)
{
    return "Array(String)";
}

bool Array_String_Equals(void *object, Array_String * const this)
{
    return (object == (void *)this) ? true : false;
}

String *Array_String_IndexOf(const String *__val, Array_String * const this)
{
    String *ret = new Instance(String, 1);
    char __ptr[25];

    for(int i=0; i<this->Array_StringPrivate->sizeArray; i++)
    {
        if(!strcmp(this->Array_StringPrivate->array[i]->Get(), __val->Get()))
        {
            (void)sprintf(__ptr, "%d", i);
            ret->String(__ptr);
            break;
        }
    }
    return ret;
}

void Array_String_Resize(Int32 *__s, Array_String * const this)
{
    String **__t;

    if(__s->Get() < 0 || __s->Get() == 0 || __s->Get() > INT_MAX)
    {
        // throw new ArgumentException();
        abort();
    }
    else if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        __t = GC_REALLOC(this->Array_StringPrivate->array, sizeof(String *) * __s->Get());
        if(__t)
        {
            this->Array_StringPrivate->array = __t;
            for(int i=this->Array_StringPrivate->sizeArray; i<__s->Get(); i++)
            {
                this->Array_StringPrivate->array[i] = new Instance(String, 0);
                this->Array_StringPrivate->array[i]->String();
            }
            this->Array_StringPrivate->sizeArray = __s->Get();
        }
        else
        {
            // throw new MemoryAccessException("No available memory to be allocated"); 
            abort();
        }
    }
    return;
}

void Array_String_Reverse(Array_String * const this)
{
    String *__t;
    int j = this->Array_StringPrivate->sizeArray - 1;

    if(!this)
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(!this->Array_StringPrivate->array) 
    {
        // throw new NullArgumentException();
        abort();
    }
    else 
    {
        for(int i=0; i<this->Array_StringPrivate->sizeArray; i++, j--)
        {
            __t = this->Array_StringPrivate->array[i];
            this->Array_StringPrivate->array[j] = __t;
        }
    }
    return;
}

void Array_String_SetValue(String *__obj, Int32 *__index, Array_String * const this)
{
    if((!__obj) || (!__index) || (!this))
    {
        // throw new NullArgumentException();
        abort();
    }
    else if(__index->Get() < 0)
    {
        // throw new ArgumentException("Index given to method is less than zero");
        abort();
    }
    else if(!this->Array_StringPrivate->array)
    {
        //throw new NullArgumentException();
        abort();
    }
    else 
    {
        if((!__obj->Get()) || (__index->Get() > this->Array_StringPrivate->sizeArray))
        {
            // throw new ArgumentException();
            abort();
        }
        this->Array_StringPrivate->array[__index->Get()] = __obj;
    }
    return;
}

String *Array_String_ToString(Array_String * const this)
{
    static char ccat[256][256];
    String *ret = new Instance(String, 1);

    for(int i=0; i<this->Array_StringPrivate->sizeArray; i++)
    {
        (void)sprintf(ccat[i], "%s ", this->Array_StringPrivate->array[i]->Get());
        if(i == 0)
        {
            ret->String(ccat[0]);
        }
        else
        {
            ret->Concatenate(ccat[i]);
        }
    }
    return ret;
}

const int Array_String_Length(Array_String * const this)
{
    return this->Array_StringPrivate->sizeArray;
}
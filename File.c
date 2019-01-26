#include "File.h"

typedef struct FileStreamPrivate
{
    Object object;
    FILE *stream;
    FileMode __mode;
    void (*Set)(const FileStream *, FileMode);
} FileStreamPrivate;

/* Public */
FILE *FileStream_Get(FileStream * const);
void FileStream_StreamOpen(struct string *, FileMode, FileStream * const);
void FileStream_StreamClose(FileStream * const);
void FileStream_FlushStream(FileStream * const);
char FileStream_GetChar(FileStream * const);
struct string *FileStream_GetString(struct string *, size_t, FileStream * const);
void FileStream_PutChar(char, FileStream * const);
void FileStream_PutString(struct string *, FileStream * const);
/* Ctor */
void *FileStream_File0(FileStream *);
void *FileStream_File1(FileStream *, FileMode, FileStream *);
/* Private */
static void FileStreamPrivate_Set(const FileStream *, FileMode, FileStreamPrivate * const);

FILE *FileStream_Get(FileStream * const this)
{
    return this->FileStreamPrivate->stream;
}

void FileStream_StreamOpen(struct string *__name, FileMode __m, FileStream * const this)
{
    if(!__name->Get())
    {
        // throw new NullArgumentException("No string assignment was given to a this reference");
        abort();
    }
    switch(__m)
    {
        case Read:
            this->FileStreamPrivate->stream = fopen(__name->Get(), "r");
            if(!this->Get())
            {
                // throw new FileNotFoundException("Invalid path or file name to be processed");
                abort();
            }
            else
            {
                this->FileStreamPrivate->__mode = Read;
            }
            break;
        case Write:
            this->FileStreamPrivate->stream = fopen(__name->Get(), "w");
            if(!this->Get())
            {
                // throw new FileNotFoundException("Invalid path or file name to be processed");
                abort();
            }
            else
            {
                this->FileStreamPrivate->__mode = Write;
            }
            break;
        case Append:
            this->FileStreamPrivate->stream = fopen(__name->Get(), "a");
            if(!this->Get())
            {
                // throw new FileNotFoundException("Invalid path or file name to be processed");
                abort();
            }
            else
            {
                this->FileStreamPrivate->__mode = Append;
            }
            break;
        case ReadUpdate:
            this->FileStreamPrivate->stream = fopen(__name->Get(), "r+");
            if(!this->Get())
            {
                // throw new FileNotFoundException("Invalid path or file name to be processed");
                abort();
            }
            else
            {
                this->FileStreamPrivate->__mode = ReadUpdate;
            }
            break;
        case WriteUpdate:
            this->FileStreamPrivate->stream = fopen(__name->Get(), "w+");
            if(!this->Get())
            {
                // throw new FileNotFoundException("Invalid path or file name to be processed");
                abort();
            }
            else
            {
                this->FileStreamPrivate->__mode = WriteUpdate;
            }
            break;
        case AppendUpdate:
            this->FileStreamPrivate->stream = fopen(__name->Get(), "a+");
            if(!this->Get())
            {
                // throw new FileNotFoundException("Invalid path or file name to be processed");
                abort();
            }
            else
            {
                this->FileStreamPrivate->__mode = AppendUpdate;
            }
            break;
    }
    return;
}

void FileStream_StreamClose(FileStream * const this)
{
    return (void)fclose(this->Get());
}

void FileStream_StreamFlush(FileStream * const this)
{
    return (void)fflush(this->Get());
}

char FileStream_GetChar(FileStream * const this)
{
    char c;

    if((c = fgetc(this->Get())) == EOF)
    {
        // throw new DataNotFoundException("End of file was set");
        abort();
    }
    return c;
}

struct string *FileStream_GetString(struct string *__s, size_t size, FileStream * const this)
{
    char *__str = GC_MALLOC(size + 1);

    if(!__s)
    {
        // throw new NullArgumentException("No available String instance can be performed");
        abort();
    }
    else if(!__s->Get())
    {
        // throw new NullArgumentException("No available String attribute to assign string literal");
        abort();
    }
    else if(size < 2)
    {
        // throw new ArgumentException("Size cannot be less than two");
        abort();
    }
    else
    {
        if(!fgets(__str, size, this->Get()))
        {
            // throw new DataNotFoundException("End of file was set");
        }
        else
        {
            strcpy(__s->Get(), __str);
        }
        return __s;
    }
    return 0;
} 

void FileStream_PutChar(char c, FileStream * const this)
{
    if(this->FileStreamPrivate->__mode == None)
    {
        // throw new FileNotOpenedException("FileStream has not been opened");
        abort();
    }
    else if(this->FileStreamPrivate->__mode == Read)
    {
        // throw new FileNotWritableException("FileStream has no writable FileMode available");
        abort();
    }
    else
    {
        return (void)fputc(c, this->Get());
    }
    return;
}

void FileStream_PutString(String *__s, FileStream * const this)
{
    if(this->FileStreamPrivate->__mode == None)
    {
        // throw new FileNotOpenedException("FileStream has not been opened");
        abort();
    }
    else if(this->FileStreamPrivate->__mode == Read)
    {
        // throw new FileNotWritableException("FileStream has no writable FileMode available");
        abort();
    }
    else
    {
        if(!__s)
        {
            // throw new NullArgumentException("No available String instance can be performed");
            abort();
        }
        else if(!__s->Get())
        {
            // throw new NullArgumentException("No available String attribute to assign string literal");
            abort();
        }
        else
        {
            return (void)fputs(__s->Get(), this->Get());
        }
    }
    return;
}

void *FileStream_File0(FileStream *this)
{
    void *__this;
    void *__save_fp = (void *)this->File0;
    callprotect(&this->object);
    __this = Object_create(sizeof(*this), 11);
    memcpy(this, __this, sizeof(*this));
    FUNCTION(FileStream, Get, 0);
    FUNCTION(FileStream, StreamOpen, 0);
    FUNCTION(FileStream, StreamClose, 0);
    FUNCTION(FileStream, StreamFlush, 0);
    FUNCTION(FileStream, GetChar, 0);
    FUNCTION(FileStream, GetString, 2);
    FUNCTION(FileStream, PutChar, 1);
    FUNCTION(FileStream, PutString, 1);
    FUNCTION(FileStream, File1, 1);
    this->File0 = __save_fp;
    this->FileStreamPrivate = Object_create(sizeof(FileStreamPrivate), 1);
    FUNCTIONP(FileStream, Set, 1);
    Object_prepare(&this->FileStreamPrivate->object);
    Object_prepare(&this->object);
    return 0;
}

void *FileStream_File1(FileStream *__fs, FileMode __m, FileStream *this)
{
    void *__this;
    void *__save_fp = (void *)this->File1;
    callprotect(&this->object);
    __this = Object_create(sizeof(*this), 11);
    memcpy(this, __this, sizeof(*this));
    FUNCTION(FileStream, Get, 0);
    FUNCTION(FileStream, StreamOpen, 0);
    FUNCTION(FileStream, StreamClose, 0);
    FUNCTION(FileStream, StreamFlush, 0);
    FUNCTION(FileStream, GetChar, 0);
    FUNCTION(FileStream, GetString, 2);
    FUNCTION(FileStream, PutChar, 1);
    FUNCTION(FileStream, PutString, 1);
    FUNCTION(FileStream, File0, 0);
    this->File1 = __save_fp;
    this->FileStreamPrivate = Object_create(sizeof(FileStreamPrivate), 1);
    FUNCTIONP(FileStream, Set, 2);
    Object_prepare(&this->FileStreamPrivate->object);
    this->FileStreamPrivate->Set(__fs, __m);
    Object_prepare(&this->object);
    return 0;
}

static void FileStreamPrivate_Set(const FileStream *__f, FileMode __m, FileStreamPrivate * const this)
{
    this->stream = __f->Get();
    this->__mode = __m;
    return;
}

/*
void FileStream_Dispose(FileStream * const this)
{
    if(this->Get())
    {
        fclose(this->Get());
        GC_free(this);
    }
    else
    {
        //throw new NullArgumentException();
        abort();
    }
    return;
}
*/
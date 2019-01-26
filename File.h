#include "ObjectPrueba.h"

#ifndef FILE_H
#define FILE_H

typedef enum fmode
{
    None = 0,
    Read,
    Write, 
    Append,
    ReadUpdate,
    WriteUpdate,
    AppendUpdate
} FileMode;

typedef struct FileStreamPrivate FileStreamPrivate;

typedef struct file
{
    Object object;
    private(FileStream);
    FILE *(*Get)(void);
    void (*StreamOpen)(struct string *, FileMode);
    void (*StreamClose)(void);
    void (*StreamFlush)(void);
    char (*GetChar)(void); 
    struct string *(*GetString)(struct string *, size_t);
    void (*PutChar)(char);
    void (*PutString)(struct string *);
    #define File(args...) overload(File, args);
    void *(*File0)(void);
    void *(*File1)(const struct file *, FileMode);
    //void (*Dispose)(void); -- Required if interface was given
} FileStream;

/* Public */
extern FILE *FileStream_Get(FileStream * const );
extern void FileStream_StreamOpen(struct string *, FileMode, FileStream * const);
extern void FileStream_StreamClose(FileStream * const);
extern void FileStream_StreamFlush(FileStream * const);
extern char FileStream_GetChar(FileStream * const);
extern struct string *FileStream_GetString(struct string *, size_t, FileStream * const);
extern void FileStream_PutChar(char, FileStream * const);
extern void FileStream_PutString(struct string *, FileStream * const);
/* Ctor */
extern void *FileStream_File0(FileStream *);
extern void *FileStream_File1(FileStream *, FileMode, FileStream *);

#endif /* FILE_H */
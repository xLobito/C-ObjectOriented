#include "ObjectPrueba.h"

#ifndef STACK_H
#define STACK_H

#define stack(T) \
    typedef struct Stack_##T##Private Stack_##T##Private; \
    \
    typedef struct stack_##T \
    { \
        Object object; \
        private(Stack_##T); \
        void (*Push)(T *); \
        T *(*Pop)(void); \
        T *(*PeekStackPointer)(void); \
    } Stack_##T; \

#define Stack(T) Stack_##T
#define StackCollection(T) StackExpand(N, T)
#define StackExpand(N, T) N##T()

stack(Int16);
stack(Int32);
stack(Int64);
stack(UInt16);
stack(UInt32);
stack(UInt64);
stack(String);

/* Constructors */
extern void *NStack_Int16(void);
extern void *NStack_Int32(void);
extern void *NStack_Int64(void);
extern void *NStack_UInt16(void);
extern void *NStack_UInt32(void);
extern void *NStack_UInt64(void);
extern void *NStack_String(void);
/* Int16 */
extern void Stack_Int16_Push(Int16 *, Stack_Int16 * const);
extern Int16 *Stack_Int16_Pop(Stack_Int16 * const);
extern Int16 *Stack_Int16_PeekStackPointer(Stack_Int16 * const);
/* Int32 */
extern void Stack_Int32_Push(Int32 *, Stack_Int32 * const);
extern Int32 *Stack_Int32_Pop(Stack_Int32 * const);
extern Int32 *Stack_Int32_PeekStackPointer(Stack_Int32 * const);
/* Int64 */
extern void Stack_Int64_Push(Int64 *, Stack_Int64 * const);
extern Int64 *Stack_Int64_Pop(Stack_Int64 * const);
extern Int64 *Stack_Int64_PeekStackPointer(Stack_Int64 * const);
/* UInt16 */
extern void Stack_UInt16_Push(UInt16 *, Stack_UInt16 * const);
extern UInt16 *Stack_UInt16_Pop(Stack_UInt16 * const);
extern UInt16 *Stack_UInt16_PeekStackPointer(Stack_UInt16 * const);
/* UInt32 */
extern void Stack_UInt32_Push(UInt32 *, Stack_UInt32 * const);
extern UInt32 *Stack_UInt32_Pop(Stack_UInt32 * const);
extern UInt32 *Stack_UInt32_PeekStackPointer(Stack_UInt32 * const);
/* UInt64 */
extern void Stack_UInt64_Push(UInt64 *, Stack_UInt64 * const);
extern UInt64 *Stack_UInt64_Pop(Stack_UInt64 * const);
extern UInt64 *Stack_UInt64_PeekStackPointer(Stack_UInt64 * const);
/* String */
extern void Stack_String_Push(String *, Stack_String * const);
extern String *Stack_String_Pop(Stack_String * const);
extern String *Stack_String_PeekStackPointer(Stack_String * const);

#endif /* STACK_H */
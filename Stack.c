#include "Stack.h"

typedef struct Stack_Int16Private
{
    Int16 *value;
    struct Stack_Int16Private *Stack;
    struct Stack_Int16Private *top;
} Stack_Int16Private;

typedef struct Stack_Int32Private
{
    Int32 *value;
    struct Stack_Int32Private *Stack;
    struct Stack_Int32Private *top;
} Stack_Int32Private;

typedef struct Stack_Int64Private
{
    Int64 *value;
    struct Stack_Int64Private *Stack;
    struct Stack_Int64Private *top;
} Stack_Int64Private;

typedef struct Stack_UInt16Private
{
    UInt16 *value;
    struct Stack_UInt16Private *Stack;
    struct Stack_UInt16Private *top;
} Stack_UInt16Private;

typedef struct Stack_UInt32Private
{
    UInt32 *value;
    struct Stack_UInt32Private *Stack;
    struct Stack_UInt32Private *top;
} Stack_UInt32Private;

typedef struct Stack_UInt64Private
{
    UInt64 *value;
    struct Stack_UInt64Private *Stack;
    struct Stack_UInt64Private *top;
} Stack_UInt64Private;

typedef struct Stack_StringPrivate
{
    String *value;
    struct Stack_StringPrivate *Stack;
    struct Stack_StringPrivate *top;
} Stack_StringPrivate;

/* Constructors */
void *NStack_Int16(void);
void *NStack_Int32(void);
void *NStack_Int64(void);
void *NStack_UInt16(void);
void *NStack_UInt32(void);
void *NStack_UInt64(void);
void *NStack_String(void);
/* Int16 */
void Stack_Int16_Push(Int16 *, Stack_Int16 * const);
Int16 *Stack_Int16_Pop(Stack_Int16 * const);
Int16 *Stack_Int16_PeekStackPointer(Stack_Int16 * const);
/* Int32 */
void Stack_Int32_Push(Int32 *, Stack_Int32 * const);
Int32 *Stack_Int32_Pop(Stack_Int32 * const);
Int32 *Stack_Int32_PeekStackPointer(Stack_Int32 * const);
/* Int64 */
void Stack_Int64_Push(Int64 *, Stack_Int64 * const);
Int64 *Stack_Int64_Pop(Stack_Int64 * const);
Int64 *Stack_Int64_PeekStackPointer(Stack_Int64 * const);
/* UInt16 */
void Stack_UInt16_Push(UInt16 *, Stack_UInt16 * const);
UInt16 *Stack_UInt16_Pop(Stack_UInt16 * const);
UInt16 *Stack_UInt16_PeekStackPointer(Stack_UInt16 * const);
/* UInt32 */
void Stack_UInt32_Push(UInt32 *, Stack_UInt32 * const);
UInt32 *Stack_UInt32_Pop(Stack_UInt32 * const);
UInt32 *Stack_UInt32_PeekStackPointer(Stack_UInt32 * const);
/* UInt64 */
void Stack_UInt64_Push(UInt64 *, Stack_UInt64 * const);
UInt64 *Stack_UInt64_Pop(Stack_UInt64 * const);
UInt64 *Stack_UInt64_PeekStackPointer(Stack_UInt64 * const);
/* String */
void Stack_String_Push(String *, Stack_String * const);
String *Stack_String_Pop(Stack_String * const);
String *Stack_String_PeekStackPointer(Stack_String * const);

/* Stack */
void *NStack_Int16(void)
{
    Stack_Int16 *this = Object_create(sizeof(Stack_Int16), 4);

    this->Stack_Int16Private->Stack = NULL;
    FUNCTION(Stack_Int16, Push, 1);
    FUNCTION(Stack_Int16, Pop, 0);
    FUNCTION(Stack_Int16, PeekStackPointer, 0);
    Object_prepare(&this->object);
    return this;
}

void *NStack_Int32(void)
{
    Stack_Int32 *this = Object_create(sizeof(Stack_Int32), 4);

    this->Stack_Int32Private->Stack = NULL;
    FUNCTION(Stack_Int32, Push, 1);
    FUNCTION(Stack_Int32, Pop, 0);
    FUNCTION(Stack_Int32, PeekStackPointer, 0);
    Object_prepare(&this->object);
    return this;
}

void *NStack_Int64(void)
{
    Stack_Int64 *this = Object_create(sizeof(Stack_Int64), 4);

    this->Stack_Int64Private->Stack = NULL;
    FUNCTION(Stack_Int64, Push, 1);
    FUNCTION(Stack_Int64, Pop, 0);
    FUNCTION(Stack_Int64, PeekStackPointer, 0);
    Object_prepare(&this->object);
    return this;
}

void *NStack_UInt16(void)
{
    Stack_UInt16 *this = Object_create(sizeof(Stack_UInt16), 4);

    this->Stack_UInt16Private->Stack = NULL;
    FUNCTION(Stack_UInt16, Push, 1);
    FUNCTION(Stack_UInt16, Pop, 0);
    FUNCTION(Stack_UInt16, PeekStackPointer, 0);
    Object_prepare(&this->object);
    return this;
}

void *NStack_UInt32(void)
{
    Stack_UInt32 *this = Object_create(sizeof(Stack_UInt32), 4);

    this->Stack_UInt32Private->Stack = NULL;
    FUNCTION(Stack_UInt32, Push, 1);
    FUNCTION(Stack_UInt32, Pop, 0);
    FUNCTION(Stack_UInt32, PeekStackPointer, 0);
    Object_prepare(&this->object);
    return this;
}

void *NStack_UInt64(void)
{
    Stack_UInt64 *this = Object_create(sizeof(Stack_UInt64), 4);

    this->Stack_UInt64Private->Stack = NULL;
    FUNCTION(Stack_UInt64, Push, 1);
    FUNCTION(Stack_UInt64, Pop, 0);
    FUNCTION(Stack_UInt64, PeekStackPointer, 0);
    Object_prepare(&this->object);
    return this;
}

void *NStack_String(void)
{
    Stack_String *this = Object_create(sizeof(Stack_String), 4);

    this->Stack_StringPrivate->Stack = NULL;
    FUNCTION(Stack_String, Push, 1);
    FUNCTION(Stack_String, Pop, 0);
    FUNCTION(Stack_String, PeekStackPointer, 0);
    Object_prepare(&this->object);
    return this;
}

/* Int16 */
void Stack_Int16_Push(Int16 *arg, Stack_Int16 * const this)
{
	void (*Push)(Int16 *, Stack_Int16Private **) = delegate(void, (Int16 *arg, Stack_Int16Private **this) {
		Stack_Int16Private *aux = GC_MALLOC(sizeof(Stack_Int16Private));
	
		aux->value = arg;
		aux->top = (*this)->Stack;
		(*this)->Stack = aux;
	} ); 
	return Push(arg, &this->Stack_Int16Private->Stack); 
}

Int16 *Stack_Int16_Pop(Stack_Int16 * const this)
{
	Int16 *(*Pop)(Stack_Int16Private **) = delegate(Int16 *, (Stack_Int16Private **this) {
		Stack_Int16Private *aux; 
		Int16 *ret;
		
		if((*this)->Stack == NULL)
		{
			//throw new NullArgumentException("The Stack has no elements to be popped off");
            abort();
        }
		else
		{
			ret = (*this)->Stack->value;
			aux = (*this)->Stack;
			(*this)->Stack = (*this)->Stack->top;
			GC_FREE(aux);
		}
		return ret;
	} );
	return Pop(&this->Stack_Int16Private->Stack);
}

Int16 *Stack_Int16_PeekStackPointer(Stack_Int16 * const this)
{
	if(this->Stack_Int16Private->Stack == NULL)
	{
		//throw new NullArgumentException("The Stack has no elements to be popped off");
        abort();
    }
	else
	{
		return this->Stack_Int16Private->Stack->value;
	}
	return 0;
}

/* Int32 */
void Stack_Int32_Push(Int32 *arg, Stack_Int32 * const this)
{
	void (*Push)(Int32 *, Stack_Int32Private **) = delegate(void, (Int32 *arg, Stack_Int32Private **this) {
		Stack_Int32Private *aux = GC_MALLOC(sizeof(Stack_Int32Private));
	
		aux->value = arg;
		aux->top = (*this)->Stack;
		(*this)->Stack = aux;
	} ); 
	return Push(arg, &this->Stack_Int32Private->Stack); 
}

Int32 *Stack_Int32_Pop(Stack_Int32 * const this)
{
	Int32 *(*Pop)(Stack_Int32Private **) = delegate(Int32 *, (Stack_Int32Private **this) {
		Stack_Int32Private *aux; 
		Int32 *ret;
		
		if((*this)->Stack == NULL)
		{
			//throw new NullArgumentException("The Stack has no elements to be popped off");
            abort();
        }
		else
		{
			ret = (*this)->Stack->value;
			aux = (*this)->Stack;
			(*this)->Stack = (*this)->Stack->top;
			GC_FREE(aux);
		}
		return ret;
	} );
	return Pop(&this->Stack_Int32Private->Stack);
}

Int32 *Stack_Int32_PeekStackPointer(Stack_Int32 * const this)
{
	if(this->Stack_Int32Private->Stack == NULL)
	{
		//throw new NullArgumentException("The Stack has no elements to be popped off");
        abort();
    }
	else
	{
		return this->Stack_Int32Private->Stack->value;
	}
	return 0;
}

/* Int64 */
void Stack_Int64_Push(Int64 *arg, Stack_Int64 * const this)
{
	void (*Push)(Int64 *, Stack_Int64Private **) = delegate(void, (Int64 *arg, Stack_Int64Private **this) {
		Stack_Int64Private *aux = GC_MALLOC(sizeof(Stack_Int64Private));
	
		aux->value = arg;
		aux->top = (*this)->Stack;
		(*this)->Stack = aux;
	} ); 
	return Push(arg, &this->Stack_Int64Private->Stack); 
}

Int64 *Stack_Int64_Pop(Stack_Int64 * const this)
{
	Int64 *(*Pop)(Stack_Int64Private **) = delegate(Int64 *, (Stack_Int64Private **this) {
		Stack_Int64Private *aux; 
		Int64 *ret;
		
		if((*this)->Stack == NULL)
		{
			//throw new NullArgumentException("The Stack has no elements to be popped off");
            abort();
        }
		else
		{
			ret = (*this)->Stack->value;
			aux = (*this)->Stack;
			(*this)->Stack = (*this)->Stack->top;
			GC_FREE(aux);
		}
		return ret;
	} );
	return Pop(&this->Stack_Int64Private->Stack);
}

Int64 *Stack_Int64_PeekStackPointer(Stack_Int64 * const this)
{
	if(this->Stack_Int64Private->Stack == NULL)
	{
		//throw new NullArgumentException("The Stack has no elements to be popped off");
        abort();
    }
	else
	{
		return this->Stack_Int64Private->Stack->value;
	}
	return 0;
}

/* UInt16 */
void Stack_UInt16_Push(UInt16 *arg, Stack_UInt16 * const this)
{
	void (*Push)(UInt16 *, Stack_UInt16Private **) = delegate(void, (UInt16 *arg, Stack_UInt16Private **this) {
		Stack_UInt16Private *aux = GC_MALLOC(sizeof(Stack_UInt16Private));
	
		aux->value = arg;
		aux->top = (*this)->Stack;
		(*this)->Stack = aux;
	} ); 
	return Push(arg, &this->Stack_UInt16Private->Stack); 
}

UInt16 *Stack_UInt16_Pop(Stack_UInt16 * const this)
{
	UInt16 *(*Pop)(Stack_UInt16Private **) = delegate(UInt16 *, (Stack_UInt16Private **this) {
		Stack_UInt16Private *aux; 
		UInt16 *ret;
		
		if((*this)->Stack == NULL)
		{
			//throw new NullArgumentException("The Stack has no elements to be popped off");
            abort();
        }
		else
		{
			ret = (*this)->Stack->value;
			aux = (*this)->Stack;
			(*this)->Stack = (*this)->Stack->top;
			GC_FREE(aux);
		}
		return ret;
	} );
	return Pop(&this->Stack_UInt16Private->Stack);
}

UInt16 *Stack_UInt16_PeekStackPointer(Stack_UInt16 * const this)
{
	if(this->Stack_UInt16Private->Stack == NULL)
	{
		//throw new NullArgumentException("The Stack has no elements to be popped off");
        abort();
    }
	else
	{
		return this->Stack_UInt16Private->Stack->value;
	}
	return 0;
}

/* UInt32 */
void Stack_UInt32_Push(UInt32 *arg, Stack_UInt32 * const this)
{
	void (*Push)(UInt32 *, Stack_UInt32Private **) = delegate(void, (UInt32 *arg, Stack_UInt32Private **this) {
		Stack_UInt32Private *aux = GC_MALLOC(sizeof(Stack_UInt32Private));
	
		aux->value = arg;
		aux->top = (*this)->Stack;
		(*this)->Stack = aux;
	} ); 
	return Push(arg, &this->Stack_UInt32Private->Stack); 
}

UInt32 *Stack_UInt32_Pop(Stack_UInt32 * const this)
{
	UInt32 *(*Pop)(Stack_UInt32Private **) = delegate(UInt32 *, (Stack_UInt32Private **this) {
		Stack_UInt32Private *aux; 
		UInt32 *ret;
		
		if((*this)->Stack == NULL)
		{
			//throw new NullArgumentException("The Stack has no elements to be popped off");
            abort();
        }
		else
		{
			ret = (*this)->Stack->value;
			aux = (*this)->Stack;
			(*this)->Stack = (*this)->Stack->top;
			GC_FREE(aux);
		}
		return ret;
	} );
	return Pop(&this->Stack_UInt32Private->Stack);
}

UInt32 *Stack_UInt32_PeekStackPointer(Stack_UInt32 * const this)
{
	if(this->Stack_UInt32Private->Stack == NULL)
	{
		//throw new NullArgumentException("The Stack has no elements to be popped off");
        abort();
    }
	else
	{
		return this->Stack_UInt32Private->Stack->value;
	}
	return 0;
}

/* UInt64 */
void Stack_UInt64_Push(UInt64 *arg, Stack_UInt64 * const this)
{
	void (*Push)(UInt64 *, Stack_UInt64Private **) = delegate(void, (UInt64 *arg, Stack_UInt64Private **this) {
		Stack_UInt64Private *aux = GC_MALLOC(sizeof(Stack_UInt64Private));
	
		aux->value = arg;
		aux->top = (*this)->Stack;
		(*this)->Stack = aux;
	} ); 
	return Push(arg, &this->Stack_UInt64Private->Stack); 
}

UInt64 *Stack_UInt64_Pop(Stack_UInt64 * const this)
{
	UInt64 *(*Pop)(Stack_UInt64Private **) = delegate(UInt64 *, (Stack_UInt64Private **this) {
		Stack_UInt64Private *aux; 
		UInt64 *ret;
		
		if((*this)->Stack == NULL)
		{
			//throw new NullArgumentException("The Stack has no elements to be popped off");
            abort();
        }
		else
		{
			ret = (*this)->Stack->value;
			aux = (*this)->Stack;
			(*this)->Stack = (*this)->Stack->top;
			GC_FREE(aux);
		}
		return ret;
	} );
	return Pop(&this->Stack_UInt64Private->Stack);
}

UInt64 *Stack_UInt64_PeekStackPointer(Stack_UInt64 * const this)
{
	if(this->Stack_UInt64Private->Stack == NULL)
	{
		//throw new NullArgumentException("The Stack has no elements to be popped off");
        abort();
    }
	else
	{
		return this->Stack_UInt64Private->Stack->value;
	}
	return 0;
}

/* String */
void Stack_String_Push(String *arg, Stack_String * const this)
{
	void (*Push)(String *, Stack_StringPrivate **) = delegate(void, (String *arg, Stack_StringPrivate **this) {
		Stack_StringPrivate *aux = GC_MALLOC(sizeof(Stack_StringPrivate));
	
		aux->value = arg;
		aux->top = (*this)->Stack;
		(*this)->Stack = aux;
	} ); 
	return Push(arg, &this->Stack_StringPrivate->Stack); 
}

String *Stack_String_Pop(Stack_String * const this)
{
	String *(*Pop)(Stack_StringPrivate **) = delegate(String *, (Stack_StringPrivate **this) {
		Stack_StringPrivate *aux; 
		String *ret;
		
		if((*this)->Stack == NULL)
		{
			//throw new NullArgumentException("The Stack has no elements to be popped off");
            abort();
        }
		else
		{
			ret = (*this)->Stack->value;
			aux = (*this)->Stack;
			(*this)->Stack = (*this)->Stack->top;
			GC_FREE(aux);
		}
		return ret;
	} );
	return Pop(&this->Stack_StringPrivate->Stack);
}

String *Stack_String_PeekStackPointer(Stack_String * const this)
{
	if(this->Stack_StringPrivate->Stack == NULL)
	{
		//throw new NullArgumentException("The Stack has no elements to be popped off");
        abort();
    }
	else
	{
		return this->Stack_StringPrivate->Stack->value;
	}
	return 0;
}
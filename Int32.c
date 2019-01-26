#include "Int32.h"

typedef struct Int32Private
{
    Object object;
    int value;
    void (*Set)(int);
} Int32Private;

/* Public */
int Int32_Get(Int32 * const);
Int32 *Int32_Parse(struct string *, Int32 * const);
struct string *Int32_ToString(Int32 * const);
bool Int32_ReferenceEquality(void *, Int32 * const);
bool Int32_Equals(Int32 *, Int32 * const);
/* Ctor */
void *Int32_Int320(Int32 *);
void *Int32_Int321(int, Int32 *);
/* Private */
static void Int32Private_Set(int, Int32Private * const);

int Int32_Get(Int32 * const this)
{
    return this->Int32Private->value;
}

Int32 *Int32_Parse(String *str, Int32 * const this)
{
	Int32 *ret = Int32_Int321(0, this);
	
	ret->Int32Private->value = atoi(str->Get());
	return ret;
}

/*
Char *Int16_ToChar(Int16 *this)
{	
	Char *ret = new Char((char)this->value + '0');
	return ret;
} */

String *Int32_ToString(Int32 * const this)
{
	String *ret;
	char *aux = GC_MALLOC(255);
	
	(void)sprintf(aux, "%d", this->Int32Private->value);
	//return (ret = new String(aux));
	return 0;
}

bool Int32_ReferenceEquality(void *object, Int32 * const this)
{
	if(object == (void *)this)
		return true;
	else
		return false;
}

bool Int32_Equals(Int32 *check, Int32 * const this)
{
	return (check->Int32Private->value == this->Int32Private->value) ? true : false;
}

/* Ctor */
optimize(0) void *Int32_Int320(Int32 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->Int320;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(Int32, Get, 0);
	FUNCTION(Int32, Parse, 1);
	FUNCTION(Int32, ToString, 0);
	FUNCTION(Int32, ReferenceEquality, 1);
	FUNCTION(Int32, Equals, 1);
	FUNCTION(Int32, Int321, 1);
	this->Int320 = __save_fp;
	this->Int32Private = Object_create(sizeof(Int32Private), 1);
	FUNCTIONP(Int32, Set, 1);
	Object_prepare(&this->Int32Private->object);
	this->Int32Private->Set(0);
	Object_prepare(&this->object);
	return 0;
}

optimize(0) void *Int32_Int321(int value, Int32 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->Int321;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(Int32, Get, 0);
	FUNCTION(Int32, Parse, 1);
	FUNCTION(Int32, ToString, 0);
	FUNCTION(Int32, ReferenceEquality, 1);
	FUNCTION(Int32, Equals, 1);
	FUNCTION(Int32, Int320, 1);
	this->Int321 = __save_fp;
	this->Int32Private = Object_create(sizeof(Int32Private), 1);
	FUNCTIONP(Int32, Set, 1);
	Object_prepare(&this->Int32Private->object);
	this->Int32Private->Set(value);
	Object_prepare(&this->object);
	return 0;
}

/* Private method */
static void Int32Private_Set(int value, Int32Private * const this)
{
    this->value = value;
    return;
}
#include "Int16.h"

typedef struct Int16Private
{
	Object object;
    short value;
    void (*Set)(short);
} Int16Private;

short Int16_Get(Int16 * const);
Int16 *Int16_Parse(String *, Int16 * const);
String *Int16_ToString(Int16 * const);
bool Int16_ReferenceEquality(void *, Int16 * const); 
bool Int16_Equals(Int16 *, Int16 * const);
/* Ctor */
void *Int16_Int160(Int16 *);
void *Int16_Int161(short, Int16 *);
/* Private method */
static void Int16Private_Set(short, Int16Private * const);

short Int16_Get(Int16 * const this)
{
    return this->Int16Private->value;
}

Int16 *Int16_Parse(String *str, Int16 * const this)
{
	Int16 *ret = Int16_Int161(0, this);
	
	ret->Int16Private->value = atoi(str->Get());
	return ret;
}

/*
Char *Int16_ToChar(Int16 *this)
{	
	Char *ret = new Char((char)this->value + '0');
	return ret;
} */

String *Int16_ToString(Int16 * const this)
{
	String *ret;
	char *aux = GC_MALLOC(255);
	
	(void)sprintf(aux, "%d", this->Int16Private->value);
	//return (ret = new String(aux));
	return 0;
}

bool Int16_ReferenceEquality(void *object, Int16 * const this)
{
	if(object == (void *)this)
		return true;
	else
		return false;
}

bool Int16_Equals(Int16 *check, Int16 * const this)
{
	return (check->Int16Private->value == this->Int16Private->value) ? true : false;
}

/* Ctor */
optimize(0) void *Int16_Int160(Int16 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->Int160;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(Int16, Get, 0);
	FUNCTION(Int16, Parse, 1);
	FUNCTION(Int16, ToString, 0);
	FUNCTION(Int16, ReferenceEquality, 1);
	FUNCTION(Int16, Equals, 1);
	FUNCTION(Int16, Int161, 1);
	this->Int160 = __save_fp;
	this->Int16Private = Object_create(sizeof(Int16Private), 1);
	FUNCTIONP(Int16, Set, 1);
	Object_prepare(&this->Int16Private->object);
	this->Int16Private->Set(0);
	Object_prepare(&this->object);
	return 0;
}
void *Int16_Int161(short value, Int16 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->Int161;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(Int16, Get, 0);
	FUNCTION(Int16, Parse, 1);
	FUNCTION(Int16, ToString, 0);
	FUNCTION(Int16, ReferenceEquality, 1);
	FUNCTION(Int16, Equals, 1);
	FUNCTION(Int16, Int160, 1);
	this->Int161 = __save_fp;
	this->Int16Private = Object_create(sizeof(Int16Private), 1);
	FUNCTIONP(Int16, Set, 1);
	Object_prepare(&this->Int16Private->object);
	this->Int16Private->Set(value);
	Object_prepare(&this->object);
	return 0;
}

/* Private method */
static void Int16Private_Set(short value, Int16Private * const this)
{
    this->value = value;
    return;
}
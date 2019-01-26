#include "Int64.h"

typedef struct Int64Private
{
    Object object;
    long value;
    void (*Set)(long);
} Int64Private;

/* Public */
long Int64_Get(Int64 * const);
Int64 *Int64_Parse(struct string *, Int64 * const);
struct string *Int64_ToString(Int64 * const);
bool Int64_ReferenceEquality(void *, Int64 * const);
bool Int64_Equals(Int64 *, Int64 * const);
/* Ctor */
void *Int64_Int640(Int64 *);
void *Int64_Int641(long, Int64 *);
/* Private */
static void Int64Private_Set(long, Int64Private * const);

long Int64_Get(Int64 * const this)
{
    return this->Int64Private->value;
}

Int64 *Int64_Parse(String *str, Int64 * const this)
{
	Int64 *ret = Int64_Int641(0, this);
	
	ret->Int64Private->value = atoi(str->Get());
	return ret;
}

/*
Char *Int16_ToChar(Int16 *this)
{	
	Char *ret = new Char((char)this->value + '0');
	return ret;
} */

String *Int64_ToString(Int64 * const this)
{
	String *ret;
	char *aux = GC_MALLOC(255);
	
	(void)sprintf(aux, "%ld", this->Int64Private->value);
	//return (ret = new String(aux));
	return 0;
}

bool Int64_ReferenceEquality(void *object, Int64 * const this)
{
	if(object == (void *)this)
		return true;
	else
		return false;
}

bool Int64_Equals(Int64 *check, Int64 * const this)
{
	return (check->Int64Private->value == this->Int64Private->value) ? true : false;
}

/* Ctor */
optimize(0) void *Int64_Int640(Int64 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->Int640;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(Int64, Get, 0);
	FUNCTION(Int64, Parse, 1);
	FUNCTION(Int64, ToString, 0);
	FUNCTION(Int64, ReferenceEquality, 1);
	FUNCTION(Int64, Equals, 1);
	FUNCTION(Int64, Int641, 1);
	this->Int640 = __save_fp;
	this->Int64Private = Object_create(sizeof(Int64Private), 1);
	FUNCTIONP(Int64, Set, 1);
	Object_prepare(&this->Int64Private->object);
	this->Int64Private->Set(0);
	Object_prepare(&this->object);
	return 0;
}

optimize(0) void *Int64_Int641(long value, Int64 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->Int641;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(Int64, Get, 0);
	FUNCTION(Int64, Parse, 1);
	FUNCTION(Int64, ToString, 0);
	FUNCTION(Int64, ReferenceEquality, 1);
	FUNCTION(Int64, Equals, 1);
	FUNCTION(Int64, Int640, 1);
	this->Int641 = __save_fp;
	this->Int64Private = Object_create(sizeof(Int64Private), 1);
	FUNCTIONP(Int64, Set, 1);
	Object_prepare(&this->Int64Private->object);
	this->Int64Private->Set(value);
	Object_prepare(&this->object);
	return 0;
}

/* Private method */
static void Int64Private_Set(long value, Int64Private * const this)
{
    this->value = value;
    return;
}
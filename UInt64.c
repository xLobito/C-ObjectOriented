#include "UInt64.h"

typedef struct UInt64Private
{
	Object object;
    unsigned long value;
    void (*Set)(unsigned long);
} UInt64Private;

unsigned long UInt64_Get(UInt64 * const);
UInt64 *UInt64_Parse(String *, UInt64 * const);
String *UInt64_ToString(UInt64 * const);
bool UInt64_ReferenceEquality(void *, UInt64 * const); 
bool UInt64_Equals(UInt64 *, UInt64 * const);
/* Ctor */
void *UInt64_UInt640(UInt64 *);
void *UInt64_UInt641(unsigned long, UInt64 *);
/* Private method */
static void UInt64Private_Set(unsigned long, UInt64Private * const);

unsigned long UInt64_Get(UInt64 * const this)
{
    return this->UInt64Private->value;
}

UInt64 *UInt64_Parse(String *str, UInt64 * const this)
{
	UInt64 *ret = UInt64_UInt641(0, this);
	
	ret->UInt64Private->value = atoi(str->Get());
	return ret;
}

/*
Char *Int16_ToChar(Int16 *this)
{	
	Char *ret = new Char((char)this->value + '0');
	return ret;
} */

String *UInt64_ToString(UInt64 * const this)
{
	String *ret = new Instance(String, 1);
	char *aux = GC_MALLOC(255);
	
	(void)sprintf(aux, "%lu", this->UInt64Private->value);
	ret->String(aux);
	return ret;
}

bool UInt64_ReferenceEquality(void *object, UInt64 * const this)
{
	if(object == (void *)this)
		return true;
	else
		return false;
}

bool UInt64_Equals(UInt64 *check, UInt64 * const this)
{
	return (check->UInt64Private->value == this->UInt64Private->value) ? true : false;
}

/* Ctor */
optimize(0) void *UInt64_UInt640(UInt64 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->UInt640;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(UInt64, Get, 0);
	FUNCTION(UInt64, Parse, 1);
	FUNCTION(UInt64, ToString, 0);
	FUNCTION(UInt64, ReferenceEquality, 1);
	FUNCTION(UInt64, Equals, 1);
	FUNCTION(UInt64, UInt641, 1);
	this->UInt640 = __save_fp;
	this->UInt64Private = Object_create(sizeof(UInt64Private), 1);
	FUNCTIONP(UInt64, Set, 1);
	Object_prepare(&this->UInt64Private->object);
	this->UInt64Private->Set(0);
	Object_prepare(&this->object);
	return 0;
}
void *UInt64_UInt641(unsigned long value, UInt64 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->UInt641;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(UInt64, Get, 0);
	FUNCTION(UInt64, Parse, 1);
	FUNCTION(UInt64, ToString, 0);
	FUNCTION(UInt64, ReferenceEquality, 1);
	FUNCTION(UInt64, Equals, 1);
	FUNCTION(UInt64, UInt640, 1);
	this->UInt641 = __save_fp;
	this->UInt64Private = Object_create(sizeof(UInt64Private), 1);
	FUNCTIONP(UInt64, Set, 1);
	Object_prepare(&this->UInt64Private->object);
	this->UInt64Private->Set(value);
	Object_prepare(&this->object);
	return 0;
}

/* Private method */
static void UInt64Private_Set(unsigned long value, UInt64Private * const this)
{
    this->value = value;
    return;
}
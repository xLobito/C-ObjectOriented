#include "UInt32.h"

typedef struct UInt32Private
{
	Object object;
    unsigned int value;
    void (*Set)(short);
} UInt32Private;

unsigned int UInt32_Get(UInt32 * const);
UInt32 *UInt32_Parse(String *, UInt32 * const);
String *UInt32_ToString(UInt32 * const);
bool UInt32_ReferenceEquality(void *, UInt32 * const); 
bool UInt32_Equals(UInt32 *, UInt32 * const);
/* Ctor */
void *UInt32_UInt320(UInt32 *);
void *UInt32_UInt321(unsigned int, UInt32 *);
/* Private method */
static void UInt32Private_Set(unsigned int, UInt32Private * const);

unsigned int UInt32_Get(UInt32 * const this)
{
    return this->UInt32Private->value;
}

UInt32 *UInt32_Parse(String *str, UInt32 * const this)
{
	UInt32 *ret = UInt32_UInt321(0, this);
	
	ret->UInt32Private->value = atoi(str->Get());
	return ret;
}

/*
Char *Int16_ToChar(Int16 *this)
{	
	Char *ret = new Char((char)this->value + '0');
	return ret;
} */

String *UInt32_ToString(UInt32 * const this)
{
	String *ret;
	char *aux = GC_MALLOC(255);
	
	(void)sprintf(aux, "%u", this->UInt32Private->value);
	//return (ret = new String(aux));
	return 0;
}

bool UInt32_ReferenceEquality(void *object, UInt32 * const this)
{
	if(object == (void *)this)
		return true;
	else
		return false;
}

bool UInt32_Equals(UInt32 *check, UInt32 * const this)
{
	return (check->UInt32Private->value == this->UInt32Private->value) ? true : false;
}

/* Ctor */
optimize(0) void *UInt32_UInt320(UInt32 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->UInt320;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(UInt32, Get, 0);
	FUNCTION(UInt32, Parse, 1);
	FUNCTION(UInt32, ToString, 0);
	FUNCTION(UInt32, ReferenceEquality, 1);
	FUNCTION(UInt32, Equals, 1);
	FUNCTION(UInt32, UInt321, 1);
	this->UInt320 = __save_fp;
	this->UInt32Private = Object_create(sizeof(UInt32Private), 1);
	FUNCTIONP(UInt32, Set, 1);
	Object_prepare(&this->UInt32Private->object);
	this->UInt32Private->Set(0);
	Object_prepare(&this->object);
	return 0;
}
void *UInt32_UInt321(unsigned int value, UInt32 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->UInt321;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(UInt32, Get, 0);
	FUNCTION(UInt32, Parse, 1);
	FUNCTION(UInt32, ToString, 0);
	FUNCTION(UInt32, ReferenceEquality, 1);
	FUNCTION(UInt32, Equals, 1);
	FUNCTION(UInt32, UInt320, 1);
	this->UInt321 = __save_fp;
	this->UInt32Private = Object_create(sizeof(UInt32Private), 1);
	FUNCTIONP(UInt32, Set, 1);
	Object_prepare(&this->UInt32Private->object);
	this->UInt32Private->Set(value);
	Object_prepare(&this->object);
	return 0;
}

/* Private method */
static void UInt32Private_Set(unsigned int value, UInt32Private * const this)
{
    this->value = value;
    return;
}
#include "UInt16.h"

typedef struct UInt16Private
{
	Object object;
    unsigned short value;
    void (*Set)(short);
} UInt16Private;

unsigned short UInt16_Get(UInt16 * const);
UInt16 *UInt16_Parse(String *, UInt16 * const);
String *UInt16_ToString(UInt16 * const);
bool UInt16_ReferenceEquality(void *, UInt16 * const); 
bool UInt16_Equals(UInt16 *, UInt16 * const);
/* Ctor */
void *UInt16_UInt160(UInt16 *);
void *UInt16_UInt161(unsigned short, UInt16 *);
/* Private method */
static void UInt16Private_Set(unsigned short, UInt16Private * const);

unsigned short UInt16_Get(UInt16 * const this)
{
    return this->UInt16Private->value;
}

UInt16 *UInt16_Parse(String *str, UInt16 * const this)
{
	UInt16 *ret = UInt16_UInt161(0, this);
	
	ret->UInt16Private->value = atoi(str->Get());
	return ret;
}

/*
Char *Int16_ToChar(Int16 *this)
{	
	Char *ret = new Char((char)this->value + '0');
	return ret;
} */

String *UInt16_ToString(UInt16 * const this)
{
	String *ret;
	char *aux = GC_MALLOC(255);
	
	(void)sprintf(aux, "%d", this->UInt16Private->value);
	//return (ret = new String(aux));
	return 0;
}

bool UInt16_ReferenceEquality(void *object, UInt16 * const this)
{
	if(object == (void *)this)
		return true;
	else
		return false;
}

bool UInt16_Equals(UInt16 *check, UInt16 * const this)
{
	return (check->UInt16Private->value == this->UInt16Private->value) ? true : false;
}

/* Ctor */
optimize(0) void *UInt16_UInt160(UInt16 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->UInt160;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(UInt16, Get, 0);
	FUNCTION(UInt16, Parse, 1);
	FUNCTION(UInt16, ToString, 0);
	FUNCTION(UInt16, ReferenceEquality, 1);
	FUNCTION(UInt16, Equals, 1);
	FUNCTION(UInt16, UInt161, 1);
	this->UInt160 = __save_fp;
	this->UInt16Private = Object_create(sizeof(UInt16Private), 1);
	FUNCTIONP(UInt16, Set, 1);
	Object_prepare(&this->UInt16Private->object);
	this->UInt16Private->Set(0);
	Object_prepare(&this->object);
	return 0;
}
void *UInt16_UInt161(unsigned short value, UInt16 *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->UInt161;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 9);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(UInt16, Get, 0);
	FUNCTION(UInt16, Parse, 1);
	FUNCTION(UInt16, ToString, 0);
	FUNCTION(UInt16, ReferenceEquality, 1);
	FUNCTION(UInt16, Equals, 1);
	FUNCTION(UInt16, UInt160, 1);
	this->UInt161 = __save_fp;
	this->UInt16Private = Object_create(sizeof(UInt16Private), 1);
	FUNCTIONP(UInt16, Set, 1);
	Object_prepare(&this->UInt16Private->object);
	this->UInt16Private->Set(value);
	Object_prepare(&this->object);
	return 0;
}

/* Private method */
static void UInt16Private_Set(unsigned short value, UInt16Private * const this)
{
    this->value = value;
    return;
}
#include "String.h"

typedef struct StringPrivate
{
	Object object;
    char *string;
	void (*SetString)(const char *);
	void (*SetStringLength)(const char *, size_t);
} StringPrivate;

/*String *StringNull_new(void);
String *StringSingle_new(const char *);
String *StringLength_new(const char *, int);
String **StringArray_new(const char *, int);
void *string_overload(int, ...); */

/* Public */
int String_CompareTo(const char *, String * const);
String *String_Concatenate(const char *, String * const);
char *String_Get(String * const);
int String_Length(String * const);
String *String_ToString(String * const);

/* Ctor */
void *String_String0(String *);
void *String_String1(const char *, String *);
void *String_String2(const char *, size_t, String *);

/* Private */
static void StringPrivate_SetString(const char *, StringPrivate * const);
static void StringPrivate_SetStringLength(const char *, size_t, StringPrivate * const);


int String_CompareTo(const char *str, String * const this)
{
	char *str2 = this->StringPrivate->string;
	
	while(*str && (*str == *str2))
		str++, str2++;
	return *(const unsigned char *)str - *(const unsigned char *)str2;
}

String *String_Concatenate(const char *str, String * const this)
{
	String *strAux;
	
	if(str == NULL)
	{
		abort();
		//throw new NullArgumentException();
	}
	strAux = this;
	strAux->StringPrivate->string = GC_REALLOC(strAux->StringPrivate->string, strlen(strAux->StringPrivate->string) + strlen(str) + 1);
	strcat(this->StringPrivate->string, str);
	return this;
}

char *String_Get(String * const this)
{
    return this->StringPrivate->string;
}

int String_Length(String * const this)
{
	return strlen(this->StringPrivate->string);
}

String *String_ToString(String * const this)
{
	return this;
}

/* Ctor */
void *String_String0(String *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->String0;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 5);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(String, CompareTo, 1);
	FUNCTION(String, Concatenate, 1);
	FUNCTION(String, Length, 0);
	FUNCTION(String, Get, 0);
	FUNCTION(String, ToString, 0);
	FUNCTION(String, String1, 1);
	FUNCTION(String, String2, 2);
	this->String0 = __save_fp;
	this->StringPrivate = Object_create(sizeof(StringPrivate), 2);
	FUNCTIONP(String, SetString, 1);
	FUNCTIONP(String, SetStringLength, 2);
	Object_prepare(&this->StringPrivate->object);
	//this->StringPrivate->string = GC_MALLOC(255);
	this->StringPrivate->SetString("");
	Object_prepare(&this->object);
	return 0;
}

void *String_String1(const char *str, String *this)
{
	/* Encapsulate */
	void *__this;
	void *__save_fp = (void *)this->String1;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 5);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(String, CompareTo, 1);
	FUNCTION(String, Concatenate, 1);
	FUNCTION(String, Length, 0);
	FUNCTION(String, Get, 0);
	FUNCTION(String, ToString, 0);
	FUNCTION(String, String0, 1);
	FUNCTION(String, String2, 2);
	this->String1 = __save_fp;
	this->StringPrivate = Object_create(sizeof(StringPrivate), 2);
	FUNCTIONP(String, SetString, 1);
	Object_prepare(&this->StringPrivate->object);
	this->StringPrivate->SetString(str);
	//memcpy(this->StringPrivate->string, str, strlen(str));
	Object_prepare(&this->object);
	return 0;
}

void *String_String2(const char *str, size_t size, String *this)
{
	void *__this;
	void *__save_fp = (void *)this->String2;
	callprotect(&this->object);
	__this = Object_create(sizeof(*this), 5);
	memcpy(this, __this, sizeof(*this));
	FUNCTION(String, CompareTo, 1);
	FUNCTION(String, Concatenate, 1);
	FUNCTION(String, Length, 0);
	FUNCTION(String, Get, 0);
	FUNCTION(String, ToString, 0);
	FUNCTION(String, String0, 1);
	FUNCTION(String, String1, 2);
	this->String2 = __save_fp;
	this->StringPrivate = Object_create(sizeof(StringPrivate), 2);
	FUNCTIONP(String, SetString, 1);
	FUNCTIONP(String, SetStringLength, 2);
	Object_prepare(&this->StringPrivate->object);
	this->StringPrivate->SetStringLength(str, size);
	//memcpy(this->StringPrivate->string, str, size);
	Object_prepare(&this->object);
	return 0;
}

/* Private */
static void StringPrivate_SetString(const char *str, StringPrivate * const this)
{
	this->string = GC_MALLOC(255);
	strcpy(this->string, str);
	this->string[strlen(str)] = '\0';
	return;
}

static void StringPrivate_SetStringLength(const char *str, size_t size, StringPrivate * const this)
{
	this->string = GC_MALLOC(255);
	strcpy(this->string, str);
	this->string[strlen(str)] = '\0';
	return;
}

/*
String **StringArray_new(const char *str, int size)
{
	int i = 0;
	String **this;
	
	if(size < 0)
	{
        abort();
		//throw new ArgumentException();
	}
	else
	{
		this = GC_MALLOC(sizeof(String *) * size);
		if(this == NULL)
		{
            abort();
			//throw new MemoryAccessException("Memoria insuficiente");
		}
		else
		{
            //__exception_push_object(this, func); /* Crear destructor 
            ;
		}
		while(i < size)
		{
			this[i] = new String();
			i++;
		}
	}
	return this;
} */
/*
optimize(0) void *string_overload(int x, ...)
{
    int argLenght;
	va_list ap;
	va_list test;
	char *argString;
	void *testType;
	
	va_start(ap, x);
	va_copy(test, ap); 
	switch(x)
	{
		case 0:
			va_end(ap);
			va_end(test);
			return StringNull_new();
			break;
		case 1:
			argString = va_arg(ap, char *);
			va_end(ap);
			return StringSingle_new((char *)argString);
			break;
		case 2:
			testType = va_arg(test, char *);
			if(strcmp(testType, "String") == 0)
			{
				va_end(test);
				argString = va_arg(ap, char *);
				argLenght = va_arg(ap, int);
				va_end(ap);
				return StringArray_new((char *)argString, argLenght);
			}
			else
			{
				va_end(test);
				argString = va_arg(ap, char *);
				argLenght = va_arg(ap, int);
				va_end(ap);
				return StringLenght_new((char *)argString, argLenght);
			}
			break;
		default:
            abort();
            //throw new ArgumentException();
			break;
	}
	va_end(ap);
	return ((String *)0);
} */

/*
String *StringNull_new(void)
{
	String *this = Object_create(sizeof(String), 5);

	//__exception_push_object(this, func); /* Crear destructor 
	this->StringPrivate->string = GC_malloc(255);
	if(this->StringPrivate->string == NULL)
	{
		GC_FREE(this);
        abort();
        //throw new MemoryAccessException("Memoria insuficiente");
	}
	else
	{
		this->StringPrivate = malloc(sizeof(StringPrivate));
		//__exception_push_object(this->string, func); /* Crear destructor 
	}
	FUNCTION(String, CompareTo, 1);
	FUNCTION(String, Concatenate, 1);
	FUNCTION(String, Length, 0);
	FUNCTION(String, GetString, 0);
	FUNCTION(String, ToString, 0);
	Object_prepare(&this->object);
	return this;
}

String *StringSingle_new(const char *str)
{
	int i = 0;
	String *this = Object_create(sizeof(String), 5);
	
	if(str == NULL)
	{
		GC_FREE(this);
        abort();
        //throw new NullArgumentException();
	}
	else
	{
		this->StringPrivate = malloc(sizeof(StringPrivate));
		//__exception_push_object(this, func); /* Crear destructor 
	}
	this->StringPrivate->string = GC_MALLOC(sizeof(char) * strlen(str) + 1);
	if(this->StringPrivate->string == NULL)
	{
		GC_FREE(this);
        abort();
        //throw new MemoryAccessException("No hay memoria disponible");
	}
	else
	{
		;
		//__exception_push_object(this->string, func); /* Crear destructor 
	}
	FUNCTION(String, CompareTo, 1);
	FUNCTION(String, Concatenate, 1);
	FUNCTION(String, Length, 0);
	FUNCTION(String, GetString, 0);
	FUNCTION(String, ToString, 0);
	while(1)
	{
		this->StringPrivate->string[i] = str[i];
		if(this->StringPrivate->string[i] == '\0')
			break;
		i++;
	}
	this->StringPrivate->string[i] = '\0';
	Object_prepare(&this->object);
	return this;
}

String *StringLength_new(const char *str, int lenght)
{
	int i = 0;
	String *this = Object_create(sizeof(String), 5);
	
	if(str == NULL || lenght > strlen(str))
	{
		GC_FREE(this);
        abort();
        //throw new ArgumentException();
	}
	else
	{
		//__exception_push_object(this, func); /* Crear destructor 
	}
	this->StringPrivate->string = GC_MALLOC(sizeof(char) * lenght + 1);
	if(this->StringPrivate->string == NULL)
	{
		GC_FREE(this);
        abort();
        //throw new MemoryAccessException("No hay memoria disponible");
	}
	else
	{
		this->StringPrivate = malloc(sizeof(StringPrivate));
		//__exception_push_object(this->string, func); /* Crear destructor 
	}
	FUNCTION(String, CompareTo, 1);
	FUNCTION(String, Concatenate, 1);
	FUNCTION(String, Length, 0);
	FUNCTION(String, GetString, 0);
	FUNCTION(String, ToString, 0);
	while(1)
	{
		this->StringPrivate->string[i] = str[i];
		if(i == lenght)
			break;
		i++;
	}
	this->StringPrivate->string[i] = '\0';
	Object_prepare(&this->object);
	return this;
} */

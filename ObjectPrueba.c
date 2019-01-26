#include "ObjectPrueba.h"

void *Object_trampoline(Object *, void *, int);
void Object_destroy(Object *);
void *Object_create(size_t, int);
void Object_prepare(Object *);
void callprotect(Object *);
void *Object_stacked(Object *, int); 
char *isPtrOnStack(void *); 
bool isList(char *); 
void *getListBase(const char *);
void *getStdPtrBase(const char *);
void *Object_stackAlloc(size_t, int);
void __initialize_virtual_table(vtable **, int *);
void __register_virtual_method(vtable *, int *, char *, void (*)(), Object *);
bool __chk_func_override(char *, char *);
void __register_overriden_method(vtable *, void *, int *, char *, int, void *, Object *);

void *Object_trampoline(Object *this, void *target, int argCount)
{
	unsigned char opcode[][2] = {
		0x48, 0xbf,
		0x48, 0xbe,
		0x48, 0xba,
		0x48, 0xb9,
		0x49, 0xb8,
		0x49, 0xb9,
	};

	memcpy(this->codePagePtr, opcode[argCount], sizeof(opcode[argCount]));
	memcpy(this->codePagePtr + 2, &this, sizeof(void *));
	memcpy(this->codePagePtr + 10, kTrampoline + 10, sizeof(kTrampoline) - 10);
	memcpy(this->codePagePtr + 16, &target, sizeof(void *));
	this->codePagePtr += sizeof(kTrampoline);
	return this->codePagePtr - sizeof(kTrampoline);
}

void Object_destroy(Object *this)
{
	int ret = munmap(this->codePage, this->codePageSize);

	assert(!ret);
}

/* Method which creates an object on the heap */
void *Object_create(size_t size, int functionCount)
{
	Object *this = GC_MALLOC(size);

	functionCount += 1;
	this->codePageSize = functionCount * sizeof(kTrampoline);
	this->codePageSize = 4096;
	this->codePage = mmap(NULL, this->codePageSize, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	this->codePagePtr = this->codePage;
	this->destroy = Object_trampoline(this, Object_destroy, 0);
	return this;
}

void Object_prepare(Object *this)
{
	int ret = mprotect(this->codePage, this->codePageSize, PROT_READ | PROT_EXEC);

	return (void)assert(!ret);
}

void callprotect(Object *this)
{
	return (void)(!mprotect(this->codePage, this->codePageSize, PROT_READ | PROT_WRITE));
}

void *Object_stacked(Object *this, int functionCount)
{
	functionCount++;
	this->codePageSize = functionCount * sizeof(kTrampoline);
	this->codePageSize = 4096;
	this->codePage = mmap(NULL, this->codePageSize, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	this->codePagePtr = this->codePage;
	this->destroy = Object_trampoline(this, Object_destroy, 0);
	return this;
}

optimize(0) char *isPtrOnStack(void *ptr)
{
	void *stackTop = 0; /* Where Stack starts; higher address */
	void *stackLow = 0; /* Where RSP points to */

	/* Avoid optimizations */
	__asm__ __volatile__
	(
		"mov %%fs:4, %%rax\n" /* Stack base (Start address) */
		"mov %%rax, %0\n"	 /* Set position into variable */
		"mov %%fs:8, %%rax\n" /* Get where RSP points to */
		"mov %%rax, %1\n"	 /* Set position into variable */
		: /* Output (None) */
		: "g"(stackTop), "g"(stackLow) /* Input variables. General purpose */
		: "ax" /* Clobbered register */
	);
	/* Check if pointer is inside the stack */
	if (ptr <= stackTop && ptr >= stackLow)
		return "True"; /* If so, return True */
	else
		return "False"; /* Else, return False */
} 

/* Single check if a Generic List was created */
bool isList(char *type) 
{
	int i = 0;
	char *__shallow = GC_MALLOC(strlen(type) + 1);
	char *__cmp;
	char *__cmp2 = "List_";

	strcpy(__shallow, type);
	__cmp = strtok(__shallow, "IUS");
	return (strcmp(__cmp, __cmp2) == 0) ? 1 : 0;
} 

/* If so, get the constructor and call it */
void *getListBase(const char *func)
{
	Elf64_Shdr *shdr;
	Elf64_Ehdr *ehdr;
	Elf *elf;
	Elf_Scn *scn;
	Elf_Data *data;
	int cnt;
	void *(*L_FP)(void) = NULL;
	int fd = 0;
	/* This is probably Linux specific - Read in our own executable*/
	if ((fd = open("/proc/self/exe", O_RDONLY)) == -1)
		exit(1);
	elf_version(EV_CURRENT);
	if ((elf = elf_begin(fd, ELF_C_READ, NULL)) == NULL)
	{
		fprintf(stderr, "File is not an ELF binary\n");
		exit(1);
	}
	/* Let's get the elf sections */
	if (((ehdr = elf64_getehdr(elf)) == NULL) || ((scn = elf_getscn(elf, ehdr->e_shstrndx)) == NULL) || ((data = elf_getdata(scn, NULL)) == NULL))
	{
		fprintf(stderr, "Failed to retrieve header ELF information\n");
		exit(1);
	}
	/* Let's go through each elf section looking for the symbol table */
	for (cnt = 1, scn = NULL; scn = elf_nextscn(elf, scn); cnt++)
	{
		if ((shdr = elf64_getshdr(scn)) == NULL)
			exit(1);
		if (shdr->sh_type == SHT_SYMTAB)
		{
			char *name;
			char *strName;
			data = 0;
			if ((data = elf_getdata(scn, data)) == 0 || data->d_size == 0)
			{
				fprintf(stderr, "No Symbol Table is available\n");
				exit(1);
			}
			Elf64_Sym *esym = (Elf64_Sym *)data->d_buf;
			Elf64_Sym *lastsym = (Elf64_Sym *)((char *)data->d_buf + data->d_size);
			/* Look through all symbols */
			for (; esym < lastsym; esym++)
			{
				if ((esym->st_value == 0) || (ELF64_ST_BIND(esym->st_info) == STB_WEAK) || (ELF64_ST_BIND(esym->st_info) == STB_NUM) || (ELF64_ST_TYPE(esym->st_info) != STT_FUNC))
					continue;
				name = elf_strptr(elf, shdr->sh_link, (size_t)esym->st_name);
				if (!name)
				{
					fprintf(stderr, "%s\n", elf_errmsg(elf_errno()));
					exit(-1);
				}
				/* This could obviously be a generic string */
				if (!strcmp(func, name))
				{
					L_FP = (void *(*)(void))esym->st_value;
				}
			}
			elf_end(elf);
		}
	}
	return L_FP(); // Cambiar
}

void *getStdPtrBase(const char *func)
{
	Elf64_Shdr *shdr;
	Elf64_Ehdr *ehdr;
	Elf *elf;
	Elf_Scn *scn;
	Elf_Data *data;
	int cnt;
	void *(*ClassPtr)(void) = NULL;
	int fd = 0;
	/* This is probably Linux specific - Read in our own executable*/
	if ((fd = open("/proc/self/exe", O_RDONLY)) == -1)
		exit(1);
	elf_version(EV_CURRENT);
	if ((elf = elf_begin(fd, ELF_C_READ, NULL)) == NULL)
	{
		fprintf(stderr, "File is not an ELF binary\n");
		exit(1);
	}
	/* Let's get the elf sections */
	if (((ehdr = elf64_getehdr(elf)) == NULL) || ((scn = elf_getscn(elf, ehdr->e_shstrndx)) == NULL) || ((data = elf_getdata(scn, NULL)) == NULL))
	{
		fprintf(stderr, "Failed to retrieve ELF header information\n");
		exit(1);
	}
	/* Let's go through each elf section looking for the symbol table */
	for (cnt = 1, scn = NULL; scn = elf_nextscn(elf, scn); cnt++)
	{
		if ((shdr = elf64_getshdr(scn)) == NULL)
			exit(1);
		if (shdr->sh_type == SHT_SYMTAB)
		{
			char *name;
			char *strName;
			data = 0;
			if ((data = elf_getdata(scn, data)) == 0 || data->d_size == 0)
			{
				fprintf(stderr, "No Symbol Table is available\n");
				exit(1);
			}
			Elf64_Sym *esym = (Elf64_Sym *)data->d_buf;
			Elf64_Sym *lastsym = (Elf64_Sym *)((char *)data->d_buf + data->d_size);
			/* Look through all symbols */
			for (; esym < lastsym; esym++)
			{
				if ((esym->st_value == 0) || (ELF64_ST_BIND(esym->st_info) == STB_WEAK) || (ELF64_ST_BIND(esym->st_info) == STB_NUM) || (ELF64_ST_TYPE(esym->st_info) != STT_FUNC))
					continue;
				name = elf_strptr(elf, shdr->sh_link, (size_t)esym->st_name);
				if (!name)
				{
					fprintf(stderr, "%s\n", elf_errmsg(elf_errno()));
					exit(-1);
				}
				/* This could obviously be a generic string */
				if (!strcmp(func, name))
				{
					//printf("Encontrado %s en %lx\n", func, esym->st_value);
					ClassPtr = (void *(*)(void))esym->st_value;
				}
			}
			/* Call and hope we don't segfault!*/
			elf_end(elf);
		}
	}
	return ClassPtr();
}

void *Object_stackAlloc(size_t size, int functionCount)
{
	Object *this = alloca(size); 

	functionCount += 1;
	this->codePageSize = functionCount * sizeof(kTrampoline);
	this->codePageSize = 4096;
	this->codePage = mmap(NULL, this->codePageSize, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	this->codePagePtr = this->codePage;
	this->destroy = Object_trampoline(this, Object_destroy, 0);
	return this;
}

optimize(0) void __initialize_virtual_table(vtable **vmt, int *__vptrFlag)
{
	(*vmt) = GC_MALLOC(sizeof(vtable) * 100);
	(*__vptrFlag) = true;
	return;
}

optimize(0) void __register_virtual_method(vtable *vmt, int *__count, char *__f, void (*__fptr)(), Object *this)
{
	vmt[*__count].__chk_v += ((*__count) + 100);
	vmt[*__count].__func = __f;
	vmt[*__count].vptr = __fptr;
	(*__count)++;
	return Object_prepare(this);
}

optimize(0) bool __chk_func_override(char *vptr, char *chk)
{
	int ret;
	char *tok = GC_MALLOC(strlen(vptr) + 1);

	strcpy(tok, vptr);
	tok[strlen(vptr)] = '\0';
	tok = strtok(tok, "_");
	tok = strtok(NULL, "_");
	return (!strcmp(tok, chk)) ? true : false;
}

optimize(0) void __register_overriden_method(vtable *vmt, void *__t, int *__c, char *__f, int argCount, void *ptr, Object * this)
{
	int _it = 0;

	while(_it < (*__c))
	{
		if(__chk_func_override(vmt[_it].__func, __f))
		{
			callprotect(this);
			ptr = Object_trampoline(this, __t, argCount);
			vmt[_it].vptr = ptr;
			Object_prepare(this);
			break;
		}
		else
			_it++;
	}
	if(_it == (*__c))
	{
		throw new DataNotFoundException();
	}
	return; /* Never reached */
}
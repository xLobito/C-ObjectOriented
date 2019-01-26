#include "ObjectPrueba.h"

typedef struct A
{
    Object object;
    struct
    {
        int __vptrCount;
        int __vptrFlag;
    };
    vtable(A);
    #define A(args...) overload(A, args);
    void *(*A0)(void);
    void (*$A)(void);
    void (*virtualFunc)(void);
    void (*virtualFunc2)(void);
} A;

typedef struct B
{
    A;
    vtable(B);
    #define B(args...) overload(B, args);
    void *(*B0)(void);
    void (*$B)(void);
} B;

void *A_A0(A *);
void A_virtualFunc(int, A * const);
void A_virtualFunc2(A * const);
void A_$A(A * const);
void *B_B0(B * const);
void B_virtualFunc(int, B * const);
void B_virtualFunc2(B * const);
void B_$B(B * const);

int main(void)
{
    A *a = new Instance(A, 0);
    B *b = new Instance(B, 0);
    
    a->A();
    a->vmtA[0].vptr(1);
    a->vmtA[1].vptr();
    b->B();
    b->vmtB[0].vptr(1);
    b->vmtB[1].vptr();
    return 0;
}

optimize(0) void *A_A0(A * const this)
{
    destructor(A, $A, 0);
    this->__vptrCount = 0;
    this->__vptrFlag = 0;
    virtual(A, virtualFunc, 1);
    virtual(A, virtualFunc2, 0);
    return 0;
}

void A_virtualFunc(int a, A * const this)
{
    Console->WriteLine("En %s", __func__);
    return;
}

void A_virtualFunc2(A * const this)
{
    Console->WriteLine("En %s", __func__);
    return;
}

void A_$A(A * const this)
{
    Console->WriteLine("Destruyendo A");
    return;
}

void *B_B0(B *this)
{
    Console->WriteLine("Construyendo B");
    base(A);
    this->vmtB = this->vmtA; 
    destructor(B, $B, 0);
    override(B, virtualFunc, 1); 
    override(B, virtualFunc2, 0);
    base->virtualFunc(); 
    return 0;
}

void B_virtualFunc(int a, B * const this)
{
    Console->WriteLine("En %s", __func__);
}

void B_virtualFunc2(B * const this)
{
    Console->WriteLine("En %s", __func__);
}

void B_$B(B * const this)
{
    Console->WriteLine("Destruyendo B");
}

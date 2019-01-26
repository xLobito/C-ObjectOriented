#include "ObjectPrueba.h"

int main(void)
{
    //String *a = new StringBuilder("Hola mundo"); /* Usar Instance para evaluar la cantidad de argumentos (Function Hooking) */
    String *a = new Instance(String, 0);
    String *b = new Instance(String, 1);
    String *c = new Instance(String, 2);
    Int16 *d = new Instance(Int16, 0);
    Int16 *e = new Instance(Int16, 1);
    Int32 *f = new Instance(Int32, 0);
    Int32 *g = new Instance(Int32, 1);
    Int64 *h = new Instance(Int64, 0);
    Int64 *i = new Instance(Int64, 1);
    UInt16 *j = new Instance(UInt16, 0);
    UInt16 *k = new Instance(UInt16, 1);
    UInt32 *l = new Instance(UInt32, 0);
    UInt32 *m = new Instance(UInt32, 1);
    UInt64 *n = new Instance(UInt64, 0);
    UInt64 *o = new Instance(UInt64, 1);
    Char *p = new Instance(Char, 0);
    Char *q = new Instance(Char, 1);
    //Float *r = new Instance(Float, 0);
    //Float *s = new Instance(Float, 1);
    List(Int16) *t = new Generic(List(Int16));

    /*
    a->String();
    b->String("Hola mundo");
    c->String("Chao mundo", strlen("Chao mundo"));
    d->Int16();
    e->Int16(10);
    f->Int32();
    g->Int32(20);
    h->Int64();
    i->Int64(30);
    j->UInt16();
    k->UInt16(40);
    l->UInt32();
    m->UInt32(50);
    n->UInt64();
    o->UInt64(60);
    p->Char();
    q->Char('c');
    //r->Float();
    //s->Float(1.0);
    a->Get();
    printf("%s\n", b->Get());
    printf("%s\n", c->Get());
    printf("Length b: %d\n", b->Length());
    printf("Lenght c: %d\n", c->Length());
    printf("%s\n", a->Concatenate("Probando Concatenate")->Get());
    printf("Valor d: %d\n", d->Get());
    printf("Valor e: %d\n", e->Get());
    printf("Valor f: %d\n", f->Get());
    printf("Valor g: %d\n", g->Get());
    printf("Valor h: %ld\n", h->Get());
    printf("Valor i: %ld\n", i->Get());
    printf("Valor j: %d\n", j->Get());
    printf("Valor k: %d\n", k->Get());
    printf("Valor l: %d\n", l->Get());
    printf("Valor m: %d\n", m->Get());
    printf("Valor n: %u\n", n->Get());
    printf("Valor o: %u\n", o->Get());
    printf("Valor p: %c\n", p->Get());
    printf("Valor q: %c\n", q->Get());
    //printf("Valor r: %f\n", r->Get());
    //printf("Valor s: %f\n", s->Get());
    printf("ToString (Char): %s\n", q->ToString()->Get()); */
    e->Int16(10);
    d->Int16();
    t->Append(e);
    t->Append(d);
    t->Delete(1);
    t->Show();
    try
    {
        throw new Exception();
    }
    catch(MemoryAccessException e)
    {
        Console->WriteLine(e->ExceptionMessage);
        //printf("%s\n", e->ExceptionMessage);
    }
    catch(FormatException e2)
    {
        Console->WriteLine(e2->ExceptionMessage);
        //printf("%s\n", e2->ExceptionMessage);
    }
    catch(Exception e3)
    {
        Console->WriteLine(e3->ExceptionMessage);
        //printf("%s\n", e3->ExceptionMessage);
    }
    finally
    {
        Console->WriteLine("Out");
        //printf("Out\n");
    }
    return 0;
}
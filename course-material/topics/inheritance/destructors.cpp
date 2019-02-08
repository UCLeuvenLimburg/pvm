struct A { };
struct B : public A { };
struct C : public B { };

C* p = new C;
delete p; // destruction

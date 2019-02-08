class A { };
class B1 : public A { };
class B2 : private A { };

void foo(const A&);

B1 b1;
B2 b2;

foo(b1); // ok
foo(b2); // not ok

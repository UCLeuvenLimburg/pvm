class A { }
class B extends A { }

void foo(A a) { }

B b = new B();
foo(b); // Ok, B is subtype of A



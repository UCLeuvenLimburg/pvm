struct A {
  A(int);
};

struct B : public A {
  B() : A(0) { }
};

struct C : public B {
  C() { } // calls B::B() implicitly
};

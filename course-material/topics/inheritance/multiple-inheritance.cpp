struct A {
  int x;
};

struct B1 : public A { };
struct B2 : public A { };

struct C : public B1, public B2 { };

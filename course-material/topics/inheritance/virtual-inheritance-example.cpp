struct A {
  int x;
};

struct B1 : public virtual A { };
struct B2 : public virtual A { };

struct C : public B1, public B2 { };

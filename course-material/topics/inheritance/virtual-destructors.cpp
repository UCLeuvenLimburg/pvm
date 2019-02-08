struct A { };

struct B : public A {
  int* data;

  ~B() { delete[] data; }
};

A* p = new B();

// Would call A::~A(), not B::~B()
// due to the fact that A::~A() is
// not virtual
delete p;

// Memory leak! data never freed

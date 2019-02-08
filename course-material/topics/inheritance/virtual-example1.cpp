struct A {
  virtual void foo() { print("A"); }
};

struct B : public A {
  void foo() override { print("B"); }
};

A* aa = new A();
A* ab = new B();
B* bb = new B();

aa->foo();`\only<2->{ // A}`
ab->foo();`\only<3->{ // B}`
bb->foo();`\only<4->{ // B}`

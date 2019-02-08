#include <iostream>

class Foo {
public:
  void bar() { std::cout << "A"; }
  void bar() const { std::cout << "B"; }
};

int main() {
  Foo* p = new Foo();
  const Foo* q = p;

  p->bar(); // prints A
  q->bar(); // prints B

  delete p;
}

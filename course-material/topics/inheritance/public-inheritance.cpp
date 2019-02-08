class A {
public:
  int x;
};

class B : public A { };

void foo()
{
  B b;

  b.x = 5; // Ok, x is public member of B
}

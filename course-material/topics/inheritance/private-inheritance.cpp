class A {
public:
  int x;
};

class B : private A { };

void foo()
{
  B b;

  b.x = 5; // Error, x not accessible
}

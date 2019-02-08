class Foo {
public:
  Foo(int);
  Foo(bool, double);
};

std::make_unique<Foo>(5); // ok
std::make_unique<Foo>(true, 5.0); // ok
std::make_unique<Foo>(false); // not ok

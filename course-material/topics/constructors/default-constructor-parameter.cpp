class Foo {
public:
    Foo(const Foo&) { std::cout << 'C'; }
};

void bar(Foo f) { }

Foo foo;
bar(foo); // Call by value, copies foo
          // therefore prints C

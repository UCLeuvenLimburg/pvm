class Foo {
public:
    Foo()           { std::cout << "D"; }
    Foo(const Foo&) { std::cout << "C"; }
};

Foo bar() { return Foo(); }

Foo foo = bar();

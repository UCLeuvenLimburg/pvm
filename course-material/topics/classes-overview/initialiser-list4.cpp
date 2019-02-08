class Foo {
public:
    Foo(int x) { }
};

class Bar {
    Foo foo1, foo2;

public:
    Bar() : foo1(5) { } // Error
};

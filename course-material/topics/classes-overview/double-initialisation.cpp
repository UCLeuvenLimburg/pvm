class Foo {
public:
    Foo()    { }
    Foo(int) { }
};

class Bar {
    Foo foo;

public:
    Bar() {
        foo = Foo(5);
    }
};

class Foo {
public:
    Foo() { }
    Foo(int x) { }
};

class Bar {
    Foo foo1, foo2;

public:
    Bar() : foo1(5)`\only<2->{\color{red}\ttfamily, foo2()}` { }
};

class Foo {
public:
    Foo(const Foo&) { std::cout << 'C'; }
};

Foo bar() {
    Foo f;
    return f;
}

// bar's return value gets copied to x
Foo x = bar(); // Prints C

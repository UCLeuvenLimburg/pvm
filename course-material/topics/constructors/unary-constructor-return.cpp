class Foo {
public:
    Foo(int) { std::cout << "U"; }
};

Foo bar() {
    return 4; // prints U
}

int main() {
    bar();
}

class Foo {
public:
    Foo(int) { std::cout << "U"; }
};

int main() {
    Foo* foo = new Foo(5); // prints U
}

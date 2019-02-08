class Foo {
public:
    Foo(int) { std::cout << "U"; }
};

int main() {
    Foo foo = 5; // alt. syntax, prints U
}

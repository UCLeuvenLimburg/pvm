class Foo {
public:
    int x;
};

int main() {
    // Creates object on stack
    // Immediately ready for use
    Foo foo;

    foo.x = 5;
}

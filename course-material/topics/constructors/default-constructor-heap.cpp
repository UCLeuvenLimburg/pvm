class Foo {
public:
  Foo() { std::cout << "D"; }
};

int main() {
  Foo* p = new Foo; // prints D
}

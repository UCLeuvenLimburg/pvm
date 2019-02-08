class Foo {
public:
  Foo() { std::cout << "D"; }
};

int main() {
  Foo x; // prints D
}

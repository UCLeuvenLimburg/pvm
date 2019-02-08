class Foo {
public:
  Foo() { std::cout << "D"; }
};

int main() {
  Foo* p = new Foo[5]; // prints DDDDD
}

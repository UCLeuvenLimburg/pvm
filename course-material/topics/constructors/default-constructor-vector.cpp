class Foo {
public:
  Foo() { std::cout << "D"; }
};

int main() {
  std::vector<Foo> foo(3); // prints DDD
}

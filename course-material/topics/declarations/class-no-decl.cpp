class Foo {
public:
  void foo() {
    bar(); // compiles just fine
  }
  
  void bar();
};

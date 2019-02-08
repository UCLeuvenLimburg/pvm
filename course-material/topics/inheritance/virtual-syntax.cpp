struct A {
  virtual void bar();
};

struct B : public A {
  void bar() override;
};

struct Quackable {
  virtual void quack() = 0;
}

struct Bird {
  virtual void fly() = 0;
}

class Duck : public Bird, public Quackable {
  void fly() override { ... }
  void quack() override { ... }
}

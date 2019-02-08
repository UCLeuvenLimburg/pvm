interface Quackable {
  void quack();
}

abstract class Bird {
  public abstract void fly();
}

class Duck extends Bird implements Quackable {
  @Override
  void fly() { ... }

  @Override
  void quack() { ... }
}

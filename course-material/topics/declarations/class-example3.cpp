// Mixed declarations and definitions
class Counter {
private:
  int x;

public:
  Counter() : x(0) { }
  void increment() { x++; }
  int read();
};

int Counter::read()
{
  return x;
}

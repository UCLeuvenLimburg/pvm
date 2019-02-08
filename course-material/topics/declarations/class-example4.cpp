// Mixed declarations and definitions
class Counter {
private:
  int x;

public:
  Counter() : x(0) { }
  void increment() { x++; }
};

// WRONG!
// Class declaration does not mention read
int Counter::read()
{
  return x;
}

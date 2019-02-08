// Declaration
class Counter {
private:
  int x;

public:
  Counter();
  void increment();
  int read();
};

// Member function definitions
Counter::Counter() : x(0) { }
void Counter::increment() { x++; }
int Counter::read() { return x; }

// Full definition
class Counter {
private:
  int x;

public:
  Counter() : x(0) { }
  void increment() { x++; }
  int read() { return x; }
};

class OilTank {
  int contents, capacity;

public:
  OilTank()
    : `\pgfmark{constructor delegation nullary start}`OilTank(0, 1000)`\pgfmark{constructor delegation nullary end}` { }

  OilTank(int capacity)
    : `\pgfmark{constructor delegation unary start}`OilTank(0, capacity)`\pgfmark{constructor delegation unary end}` { }
  
  OilTank(int contents, int capacity)
    : contents(contents),
      capacity(capacity) { }
};

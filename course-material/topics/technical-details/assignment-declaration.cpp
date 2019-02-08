Bar foo() { return Bar(); }

Bar bar;           // Bar::Bar()
Bar bar2 = bar;    // Bar::Bar(const Bar&)
Bar bar3 = foo();  // Bar::Bar(const Bar&)

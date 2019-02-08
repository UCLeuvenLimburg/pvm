Bar foo() { return Bar(); }

Bar bar;
bar = foo();    // Bar::operator =(const Bar&)
Bar bar2 = bar; // Bar::Bar(const Bar&)
bar2 = bar;     // Bar::operator =(const Bar&)

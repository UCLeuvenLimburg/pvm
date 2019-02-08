Bar bar;          // Bar::Bar()
Bar& bar2 = bar;  // bar2 is an alias for bar
Bar bar3;         // Bar::Bar()  
bar2 = bar3;      // Bar::operator =(const Bar&)
Bar& bar5;        // Error

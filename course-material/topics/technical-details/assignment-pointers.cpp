Bar* foo() { return new Bar; }

Bar bar;         // Bar::Bar()
Bar* p = &bar;   // Pointer assignment
Bar* q = foo();  // Pointer assignment
Bar* r = q;      // Pointer assignment

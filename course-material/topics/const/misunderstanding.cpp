void foo(const int* x);

int x = 5;
const int y = 6;

// Does this work?
foo(&x);

// Does this work?
foo(&y);

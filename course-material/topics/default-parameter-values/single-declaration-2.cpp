// Declaration
void foo(int x = 1);

// Ok: default value known from declaration
foo();

// Error! Second time default
// value is encountered
void foo(int x = 1) { ... }

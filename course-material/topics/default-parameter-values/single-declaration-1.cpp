// Declaration
void foo(int x = 1);

// Ok: default value known from declaration
foo();

// Definition
void foo(int x) { ... }

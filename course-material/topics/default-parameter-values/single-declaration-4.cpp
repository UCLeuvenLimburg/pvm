// Declaration
void foo(int x);

// Error: compiler thinks there no default values
// Cannot look into the future
foo();

// Defaults defined here
void foo(int x = 1) { ... }

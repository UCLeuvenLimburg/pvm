// No mention of default value
void foo(int x);

// Ok, since no need for default value
foo(3);

// Definition
void foo(int x = 1) { ... }

// Ok, default values are known
foo();

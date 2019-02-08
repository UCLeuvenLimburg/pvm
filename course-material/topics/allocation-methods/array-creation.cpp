// Size known at compile-time: ok
int ns[5];

// Size computed at runtime: not ok
int array_size = readIntFromFile();
int* ns = new int[array_size];

int x = 1, y = 2;
const int* const p = &x;

*p = 5;    // Forbidden
p = &y;    // Forbidden

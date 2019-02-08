int x = 1, y = 2;
int* const p = &x;

*p = 5;   // Allowed
p = &y;   // Forbidden

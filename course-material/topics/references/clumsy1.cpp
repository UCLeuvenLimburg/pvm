int x = 5;
int* p = &x;

*p++;   // Uh oh! Are you sure?
(*p)++; // You probably meant this

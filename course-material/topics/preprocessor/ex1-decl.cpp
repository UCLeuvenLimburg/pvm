// Declarations
bool foo();
double bar(int);
int qux(int);

// Definitions
bool foo()        { return bar(1)>0; }
double bar(int x) { return qux(x) / 2.0; }
int qux(int x)    { return x * x; }

int_array xs;
const int_array ys;

// Reading
int a = xs[i];     // calls at(index)
int b = ys[i];     // calls at(index) const
int& r1 = xs[i];   // ok
int& r2 = ys[i];   // does not compile

// Writing
xs[i]++;           // calls at(index)
ys[i]++;           // does not compile

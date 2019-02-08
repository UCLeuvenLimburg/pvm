// Forward declaration of bar
int bar(bool x);

int foo(double x) {
  return bar(false);
}

int bar(bool x) {
  return foo(0);
}

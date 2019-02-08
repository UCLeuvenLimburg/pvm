// Forward declarations for both
int foo(double x);
int bar(bool x);

int foo(double x) {
  return bar(false);
}

int bar(bool x) {
  return foo(0);
}

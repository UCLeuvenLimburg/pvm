// Forward declaration of foo
int foo(double x);

int bar(bool x) {
  return foo(0);
}

int foo(double x) {
  return bar(false);
}

int bar(bool x) {
  return foo(0);
}

int foo(double x) {
  return bar(false);
}

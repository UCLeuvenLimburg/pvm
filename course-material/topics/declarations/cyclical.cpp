int foo(double x) {
  return bar(false);
}

int bar(bool x) {
  return foo(0);
}

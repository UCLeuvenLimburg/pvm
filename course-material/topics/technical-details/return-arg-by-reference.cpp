Bar* foo(Bar& b) {
  return &b;
}

Bar bar;
Bar* p = foo(bar);

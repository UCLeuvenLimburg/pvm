Bar& foo() {
  return *new Bar();
}

Bar& bar = foo();
delete &bar; // This is just weird


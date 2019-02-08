void bar(smart_pointer<T> p) { ... }

void foo() {
  smart_pointer<T> p(new T);

  // bar would receive a copy of p
  // there would be two owners
  // we need to prevent this
  bar(p);
}

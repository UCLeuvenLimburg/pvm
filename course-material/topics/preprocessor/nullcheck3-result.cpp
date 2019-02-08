void foo(int* ptr) {
  if ( ptr == nullptr )
    fail("ptr is null", "X.cpp", 5);

  /* ... */
}

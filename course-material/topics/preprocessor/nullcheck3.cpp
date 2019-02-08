#define NULLCHECK(p) if ( p == nullptr ) \
    fail(#p " is null", __FILE__, __LINE__ );

void foo(int* ptr) {
  NULLCHECK(ptr);

  /* ... */
}

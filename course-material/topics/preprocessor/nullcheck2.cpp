#define NULLCHECK(p) if ( p == nullptr ) \
                       fail(#p " is null" );


void foo(int* ptr) {
  NULLCHECK(ptr);

  /* ... */
}

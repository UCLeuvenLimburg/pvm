#define NULLCHECK(p) if ( p == nullptr ) \
                       fail();

void foo(int* ptr)
{
  NULLCHECK(ptr);

  /* ... */
}

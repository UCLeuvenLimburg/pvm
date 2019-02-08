void foo()
{
  T t;
  U u;
  X x;
  
  // ...

  return; // t, u, x get destroyed
}

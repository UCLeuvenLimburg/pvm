void foo()
{
  T* p = new T;

  // NO destructor on T-object called!
  // It's the pointer p that's
  // going out of scope,
  // not the object itself
  // Use delete p to prevent leak
}

void foo(const Person&);

template<typename T>
class smart_pointer {
  T* p;
public:
  // ...
  T& operator *() { return *p; }
};

smart_pointer<Person> p(new Person);

// Works
foo(*p);

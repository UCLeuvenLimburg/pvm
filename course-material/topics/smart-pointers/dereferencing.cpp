void foo(const Person& p);

smart_pointer<Person> p(new Person);

foo(p);  // mustn't work
foo(*p); // should work

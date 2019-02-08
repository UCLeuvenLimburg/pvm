smart_pointer<Person> p(new Person);

// Current syntax
std::string name = p.get()->getName();

// Ideal syntax
std::string name = p->getName();

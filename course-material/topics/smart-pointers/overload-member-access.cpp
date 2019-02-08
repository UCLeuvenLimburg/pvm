template<typename T>
class smart_pointer {
  T* p;
public:
  // ...
  T* operator ->() { return p; }
};

smart_pointer<Person> p(new Person);

// Valid syntax
std::string name = p->getName();

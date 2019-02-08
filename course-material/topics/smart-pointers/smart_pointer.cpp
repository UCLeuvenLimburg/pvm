template<typename T> class smart_pointer {
  T* p;  // Pointer
    
public:
  // Constructor receives pointer
  smart_pointer(T* p) : p(p) { }

  // Destructor frees memory
  ~smart_pointer() { delete p; }

  // Gives access to pointer
  T* get() { return p; }
};

void foo() {
  smart_pointer<Person> p(new Person);
  // stuff
}

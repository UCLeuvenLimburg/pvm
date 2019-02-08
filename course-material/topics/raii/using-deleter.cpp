class deleter {
  int* p;
public:
  deleter(int* p) : p(p) { }
  ~deleter() { delete[] p; }
};

void foo()
{
  int* p = new int[10];
  deleter deleter_p(p);

  // ...
  
  // deleter_p goes out of scope here
  // its destructor gets called
  // destructor frees memory
}

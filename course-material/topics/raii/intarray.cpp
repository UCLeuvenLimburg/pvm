class intarray {
  int* elts;

public:
  intarray(int size)
    : elts( new int[size] ) { }

  ~intarray() {
    delete[] elts;
  }
};

void foo() {
  intarray ns(10);
  // ...
  // ns's destructor gets called here
}

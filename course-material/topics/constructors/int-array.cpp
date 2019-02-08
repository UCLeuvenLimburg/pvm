class IntArray {
  int *ns, size;

public:
  IntArray(int size)
    : ns(new int[size]), size(size) { }

  IntArray(IntArray&& other)
    : ns(other.ns), size(other.ns) {
    // DO NOT FORGET THIS
    other.ns = nullptr;
    other.size = 0;
  }

  ~IntArray() { delete[] ns; }
};

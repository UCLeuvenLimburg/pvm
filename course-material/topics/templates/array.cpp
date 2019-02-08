`\pgfmark{array template start}`template<typename T>`\pgfmark{array template end}`
class Array {
  T*  _xs;
  int _size;

public:
  // Constructor
  Array(int size) : _xs(new T[size]), _size(size) { }

  // Destructor
  ~Array() { delete[] _xs; }

  // Indexing
        T& operator[](int i)       { return _xs[i]; }
  const T& operator[](int i) const { return _xs[i]; }

  // Size
  int size() const { return _size; }
};

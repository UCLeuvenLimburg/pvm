template<typename T> class Array {
  T* _xs;
  int _size;

public:
  // Only sensible for addable types
  T sum() const {
    T result = 0;

    for ( int i = 0; i != _size; ++i )
      result += _xs[i];

    return result;
  }
};

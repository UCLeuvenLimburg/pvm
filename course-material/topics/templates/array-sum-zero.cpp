T sum() const {
  T result = `\pgfmark{array sum zero start}`typeinfo<T>::zero()`\pgfmark{array sum zero end}`;

  for ( int i = 0; i != _size; ++i )
    result += _xs[i];

  return result;
}

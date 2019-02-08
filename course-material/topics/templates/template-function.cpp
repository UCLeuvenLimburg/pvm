template<typename T>
T sum(const std::vector<T> ns)
{
  T result = typeinfo<T>::zero();

  for ( const T& n : ns )
    result += n;

  return result;
}

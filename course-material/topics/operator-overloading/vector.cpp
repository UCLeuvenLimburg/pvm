template<typename T>
class vector
{
  T* items;

public:
        T& operator[](int index);
  const T& operator[](int index) const;
};

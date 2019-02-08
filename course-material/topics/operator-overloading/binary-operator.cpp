// As member function
struct T {
    T operator *(const T& other) { ... }
};

// As global function
T operator *(const T& t, const T& u)
{
    ...
}

T t, u;
T product = t * u;

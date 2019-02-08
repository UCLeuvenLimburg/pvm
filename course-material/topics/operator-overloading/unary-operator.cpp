// Either as member function
struct T {
    T operator !() const;
}

// or as global function
T operator !(const T& t) { ...  }

// Usage
T t;
T anti_t = !t;


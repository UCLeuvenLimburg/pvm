template<typename T> class smart_ptr
{
public:
  // Explicit "no copy constructor"
  smart_ptr(const smart_ptr&) = delete;

  // Explicit "no assignment"
  smart_ptr&
    operator =(const smart_ptr&) = delete;
};

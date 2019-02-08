class int_array {
  int* ns;
public:
  // Nonconst at returns nonconst reference
  // int_array is writeable
  int& at(int index)
  {
    return ns[index];
  }

  // Const at return const reference
  // const int_array is readonly
  const int& at(int index) const
  {
    return ns[index];
  }
};

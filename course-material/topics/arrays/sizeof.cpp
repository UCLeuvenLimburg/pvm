// 32 bit platform
void foo(int ns[])
{
  std::cout << sizeof(ns) << std::endl; // 4
}

void bar()
{
  int ns[5];
  std::cout << sizeof(ns) << std::endl; // 20
  foo(ns);
}

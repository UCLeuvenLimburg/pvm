#include <iostream>

int main()
{
  int x = 10;
  int y = 5;

  int* p = &x;
  int* q = &y;

  std::cout << *p + *q << std::endl;
}

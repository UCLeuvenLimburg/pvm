#include <iostream>

int main() {
  Person* p = new Person("Jan", 20);

  std::cout << (*p).getName()
            << " is "
            << (*p).age
            << " years old"
            << std::endl;

  delete p;
}

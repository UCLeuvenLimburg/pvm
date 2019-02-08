class Person {
private:
  std::string name;
  int age;
  
public:
  Person(std::string name);
};

void foo() {
  Person* p = new Person("Mario");
}


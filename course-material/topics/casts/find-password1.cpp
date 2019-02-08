class Person
{
private:
  std::string name;
  int age;

  // Password is secret
  std::string password;

public:
  Person(std::string pw)
    : password(pw) { }
};

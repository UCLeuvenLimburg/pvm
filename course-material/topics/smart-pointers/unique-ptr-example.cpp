class Class {
  std::vector<std::unique_ptr<Student>> members;

public:
  void add(std::unique_ptr<Student> student) {
    members.push_back(student);
  }
};

class Student {
public:
  Person(std::string, int);
};

Class c;
auto p = std::make_unique<Student>("Jan", 20);

c.add(std::move(p));


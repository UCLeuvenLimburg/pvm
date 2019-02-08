class Class {
  std::vector<smart_ptr<Student>> students;
public:
  void add(smart_ptr<Student> student) {
    students.push_back(student);
  }
};

Class c;
smart_ptr<Student>(new Student("Brad"));

c.add( s ); // Fails
c.add( transfer(s) ); // Succeeds

// When c goes out of scope,
// all students will be deleted

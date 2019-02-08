// Const-incorrect function
// Does not need write access,
// so parameter should be const
int current_age(Person& person);

void foo(const Person& person) {
  // Wants to get the age
  // Does not compile
  int length = string_length(person);

  // Works
  int length = string_length(const_cast<Person&>(person));
}

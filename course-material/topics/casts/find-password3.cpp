std::string find_password(const Person& person) {
  // First use person with known password
  // to find position of password in object
  Person dummy("xyz");
  int index = find_password_index(dummy, "xyz");

  // Look at same location in given person
  const uint8_t* p = reinterpret_cast<const uint8_t*>(&person);
  return *reinterpret_cast<const std::string*>(p + index);
}

int main() {
    Person person("secret");
    std::cout << find_password(person) << std::endl;
}

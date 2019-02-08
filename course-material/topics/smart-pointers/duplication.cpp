void make_older(smart_pointer<Person> p) {
  p->age++;
}

smart_pointer<Person> q(new Person(20));
make_older(q);
std::cout << "Age: " << q->age << std::endl;

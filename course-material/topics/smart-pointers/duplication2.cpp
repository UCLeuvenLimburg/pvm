// make_older does not need ownership
// so we use Person* instead
// of smart_ptr<Person>
void make_older(Person* p) {
  p->age++;
}

smart_pointer<Person> q(new Person(20));
make_older(q.get());
std::cout << "Age: " << q->age << std::endl;

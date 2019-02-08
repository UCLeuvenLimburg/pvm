Dog* dog = new Dog;

// Does not compile
Cat* cat = static_cast<Dog*>(dog);

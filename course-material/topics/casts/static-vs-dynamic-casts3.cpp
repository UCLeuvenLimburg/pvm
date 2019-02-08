Animal* animal = new Dog();

// Compiles: an animal could be a cat
// Compiler not smart enough remember
// previous statement
// It's still a bad cast and
// will lead to undefined behaviour
// at runtime
Cat* cat = static_cast<Cat*>(animal);

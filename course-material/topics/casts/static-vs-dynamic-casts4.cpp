Animal* animal = new Dog();

// Compiles: an animal could be a cat
Cat* cat = dynamic_cast<Cat*>(animal);

// At runtime, it is discovered that
// animal was not a cat, but a dog
// The bad cast is detected, and
// cat == nullptr

struct Animal { virtual ~Animal(); };
struct Dog : public Animal { };
struct Cat : public Animal { };

Cat* cat = new Cat;
Animal* animal = cat;     // Implicit upcast
Dog* dog = (Dog*) animal; // Wrong downcast

struct A { };
struct B {
  ~B() { }
};

std::shared_ptr<A> p = std::make_shared<B>();

// When p's refcount goes to zero B::~B()
// will be called because p, even though
// it is a shared_ptr<A>, it remembers
// that it points to a B

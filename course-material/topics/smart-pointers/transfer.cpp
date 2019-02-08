smart_pointer<T> p(new T);
smart_pointer<T> q(nullptr);

// Transfer ownership from p to q
q = transfer(p);

// p == nullptr
// q points to object

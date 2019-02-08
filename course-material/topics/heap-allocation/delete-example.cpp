bool* p = new bool;

delete p;

// Forbidden
std::cout << *p << std::endl;

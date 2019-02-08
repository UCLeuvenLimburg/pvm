class Foo
{
    int* p;

public:
    // Constructor allocates
    Foo() : p(new int) { }

    // Destructor deallocates
    ~Foo()
    {
        delete p;
    }
}

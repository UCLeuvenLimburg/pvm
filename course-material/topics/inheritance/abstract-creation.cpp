struct Foo {
    virtual void bar() = 0;
};

int main()
{
    Foo foo;          // Error
    Foo* p = new Foo; // Error
}

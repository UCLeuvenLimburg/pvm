class Foo {
public:
    Foo(int) { std::cout << "U"; }
};

void bar(Foo) { }

int main()
{
    bar(5); // prints U
}

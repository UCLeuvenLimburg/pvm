// In foo.cpp
int foo(int x)
{
    bar(9, 8);

    return x + 1;
}

// In bar.cpp
char bar(double, double)
{
    foo(1);

    return 'd';
}

// In baz.cpp
void baz()
{
    bar(1, 2);
}

// In qux.cpp
void qux(bool b)
{
    foo(1);
    bar(5, 6);

    if (b)
        qux(false);
}

// In app.cpp
int main()
{
    foo(5);
    qux(false);
}
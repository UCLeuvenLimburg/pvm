int main()
{
  // Calls default constructor Foo::Foo()
  Foo bar;

  // Calls constructor Foo::Foo(int)
  Foo baz(1);

  // WRONG, do not use parentheses!
  // It is interpreted as a function declaration
  Foo qux();
}

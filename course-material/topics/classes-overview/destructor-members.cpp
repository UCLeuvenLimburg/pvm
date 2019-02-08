class Foo
{
  Bar bar;

public:
  ~Foo()
  {
    // bar gets cleaned up automatically
  }
};

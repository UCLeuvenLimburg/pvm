Bar* foo()
{
  Bar b;
  return &b;
}

Bar* p = foo();
p->x++;

void foo(Bar* p) {
  p->x++;
}

Bar bar;
foo(&bar);

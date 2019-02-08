void foo(int arg) {
  // foo receives a copy
  arg++;
}

int x = 5;
foo(x);
// x is still 5

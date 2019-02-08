void foo(int[] arg) {
  for ( int i = 0; i != arg.length; ++i )
    arg[i]++;
}

int[] xs = new int[] {1, 2, 3};
foo(xs);
// xs now equals {2, 3, 4}

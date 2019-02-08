int sum(int n) {
  return n == 0 ? 0 : n + sum(n - 1);
}

sum(5);

int sum(int from, int to) {
  int result = 0;

  for (int i = from; i <= to; ++i)
      result += i;

  return result;
}

int result = sum(0, 5);

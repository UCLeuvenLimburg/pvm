#define FOR_RANGE(i, from, to) \
  for ( int i = from; i <= to; ++i )

FOR_RANGE(i, 1, 10) {
  std::cout << i << std::endl;
}

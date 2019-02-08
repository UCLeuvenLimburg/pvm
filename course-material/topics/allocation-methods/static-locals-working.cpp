int counter()
{
  static int current = 0;

  return ++current;
}

counter(); // 1
counter(); // 2
counter(); // 3

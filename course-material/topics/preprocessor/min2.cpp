int x = 3;
int y = (++x < 7 ? ++x : y);

// x == 5, y == 5

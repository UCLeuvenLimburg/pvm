struct Bar {
  int x, y;
  
  Bar() : x(1), y(2) { }
  Bar(int x, int y)
    : x(x + 1), y(y + 1) { }
  Bar(const Bar& b)
    : x(b.x), y(b.y) { }

  Bar& operator =(const Bar& b) {
    this->x = b.x * 3;
    this->y = b.y * 3;
    return *this;
  }
};

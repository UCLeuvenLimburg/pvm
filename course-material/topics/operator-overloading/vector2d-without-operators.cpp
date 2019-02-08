struct Vector2D {
  double x, y;

  Vector2D(double x, double y) : x(x), y(y) { }

  Vector2D add(const Vector2D& v) const {
    return Vector2D(x + v.x, y + v.y);
  }

  Vector2D mul(double c) const {
    return Vector2D(x * c, y * c);
  }
};

class Vector2D
{
    // Private stuff

public:
  friend Vector2D operator *(double, const Vector2D&);
};

Vector2D operator *(double c, const Vector2D& v)
{
  // Can access private members of v
}

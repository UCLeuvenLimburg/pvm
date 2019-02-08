class Vector2D
{
  // ...
    
  Vector2D operator *(double c) { ... }
};


Vector2D u(1, 2);

Vector2D v = u * 5; // Possible
Vector2D w = 5 * u; // Does not work!

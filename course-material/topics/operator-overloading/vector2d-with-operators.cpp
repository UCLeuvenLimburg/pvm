struct Vector2D {
    double x, y;

    Vector2D(double x, double y) : x(x), y(y) { }
};


Vector2D operator +(const Vector2D& u,
                    const Vector2D& v)
{
    return Vector2D(u.x + v.x,u.y + v.y);
}

Vector2D operator *(const Vector2D& v,
                    double c)
{
    return Vector2D(v.x * c, v.y * c);
}

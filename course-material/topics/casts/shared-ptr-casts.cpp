std::shared_ptr<Shape> shape;

// Equivalent for static_cast
std::shared_ptr<Circle> circle =
  std::static_pointer_cast<Circle>(shape);

// Equivalent for dynamic_cast
std::shared_ptr<Circle> circle =
  std::dynamic_pointer_cast<Circle>(shape);

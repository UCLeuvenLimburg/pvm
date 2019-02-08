struct Shape {
  virtual double area() const = 0;
};

struct Square : public Shape {
  double side;
  
  double area() const override {
    return side * side;
  }
};

class Array<int> {
  `\pgfmark{array int xs start}`int*`\pgfmark{array int xs end}` _xs;
  int _size;

public:
  `\pgfmark{array int return type start}`int`\pgfmark{array int return type end}` sum() const {
    `\pgfmark{array int init start}`int result = 0`\pgfmark{array int init end}`;

    for ( int i = 0; i != _size; ++i )
      `\pgfmark{array int add start}`result += _xs[i]`\pgfmark{array int add end}`;

    return result;
  }
};

class Array<double> {
  `\pgfmark{array double xs start}`double*`\pgfmark{array double xs end}` _xs;
  int _size;

public:
  `\pgfmark{array double return type start}`double`\pgfmark{array double return type end}` sum() const {
    `\pgfmark{array double init start}`double result = 0`\pgfmark{array double init end}`;

    for ( int i = 0; i != _size; ++i )
      `\pgfmark{array double add start}`result += _xs[i]`\pgfmark{array double add end}`;

    return result;
  }
};

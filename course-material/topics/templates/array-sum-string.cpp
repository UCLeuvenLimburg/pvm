class Array<std::string> {
  `\pgfmark{array std::string xs start}`std::string*`\pgfmark{array std::string xs end}` _xs;
  int _size;

public:
  `\pgfmark{array std::string return type start}`std::string`\pgfmark{array std::string return type end}` sum() const {
    `\pgfmark{array std::string init start}`std::string result = 0`\pgfmark{array std::string init end}`;

    for ( int i = 0; i != _size; ++i )
      `\pgfmark{array std::string add start}`result += _xs[i]`\pgfmark{array std::string add end}`;

    return result;
  }
};

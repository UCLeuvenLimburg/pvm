struct Foo {
  void `\pgfmark{foo hello start}`hello()`\pgfmark{foo hello end}` { std::cout << "Hello"; }
};
struct Bar {
  `\pgfmark{bar arrow return type start}`Foo*`\pgfmark{bar arrow return type end}` operator ->() { return new Foo() ; }
};
struct Baz {
  `\pgfmark{baz arrow return type start}`Bar`\pgfmark{baz arrow return type end}` operator ->() { return Bar(); }
};
struct Qux {
  `\pgfmark{qux arrow return type start}`Baz`\pgfmark{qux arrow return type end}` operator ->() { return Baz(); }
};
auto qux = `\pgfmark{qux creation start}`Qux()`\pgfmark{qux creation end}`;
`\pgfmark{qux arrow start}`qux->hello()`\pgfmark{qux arrow end}`;

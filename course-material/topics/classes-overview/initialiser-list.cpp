class Foo {
    int `\pgfmark{constructor field a start}`a`\pgfmark{constructor field a end}`, `\pgfmark{constructor field b start}`b`\pgfmark{constructor field b end}`, `\pgfmark{constructor field c start}`c`\pgfmark{constructor field c end}`;

public:
    Foo() : `\pgfmark{constructor parameter a start}`a(1)`\pgfmark{constructor parameter a end}`, `\pgfmark{constructor parameter b start}`b(2)`\pgfmark{constructor parameter b end}`, `\pgfmark{constructor parameter c start}`c(3)`\pgfmark{constructor parameter c end}` { }
};

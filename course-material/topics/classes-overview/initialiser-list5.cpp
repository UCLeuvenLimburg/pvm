class Foo {
    int `\pgfmark{ilnaming field a start}`a`\pgfmark{ilnaming field a end}`, `\pgfmark{ilnaming field b start}`b`\pgfmark{ilnaming field b end}`, `\pgfmark{ilnaming field c start}`c`\pgfmark{ilnaming field c end}`;

public:
    Foo(int `\pgfmark{ilnaming parameter a start}`a`\pgfmark{ilnaming parameter a end}`, int `\pgfmark{ilnaming parameter b start}`b`\pgfmark{ilnaming parameter b end}`, int `\pgfmark{ilnaming parameter c start}`c`\pgfmark{ilnaming parameter c end}`)
        : `\pgfmark{ilnaming init a start}`a`\pgfmark{ilnaming init a end}`(`\pgfmark{ilnaming value a start}`a`\pgfmark{ilnaming value a end}`), `\pgfmark{ilnaming init b start}`b`\pgfmark{ilnaming init b end}`(`\pgfmark{ilnaming value b start}`b`\pgfmark{ilnaming value b end}`), `\pgfmark{ilnaming init c start}`c`\pgfmark{ilnaming init c end}`(`\pgfmark{ilnaming value c start}`c`\pgfmark{ilnaming value c end}`)
    {
    }
};

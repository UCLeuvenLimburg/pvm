class Foo {
    `\pgfmark{explicit start}`explicit`\pgfmark{explicit end}` Foo(int) { }
};

void bar(Foo) { }

int main() {
    bar(5);       // error
    bar((Foo) 5); // ok
}

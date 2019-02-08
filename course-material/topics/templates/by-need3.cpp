// Compiler error!
template<typename T>
struct Foo {
    void bar() {
        djflksdjfl dskfljsd
        fjqipodf cm ckmal 778!
    }
};

int main() {
    Foo<int> foo;
    foo.bar(); // <-- makes compiler look at bar
}

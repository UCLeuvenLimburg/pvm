void foo(int x);

class Bar {
public:
    void bar() {
        foo(5); // fails
    }

    void foo();
};

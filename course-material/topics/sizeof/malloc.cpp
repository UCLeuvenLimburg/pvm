struct Foo {
    int x;
    char* p;
};

// C-style allocation
Foo* foo = (Foo*) malloc(sizeof(Foo));

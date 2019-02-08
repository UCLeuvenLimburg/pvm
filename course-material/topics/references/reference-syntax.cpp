void foo(int& x) {
    // Reading x
    std::cout << x;

    // Writing x
    x++;
}

int a = 1;
foo(a);      // Prints 1
// a == 2

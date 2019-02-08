void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int a = 1, b = 2;
swap(a, b);
// a == 2, b == 1

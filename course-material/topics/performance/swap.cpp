void swap(int& x, int& y) {
    int temp = x; x = y; y = temp;
}

int x = 1, y = 2;
swap(x, y);

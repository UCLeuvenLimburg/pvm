void inc(int& x) {
    x++;
}

int x = 0;
inc(x);

// becomes

int x = 0;
x++;

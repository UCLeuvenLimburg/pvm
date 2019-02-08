int long_computation(int x) {
    int result = 0;

    while ( x-- )
        result += x;

    return result;
}

// Nothing is done with result
long_computation(9999999);

class IntList {
    int* items;
    int size;
    
public:
    IntList& operator =(const IntList& xs) {
        delete[] items;
        items = new int[xs.size];

        for ( int i = 0; i != xs.size; ++i )
            items[i] = xs.items[i];

        return *this;
    }
};

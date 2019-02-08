class Color {
    int r, g, b;

public:
    Color(int r = 0, int g = 0, int b = 0)
        : r(r), g(g), b(b) { }
};

Color bar() {
    return true; // returns Color(1,0,0)
}

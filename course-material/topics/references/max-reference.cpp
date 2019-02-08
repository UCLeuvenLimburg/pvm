int& max(int& a, int& b)
{
    if ( a >= b ) return a;
    else return b;
}

int a = 1, b = 2;
max(a, b)++;
// a == 1, b == 3

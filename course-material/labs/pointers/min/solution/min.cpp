#include "min.h"

int* min(int* p, int* q, int* r)
{
    int a = *p, b = *q, c = *r;
    
    if (a <= b && a <= c)
    {
        return p;
    }
    else if (b <= a && b <= c)
    {
        return q;
    }
    else
    {
        return r;
    }
}
#include "util.h"

void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

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

int* max(int* p, int* q, int* r)
{
    int a = *p, b = *q, c = *r;

    if (a >= b && a >= c)
    {
        return p;
    }
    else if (b >= a && b >= c)
    {
        return q;
    }
    else
    {
        return r;
    }
}

void minmax(int* p, int *q, int *r, int** minimum, int** maximum)
{
    *minimum = min(p, q, r);
    *maximum = max(p, q, r);
}

void swap_min_and_max(int* p, int* q, int* r)
{
    int* minimum;
    int* maximum;
    
    minmax(p, q, r, &minimum, &maximum);
    swap(minimum, maximum);
}

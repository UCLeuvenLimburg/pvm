#include "quotrest.h"


void quotrest(int x, int y, int* q, int *r)
{
    *q = x / y;
    *r = x % y;
}
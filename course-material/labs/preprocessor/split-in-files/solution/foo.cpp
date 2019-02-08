#include "foo.h"
#include "bar.h"

int foo(int x)
{
    bar(9, 8);

    return x + 1;
}
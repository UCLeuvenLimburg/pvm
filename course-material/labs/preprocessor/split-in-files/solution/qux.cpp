#include "qux.h"
#include "foo.h"
#include "bar.h"

void qux(bool b)
{
    foo(1);
    bar(5, 6);

    if (b)
        qux(false);
}
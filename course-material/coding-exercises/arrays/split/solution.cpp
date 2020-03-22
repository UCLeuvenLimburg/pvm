#include "solution.h"

void split(int* ns, unsigned size, int** odds, unsigned* n_odds, int** evens, unsigned* n_evens)
{
    *n_odds = *n_evens = 0;

    for (unsigned i = 0; i != size; ++i)
    {
        ++* (ns[i] % 2 ? n_odds : n_evens);
    }

    *odds = new int[*n_odds];
    *evens = new int[*n_evens];

    unsigned i = 0, j = 0;
    for (unsigned k = 0; k != size; ++k)
    {
        if (ns[k] % 2)
        {
            (*odds)[i++] = ns[k];
        }
        else
        {
            (*evens)[j++] = ns[k];
        }
    }
}

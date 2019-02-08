#include "crop.h"


std::vector<int> crop(std::vector<int> ns, unsigned n)
{
    if (ns.size() < n * 2)
    {
        return std::vector<int>();
    }
    else
    {
        return std::vector<int>(ns.begin() + n, ns.end() - n);
    }
}
#include "uniq.h"
#include <set>


void uniq(std::vector<int>* ns)
{
    std::set<int> set((*ns).begin(), (*ns).end());
    *ns = std::vector<int>(set.begin(), set.end());
}
#include "is-palindrome.h"
#include <vector>


bool is_palindrome(std::vector<int> ns)
{
    for (unsigned i = 0; i < ns.size() / 2; ++i)
    {
        if (ns[i] != ns[ns.size() - i - 1])
        {
            return false;
        }
    }

    return true;
}

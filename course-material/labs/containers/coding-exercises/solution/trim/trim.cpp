#include "trim.h"
#include <algorithm>
#include <cctype>


void trim(std::string* str)
{
    auto left = std::find_if_not((*str).begin(), (*str).end(), isspace);

    if (left != (*str).end())
    {
        (*str).erase((*str).begin(), left);
    }

    auto right = std::find_if_not((*str).rbegin(), (*str).rend(), isspace);

    if (right != (*str).rend())
    {
        (*str).erase(right.base(), (*str).end());
    }
}
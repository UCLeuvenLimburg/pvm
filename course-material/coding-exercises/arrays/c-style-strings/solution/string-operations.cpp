#include "string.h"


unsigned length(char* string)
{
    unsigned count = 0;
    auto current = string;

    while (*current != 0)
    {
        ++current;
        ++count;
    }

    return count;
}

void overwrite(char* destination, char* source)
{
    while (*source != 0)
    {
        *destination = *source;
        ++destination;
        ++source;
    }

    *destination = 0;
}

char* concatenate(char* s1, char* s2)
{
    auto len1 = length(s1);
    auto len2 = length(s2);
    char* result = new char[len1 + len2 + 1];

    overwrite(result, s1);
    overwrite(result + len1, s2);

    return result;
}

void reverse(char* string)
{
    const auto len = length(string);

    for (unsigned i = 0; i < len / 2; ++i)
    {
        unsigned j = len - i - 1;
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
}

unsigned parse(char* string)
{
    unsigned total = 0;

    while (*string != 0)
    {
        total = (total * 10) + (*string - '0');
        ++string;
    }

    return total;
}
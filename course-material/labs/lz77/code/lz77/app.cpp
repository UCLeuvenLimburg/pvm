#ifndef TEST_BUILD

#include "lz77.h"
#include <iostream>


int main()
{
    auto triplets = encode(7, 3, "ABAABBBABA");
    
    for (auto& triplet : triplets)
    {
        std::cout << triplet << std::endl;
    }
}

#endif

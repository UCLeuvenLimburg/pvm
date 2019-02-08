#ifndef COLOR_H
#define COLOR_H

#include <cstdint>


struct ARGB
{
    uint8_t b, g, r, a;
};

uint32_t convert_to_uint(const ARGB&);

#endif

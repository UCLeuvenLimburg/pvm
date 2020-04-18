#include "extract-byte.h"


uint8_t extract_byte(uint64_t x, unsigned k)
{
    return (x >> (8 * k)) & 0xFF;
}
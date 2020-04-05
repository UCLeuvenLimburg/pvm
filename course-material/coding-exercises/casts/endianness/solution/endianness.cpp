#include "endianness.h"
#include <cstdint>


bool is_little_endian()
{
    // Allocate 2 bytes in memory for a uint16_t
    // Initialize it to value 1
    // On little endian platforms, it will be stored as 0x0100
    // On big endian platforms, it will be stored as 0x0001
    uint16_t x = 1;

    // View x as a series of bytes
    uint8_t* p = reinterpret_cast<uint8_t*>(&x);

    // Check first byte
    // If it's 1, we're little endian
    return p[0] == 1;
}

bool is_big_endian()
{
    return !is_little_endian();
}
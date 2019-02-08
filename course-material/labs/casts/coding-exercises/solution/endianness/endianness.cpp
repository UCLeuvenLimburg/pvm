#include "endianness.h"
#include <cstdint>
#include <assert.h>


bool is_little_endian()
{
    uint16_t a = 0x0011;
    uint8_t* b = reinterpret_cast<uint8_t*>(&a);

    // Sanity checks
    assert((b[0] == 0x00 && b[1] == 0x11) || (b[0] == 0x11 && b[1] == 0x00));

    return b[0] == 0x11;
}

bool is_big_endian()
{
    return !is_little_endian();
}

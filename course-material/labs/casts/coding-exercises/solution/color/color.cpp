#include "color.h"


uint32_t convert_to_uint(const ARGB& argb)
{
    return *reinterpret_cast<const uint32_t*>(&argb);
}

#ifndef BITMAP_H
#define BITMAP_H

#include "color.h"


class Bitmap
{
    Color* _colors;
    unsigned _width, _height;

public:
    Bitmap(unsigned, unsigned);
    ~Bitmap();

    unsigned width() const;
    unsigned height() const;

    Color& at(unsigned x, unsigned y);
    const Color& at(unsigned x, unsigned y) const;

    void clear(const Color&);
};

#endif

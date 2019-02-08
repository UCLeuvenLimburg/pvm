#include "bitmap.h"

Bitmap::Bitmap(unsigned width, unsigned height)
    : _width(width), _height(height), _colors(new Color[width * height])
{
    // NOP
}

Bitmap::~Bitmap()
{
    delete[] _colors;
}

unsigned Bitmap::width() const
{
    return _width;
}

unsigned Bitmap::height() const
{
    return _height;
}

Color& Bitmap::at(unsigned x, unsigned y)
{
    return _colors[y * _width + x];
}

const Color& Bitmap::at(unsigned x, unsigned y) const
{
    return _colors[y * _width + x];
}

void Bitmap::clear(const Color& color)
{
    for (unsigned y = 0; y != _height; ++y)
    {
        for (unsigned x = 0; x != _width; ++x)
        {
            at(x, y) = color;
        }
    }
}
#ifndef GRID_H
#define GRID_H

#include "position.h"
#include <vector>


template<typename T>
class Grid
{
    std::vector<T> _contents;
    int _width;
    int _height;

    int index_of(const Position& position) const            { return position.x + position.y * _width; }

public:
    Grid(int width, int height) : _contents(width * height), _width(width), _height(height) { }

    int width()  const                                      { return _width; }
    int height() const                                      { return _height; }

          T& operator [](const Position& position)          { return _contents[index_of(position)]; }
    const T& operator [](const Position& position) const    { return _contents[index_of(position)]; }
};

#endif

#include "tag.h"


tag get_tag(const Shape& shape)
{
    const Shape* p = &shape;

    if (dynamic_cast<const Square*>(p) != nullptr) return tag::square;
    if (dynamic_cast<const Rectangle*>(p) != nullptr) return tag::rectangle;
    if (dynamic_cast<const Circle*>(p) != nullptr) return tag::circle;
    if (dynamic_cast<const Ellipse*>(p) != nullptr) return tag::ellipse;
}

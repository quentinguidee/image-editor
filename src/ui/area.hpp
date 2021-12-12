#ifndef AREA_HPP
#define AREA_HPP

#include "position.hpp"
#include "size.hpp"

class Area
{
public:
    Position position;
    Size size;

    Area(const Position& position, const Size& size);
    ~Area() {}

    bool contains(const Position& position) const;
};

#endif /* AREA_HPP */

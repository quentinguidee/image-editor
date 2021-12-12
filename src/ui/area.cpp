#include "area.hpp"

Area::Area(const Position& position, const Size& size) :
    position(position),
    size(size)
{
}

bool Area::contains(const Position& position) const
{
    return position.x >= this->position.x &&
           position.y >= this->position.y &&
           position.x.x <= this->position.x.x + this->size.width.width &&
           position.y.x <= this->position.y.x + this->size.height.width;
}

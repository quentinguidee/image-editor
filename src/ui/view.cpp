#include "view.hpp"

View::View() :
    position({0, 0})
{
}

int16_t View::getX() const
{
    return position.x;
}

int16_t View::getY() const
{
    return position.y;
}

Position View::getPosition() const
{
    return position;
}

void View::setX(int16_t x)
{
    position.x = x;
}

void View::setY(int16_t y)
{
    position.y = y;
}

void View::setPosition(int16_t x, int16_t y)
{
    setX(x);
    setY(y);
}

#include "has_background.hpp"

#include "rectangle.hpp"
#include "shape.hpp"
#include "size.hpp"

HasBackground::HasBackground() :
    shape(new Rectangle())
{
}

HasBackground::~HasBackground()
{
    delete shape;
}

void HasBackground::setBackgroundShape(Shape* shape)
{
    this->shape = shape;
}

void HasBackground::drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) const
{
    shape->setFillColor(getFillColor());
    shape->draw(renderer, offset, maxSize);
}
#include "has_background.hpp"

#include "rectangle.hpp"
#include "shape.hpp"
#include "size.hpp"

HasBackground::HasBackground() :
    shape(new Rectangle())
{
    setFillColor(Color::TRANSPARENT);
}

HasBackground::~HasBackground()
{
    if (shape != nullptr)
        delete shape;
}

void HasBackground::setBackgroundShape(Shape* shape)
{
    this->shape = shape;
}

void HasBackground::drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize)
{
    shape->setFillColor(getFillColor());
    shape->draw(renderer, offset, maxSize);
}

#include "fillable.hpp"

#include "color.hpp"

Fillable::Fillable() :
    fillColor(Color::WHITE) {}

void Fillable::setFillColor(const Color& color)
{
    fillColor = color;
}

const Color& Fillable::getFillColor() const
{
    return fillColor;
}

void Fillable::beforeDrawFill(SDL_Renderer* renderer) const
{
    fillColor.useAsRenderDrawColor(renderer);
}

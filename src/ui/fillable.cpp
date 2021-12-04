#include "fillable.hpp"

#include "color.hpp"

Fillable::Fillable() :
    fillColor(WHITE) {}

void Fillable::fill(const Color& color)
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

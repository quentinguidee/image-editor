#include "rectangle.hpp"

#include "sdl_draw.hpp"

void Rectangle::draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) const
{
    drawFill(renderer, offset, maxSize);
}

void Rectangle::drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) const
{
    beforeDrawFill(renderer);

    Size size = maxSize.isUndefined() ? getSize() : maxSize;

    SDL::drawRectangle(renderer, getPosition() + offset, size);
}

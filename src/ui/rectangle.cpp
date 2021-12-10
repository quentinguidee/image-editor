#include "rectangle.hpp"

#include "SDL.h"

void Rectangle::draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) const
{
    drawFill(renderer, offset, maxSize);
}

void Rectangle::drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) const
{
    beforeDrawFill(renderer);

    Size s = maxSize.isUndefined() ? getSize() : maxSize;

    SDL_Rect rectangle{
        getX() + offset.x,
        getY() + offset.y,
        s.width,
        s.height};

    SDL_RenderFillRect(renderer, &rectangle);
}

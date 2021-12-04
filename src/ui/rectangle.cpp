#include "rectangle.hpp"

#include <SDL.h>

void Rectangle::draw(SDL_Renderer* renderer, const Position& offset, const Size& forcedSize) const
{
    drawFill(renderer, offset, forcedSize);
}

void Rectangle::drawFill(SDL_Renderer* renderer, const Position& offset, const Size& forcedSize) const
{
    beforeDrawFill(renderer);

    Size s = forcedSize.isUndefined() ? getSize() : forcedSize;

    SDL_Rect rectangle{
        getX() + offset.x,
        getY() + offset.y,
        s.width,
        s.height};

    SDL_RenderFillRect(renderer, &rectangle);
}

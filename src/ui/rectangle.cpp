#include "rectangle.hpp"

#include <SDL.h>

void Rectangle::draw(SDL_Renderer *renderer) const
{
    drawFill(renderer);
}

void Rectangle::drawFill(SDL_Renderer *renderer) const
{
    beforeDrawFill(renderer);

    SDL_Rect rectangle{getX(), getY(), getWidth(), getHeight()};
    SDL_RenderFillRect(renderer, &rectangle);
}

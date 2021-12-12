#include "rectangle.hpp"

#include "sdl_draw.hpp"

void Rectangle::draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize)
{
    drawFill(renderer, offset, maxSize);
}

void Rectangle::drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize)
{
    beforeDrawFill(renderer);

    Position position = getPosition() + offset;
    setDrawingPosition(position);

    Size size = maxSize.isUndefined() ? getSize() : maxSize;
    size.ensureIsSmallerThan(maxSize);
    setDrawingSize(size);

    SDL::drawRectangle(renderer, position, size);
}

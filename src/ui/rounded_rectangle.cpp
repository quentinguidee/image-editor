#include "rounded_rectangle.hpp"

#include "position.hpp"
#include "sdl_draw.hpp"

void RoundedRectangle::setRadius(uint8_t radius)
{
    this->radius = radius;
}

void RoundedRectangle::draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize)
{
    drawFill(renderer, offset, maxSize);
}

void RoundedRectangle::drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize)
{
    beforeDrawFill(renderer);

    Position position = getPosition() + offset;
    setDrawingPosition(position);

    Size size = getSize();
    size.ensureIsSmallerThan(maxSize);
    setDrawingSize(size);

    SDL::drawRoundedRectangle(renderer, radius, position, size);
}

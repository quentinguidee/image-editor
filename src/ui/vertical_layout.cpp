#include "vertical_layout.hpp"

void VerticalLayout::draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize)
{
    drawStack(renderer, offset, maxSize, 1);
}

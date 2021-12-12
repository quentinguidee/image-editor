#include "horizontal_layout.hpp"

HorizontalLayout::HorizontalLayout()
{
}

void HorizontalLayout::draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize)
{
    drawStack(renderer, offset, maxSize, 0);
}

#include "horizontal_layout.hpp"

HorizontalLayout::HorizontalLayout()
{
}

void HorizontalLayout::draw(SDL_Renderer* renderer, const Position& offset, const Size& forcedSize) const
{
    drawStack(renderer, offset, forcedSize, 0);
}

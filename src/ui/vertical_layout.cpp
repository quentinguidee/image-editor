#include "vertical_layout.hpp"

void VerticalLayout::draw(SDL_Renderer* renderer, const Position& offset, const Size& forcedSize) const
{
    drawStack(renderer, offset, forcedSize, 1);
}

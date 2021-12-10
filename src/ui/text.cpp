#include "text.hpp"

#include <algorithm>

#include "SDL.h"
#include "color.hpp"
#include "sdl_draw.hpp"

Text::Text(const string &value) :
    value(value),
    font(Font::REGULAR),
    textColor(Color::WHITE)
{
}

void Text::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize) const
{
    SDL::drawText(renderer, font, value, textColor, getPosition() + offset);
}

void Text::setTextColor(const Color &color)
{
    textColor = color;
}

void Text::setFont(const Font &font)
{
    this->font = font;
}

void Text::uppercase()
{
    std::transform(value.begin(), value.end(), value.begin(), ::toupper);
}

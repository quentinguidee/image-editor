#include "text.hpp"

#include <SDL.h>

#include <algorithm>

#include "SDL_render.h"
#include "color.hpp"

Text::Text(const string &value) :
    value(value),
    font(Font::REGULAR),
    textColor(WHITE)
{
}

void Text::draw(SDL_Renderer *renderer, const Position &offset, const Size &forcedSize) const
{
    SDL_Surface *surface = TTF_RenderText_Blended(font.getTTFFont(), value.c_str(), textColor.toSDL());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect area{
        getX() + offset.x,
        getY() + offset.y,
        surface->w,
        surface->h,
    };

    SDL_RenderCopy(renderer, texture, NULL, &area);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
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

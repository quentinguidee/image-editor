#include "sdl_draw.hpp"

#include <iostream>

void SDL::drawRectangle(SDL_Renderer *renderer, Position position, Size size)
{
    drawRectangle(renderer, position.x, position.y, size.width, size.height);
}

void SDL::drawRectangle(SDL_Renderer *renderer, float x, float y, float width, float height)
{
    SDL_FRect rectangle{x, y, width, height};
    if (SDL_RenderFillRectF(renderer, &rectangle))
        printError();
}

void SDL::drawText(SDL_Renderer *renderer, const Font &font, const string &text, Color color, Position position)
{
    drawText(renderer, font, text, color, position.x, position.y);
}

void SDL::drawText(SDL_Renderer *renderer, const Font &font, const string &text, Color color, float x, float y)
{
    SDL_Surface *surface = TTF_RenderText_Blended(font.getTTFFont(), text.c_str(), color.toSDL());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FRect area{x, y, (float)surface->w, (float)surface->h};

    if (SDL_RenderCopyF(renderer, texture, NULL, &area))
        printError();

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void SDL::printError()
{
    std::cerr << SDL_GetError() << std::endl;
}

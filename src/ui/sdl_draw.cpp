#include "sdl_draw.hpp"

#include <iostream>

#include "SDL_render.h"
#include "position.hpp"

void SDL::drawRectangle(SDL_Renderer *renderer, const Position &position, const Size &size)
{
    drawRectangle(renderer, position.x, position.y, size.width, size.height);
}

void SDL::drawRectangle(SDL_Renderer *renderer, const Position &start, const Position &end)
{
    drawRectangle(renderer, start.x, start.y, end.x - start.x, end.y - start.y);
}

void SDL::drawRectangle(SDL_Renderer *renderer, float x, float y, float width, float height)
{
    SDL_FRect rectangle{x, y, width, height};
    if (SDL_RenderFillRectF(renderer, &rectangle))
        printError();
}

void SDL::drawCircle(SDL_Renderer *renderer, uint16_t radius, const Position &position)
{
    drawCircle(renderer, radius, position.x, position.y);
}

void SDL::drawCircle(SDL_Renderer *renderer, uint16_t radius, float x, float y)
{
    // Using a variant of the circle algorithm
    // which also fills the circle.
    drawLine(renderer, x - radius, y, x + radius, y);

    float f = 1 - radius;
    float ddFx = 0, ddFy = -2 * radius;
    int currentY = radius;

    for (int currentX = 0; currentX <= currentY; currentX++)
    {
        if (f >= 0)
        {
            currentY--;
            ddFy += 2;
            f += ddFy;
        }

        ddFx += 2;
        f += ddFx + 1;

        drawLine(renderer, x + currentX, y + currentY, x - currentX, y + currentY);
        drawLine(renderer, x + currentX, y - currentY, x - currentX, y - currentY);

        drawLine(renderer, x + currentY, y + currentX, x - currentY, y + currentX);
        drawLine(renderer, x + currentY, y - currentX, x - currentY, y - currentX);
    }
}

void SDL::drawLine(SDL_Renderer *renderer, const Position &start, const Position &end)
{
    drawLine(renderer, start.x, start.y, end.x, end.y);
}

void SDL::drawLine(SDL_Renderer *renderer, float startX, float startY, float endX, float endY)
{
    SDL_RenderDrawLineF(renderer, startX, startY, endX, endY);
}

void SDL::drawRoundedRectangle(SDL_Renderer *renderer, uint8_t radius, const Position &position, const Size &size)
{
    drawRoundedRectangle(renderer, radius, position.x, position.y, size.width, size.height);
}

void SDL::drawRoundedRectangle(SDL_Renderer *renderer, uint8_t radius, float x, float y, float width, float height)
{
    // This decrement is because, in the algorithm made here,
    // we'll overflow of one pixel.
    width--;
    height--;

    int anchorAx = x + radius;
    int anchorAy = y + radius;

    int anchorBx = x + width - radius;
    int anchorBy = y + height - radius;

    Position anchors[] = {
        Position(anchorAx, anchorAy),
        Position(anchorBx, anchorAy),
        Position(anchorBx, anchorBy),
        Position(anchorAx, anchorBy),
    };

    // Center
    drawRectangle(renderer, anchors[0], anchors[2]);

    // Borders
    drawRectangle(renderer, Position(anchorAx, y), anchors[1]);
    drawRectangle(renderer, anchors[1], Position(x + width + 1, anchorBy));
    drawRectangle(renderer, anchors[3], Position(anchorBx, y + height + 1));
    drawRectangle(renderer, Position(x, anchorAy), anchors[3]);

    // Corners
    for (int i = 0; i < 4; i++)
    {
        drawCircle(renderer, radius, anchors[i]);
    }
}

void SDL::drawText(SDL_Renderer *renderer, const Font &font, const string &text, Color color, const Position &position)
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

#ifndef SDL_DRAW_HPP
#define SDL_DRAW_HPP

#include <string>

#include "SDL.h"
#include "SDL_ttf.h"
#include "color.hpp"
#include "font.hpp"
#include "position.hpp"
#include "size.hpp"

using std::string;

namespace SDL {

void drawRectangle(SDL_Renderer *renderer, const Position &position, const Size &size);
void drawRectangle(SDL_Renderer *renderer, const Position &start, const Position &end);
void drawRectangle(SDL_Renderer *renderer, float x, float y, float width, float height);

void drawCircle(SDL_Renderer *renderer, uint16_t radius, const Position &position);
void drawCircle(SDL_Renderer *renderer, uint16_t radius, float x, float y);

void drawLine(SDL_Renderer *renderer, const Position &start, const Position &end);
void drawLine(SDL_Renderer *renderer, float startX, float startY, float endX, float endY);

void drawRoundedRectangle(SDL_Renderer *renderer, uint8_t radius, const Position &position, const Size &size);
void drawRoundedRectangle(SDL_Renderer *renderer, uint8_t radius, float x, float y, float width, float height);

void printError();

}  // namespace SDL

namespace TTF {

void drawText(SDL_Renderer *renderer, const Font &font, const string &text, Color color, const Position &position);
void drawText(SDL_Renderer *renderer, const Font &font, const string &text, Color color, float x, float y);

void printError();

}  // namespace TTF

namespace IMG {

void drawImage(SDL_Renderer *renderer, const string &path, float x, float y);

void printError();

}  // namespace IMG

#endif /* SDL_DRAW_HPP */

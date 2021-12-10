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

void drawRectangle(SDL_Renderer *renderer, Position position, Size size);
void drawRectangle(SDL_Renderer *renderer, float x, float y, float width, float height);

void drawText(SDL_Renderer *renderer, const Font &font, const string &text, Color color, Position position);
void drawText(SDL_Renderer *renderer, const Font &font, const string &text, Color color, float x, float y);

void printError();

}  // namespace SDL

#endif /* SDL_DRAW_HPP */

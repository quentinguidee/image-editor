#include "font.hpp"

#include <iostream>

using std::cerr;
using std::endl;

Font::Font(const string& path, uint8_t size) :
    path(path),
    size(size)
{
    if (!TTF_WasInit())
        TTF_Init();

    font = TTF_OpenFont(path.c_str(), size);
    if (font == NULL)
    {
        std::cerr << TTF_GetError() << std::endl;
    }
}

Font::~Font()
{
    if (TTF_WasInit())
        TTF_CloseFont(font);
}

TTF_Font* Font::getTTFFont() const
{
    return font;
}

const Font Font::REGULAR = Font("src/assets/fonts/rubik/regular.ttf", 13);
const Font Font::BOLD = Font("src/assets/fonts/rubik/bold.ttf", 13);

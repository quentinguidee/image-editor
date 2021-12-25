#include "font.hpp"

#include "../resources/resources.hpp"
#include "sdl_draw.hpp"

Font::Font(const string& path, uint8_t size) :
    path(path),
    size(size)
{
    if (!TTF_WasInit())
        TTF_Init();

    font = TTF_OpenFont(path.c_str(), size);
    if (font == NULL)
        TTF::printError();
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

const Font Font::REGULAR = Font(Resources::getFont("rubik/regular"), 13);
const Font Font::BOLD = Font(Resources::getFont("rubik/bold"), 13);

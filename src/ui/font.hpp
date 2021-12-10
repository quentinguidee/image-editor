#ifndef FONT_HPP
#define FONT_HPP

#include <string>

#include "SDL_ttf.h"

using std::string;

class Font
{
private:
    string path;
    uint8_t size;

    TTF_Font* font;

public:
    Font(const string& path, uint8_t size);
    ~Font();

    TTF_Font* getTTFFont() const;

    static const Font REGULAR;
    static const Font BOLD;
};

#endif /* FONT_HPP */

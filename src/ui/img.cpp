#include "img.hpp"

#include "sdl_draw.hpp"

Img::Img(const string &path) :
    path(path)
{
}

void Img::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize)
{
    IMG::drawImage(renderer, path, getPosition() + offset, getSize());
}

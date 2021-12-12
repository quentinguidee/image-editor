#include "img.hpp"

#include "position.hpp"
#include "sdl_draw.hpp"

Img::Img(const string &path) :
    path(path)
{
}

void Img::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize)
{
    Position position = getPosition() + offset;
    setDrawingPosition(position);

    Size size = getSize();
    size.ensureIsSmallerThan(maxSize);
    setDrawingSize(size);

    IMG::drawImage(renderer, path, position, size);
}

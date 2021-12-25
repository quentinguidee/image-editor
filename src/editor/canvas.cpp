#include "canvas.hpp"

#include "../ui/color.hpp"
#include "../ui/sdl_draw.hpp"

Canvas::Canvas() :
    image(30, 30)
{
    setSize(100, 100);
    setPosition(0, 0);
}

void Canvas::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize)
{
    Size size = getSize();
    size.ensureIsSmallerThan(maxSize);
    setDrawingSize(size);

    float pixelSize = size.width / (float)image.getWidth();

    Position position = Position(
        maxSize.width / 2 - size.width / 2 + getPosition().x.x,
        maxSize.height / 2 - size.height / 2 + getPosition().y.x);

    setDrawingPosition(position);

    const vector<Color> &pixels = image.getPixels();
    for (int x = 0; x < image.getWidth(); x++)
    {
        for (int y = 0; y < image.getHeight(); y++)
        {
            image.getPixel(x, y).useAsRenderDrawColor(renderer);

            SDL::drawRectangle(
                renderer,
                position.x + offset.x + Position1D(pixelSize * x),
                position.y + offset.y + Position1D(pixelSize * y),
                pixelSize,
                pixelSize);
        }
    }
}

#include "canvas.hpp"

#include "../ui/color.hpp"
#include "../ui/sdl_draw.hpp"

Canvas::Canvas() :
    image(30, 30)
{
    setSize(100, 100);
}

void Canvas::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize)
{
    Size size = getSize();
    size.ensureIsSmallerThan(maxSize);
    setDrawingSize(size);

    int pixelSize = size.width / (float)image.getWidth();

    Position position = Position(
        maxSize.width / 2 - size.width / 2,
        maxSize.height / 2 - size.height / 2);

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

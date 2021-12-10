#include "canvas.hpp"

#include "../ui/color.hpp"
#include "../ui/sdl_draw.hpp"

Canvas::Canvas() :
    image(30, 30)
{
    setSize(100, 100);
    setPosition(300, 200);
}

void Canvas::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize) const
{
    Size s = maxSize.isUndefined() ? getSize() : maxSize;

    int pixelSize = s.width / (float)image.getWidth();

    const vector<Color> &pixels = image.getPixels();
    for (int x = 0; x < image.getWidth(); x++)
    {
        for (int y = 0; y < image.getHeight(); y++)
        {
            image.getPixel(x, y).useAsRenderDrawColor(renderer);

            SDL::drawRectangle(
                renderer,
                getX() + offset.x + Position1D(pixelSize * x),
                getY() + offset.y + Position1D(pixelSize * y),
                pixelSize,
                pixelSize);
        }
    }
}

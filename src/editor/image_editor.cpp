#include "image_editor.hpp"

#include <functional>
#include <vector>

#include "../ui/color.hpp"
#include "../ui/sdl_draw.hpp"
#include "canvas.hpp"

ImageEditor::ImageEditor() :
    canvas(Canvas()),
    tools(Tools())
{
}

void ImageEditor::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize)
{
    Color::BACKGROUND.useAsRenderDrawColor(renderer);

    Size size = maxSize.isUndefined() ? getSize() : maxSize;

    SDL::drawRectangle(renderer, getPosition() + offset, size);

    canvas.draw(renderer, offset, size);

    tools.draw(renderer, offset + Position(16, 16), maxSize);
}

Views ImageEditor::getSubviews()
{
    Views views = Views();
    views.push_back(canvas);
    views.push_back(tools);
    return views;
}

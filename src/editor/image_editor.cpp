#include "image_editor.hpp"

#include "../ui/color.hpp"
#include "../ui/sdl_draw.hpp"

void ImageEditor::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize) const
{
    Color::BACKGROUND.useAsRenderDrawColor(renderer);

    Size size = maxSize.isUndefined() ? getSize() : maxSize;

    SDL::drawRectangle(renderer, getPosition() + offset, size);

    canvas.draw(renderer, offset, Size::UNDEFINED);
}

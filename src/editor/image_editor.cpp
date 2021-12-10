#include "image_editor.hpp"

#include "../ui/color.hpp"

void ImageEditor::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize) const
{
    BACKGROUND.useAsRenderDrawColor(renderer);

    Size s = maxSize.isUndefined() ? getSize() : maxSize;

    SDL_Rect rectangle{
        getX() + offset.x,
        getY() + offset.y,
        s.width,
        s.height};

    SDL_RenderFillRect(renderer, &rectangle);

    canvas.draw(renderer, offset, Size::UNDEFINED);
}

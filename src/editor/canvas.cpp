#include "canvas.hpp"

#include "../ui/color.hpp"

Canvas::Canvas()
{
    setSize(100, 100);
    setPosition(300, 200);
}

void Canvas::draw(SDL_Renderer *renderer, const Position &offset, const Size &forcedSize) const
{
    Color(100, 100, 200).useAsRenderDrawColor(renderer);

    Size s = forcedSize.isUndefined() ? getSize() : forcedSize;

    SDL_Rect rectangle{
        getX() + offset.x,
        getY() + offset.y,
        s.width,
        s.height};

    SDL_RenderFillRect(renderer, &rectangle);
}

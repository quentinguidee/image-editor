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
    setEventHandler([this](const Event &event) -> void { eventHandler(event); });
}

void ImageEditor::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize)
{
    Color::BACKGROUND.useAsRenderDrawColor(renderer);

    Position position = getPosition() + offset;
    setDrawingPosition(position);

    Size size = maxSize.isUndefined() ? getSize() : maxSize;
    size.ensureIsSmallerThan(maxSize);
    setDrawingSize(size);

    SDL::drawRectangle(renderer, position, size);

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

void ImageEditor::eventHandler(const Event &event)
{
    if (event.mouseScroll())
    {
        if (event.keyAlt())
        {
            eventZoom(event.getMousePosition(), event.getScrollY());
        }
        else
        {
            eventMove(event.getScrollX(), event.getScrollY());
        }
    }
}

void ImageEditor::eventZoom(const Position &position, float scrollY)
{
    const int MOUSE_SENSITIVITY = 5;

    float zoom_multiplier = 1 + scrollY * 0.04;

    canvas.setSize(
        canvas.getSize().width * zoom_multiplier,
        canvas.getSize().height * zoom_multiplier);

    redraw();
}

void ImageEditor::eventMove(float scrollX, float scrollY)
{
    const int MOUSE_SENSITIVITY = 5;

    canvas.setPosition(
        canvas.getX().x - scrollX * MOUSE_SENSITIVITY,
        canvas.getY().x + scrollY * MOUSE_SENSITIVITY);

    redraw();
}

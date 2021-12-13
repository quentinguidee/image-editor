#include "view.hpp"

#include <functional>
#include <vector>

#include "area.hpp"
#include "position.hpp"
#include "window.hpp"

View::View() :
    position(Position::ZERO),
    size(Size::ZERO),
    drawingPosition(Position::ZERO),
    drawingSize(Size::ZERO)
{
}

Views View::getSubviews()
{
    return Views();
}

Position1D View::getX() const
{
    return position.x;
}

Position1D View::getY() const
{
    return position.y;
}

Position View::getPosition() const
{
    return position;
}

void View::setX(int16_t x)
{
    position.x = x;
}

void View::setY(int16_t y)
{
    position.y = y;
}

void View::setPosition(int16_t x, int16_t y)
{
    setX(x);
    setY(y);
}

Size1D View::getWidth() const
{
    return size.width;
}

Size1D View::getHeight() const
{
    return size.height;
}

Size View::getSize() const
{
    return size;
}

void View::setWidth(uint16_t value)
{
    size.width = value;
}

void View::setHeight(uint16_t value)
{
    size.height = value;
}

void View::setSize(uint16_t width, uint16_t height)
{
    setWidth(width);
    setHeight(height);
}

void View::setSize(const Size& size)
{
    setWidth(size.width);
    setHeight(size.height);
}

void View::redraw()
{
    Window::mustRedraw = true;
}

void View::setDrawingPosition(const Position& position)
{
    drawingPosition = position;
}

void View::setDrawingSize(const Size& size)
{
    drawingSize = size;
}

const Position& View::getDrawingPosition() const
{
    return drawingPosition;
}

const Size& View::getDrawingSize() const
{
    return drawingSize;
}

const Area View::getDrawingArea() const
{
    return Area(getDrawingPosition(), getDrawingSize());
}

void View::propagateEvent(SDL_Event& event, const Position& position)
{
    if (getDrawingArea().contains(position))
    {
        switch (event.type)
        {
            case SDL_MOUSEBUTTONDOWN:
                onMouseEvent(event.button, position);
                break;
            case SDL_MOUSEWHEEL:
                onMouseWheelEvent(event.wheel, position);
                break;
        }
    }

    Views views = getSubviews();
    for (int i = 0; i < views.size(); i++)
        views[i].get().propagateEvent(event, position);
}

void View::onMouseEvent(SDL_MouseButtonEvent& event, const Position& position)
{
    switch (event.button)
    {
        case SDL_BUTTON_LEFT:
            if (onClick) onClick(position);
            break;
    }
}

void View::onMouseWheelEvent(SDL_MouseWheelEvent& event, const Position& position)
{
    if (onScroll) onScroll(position, event.preciseX, event.preciseY);
}

void View::setOnClick(std::function<void(const Position&)> onClick)
{
    this->onClick = onClick;
}

void View::setOnScroll(std::function<void(const Position&, float, float)> onScroll)
{
    this->onScroll = onScroll;
}

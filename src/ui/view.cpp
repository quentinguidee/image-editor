#include "view.hpp"

#include <functional>
#include <vector>

#include "position.hpp"
#include "size.hpp"

View::View() :
    position(Position::ZERO),
    size(Size::ZERO),
    drawingPosition(Position::ZERO),
    drawingSize(Size::ZERO)
{
}

void View::processMouseEvent(SDL_MouseButtonEvent& event, int x, int y)
{
    Views views = getSubviews();
    for (int i = 0; i < views.size(); i++)
        views[i].get().processMouseEvent(event, x, y);
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

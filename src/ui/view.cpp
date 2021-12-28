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

std::vector<std::shared_ptr<View>> View::getViews()
{
    return std::vector<std::shared_ptr<View>>();
}

Position1D View::getX() const
{
    return getPosition().x;
}

Position1D View::getY() const
{
    return getPosition().y;
}

Position View::getPosition() const
{
    return position;
}

void View::setX(float x)
{
    position.x = x;
}

void View::setY(float y)
{
    position.y = y;
}

void View::setPosition(float x, float y)
{
    setX(x);
    setY(y);
}

Size1D View::getWidth() const
{
    return getSize().width;
}

Size1D View::getHeight() const
{
    return getSize().height;
}

Size View::getSize() const
{
    return size;
}

void View::setWidth(float value)
{
    size.width = value;
}

void View::setHeight(float value)
{
    size.height = value;
}

void View::setSize(float width, float height)
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

void View::propagateEvent(const Event& event)
{
    if (eventHandlers.size() != 0 && getDrawingArea().contains(event.getMousePosition()))
        for (size_t i = 0; i < eventHandlers.size(); i++) eventHandlers[i](event);

    std::vector<std::shared_ptr<View>> views = getViews();
    for (int i = 0; i < views.size(); i++)
        views[i]->propagateEvent(event);
}

void View::addEventHandler(std::function<void(const Event&)> eventHandler)
{
    eventHandlers.push_back(eventHandler);
}

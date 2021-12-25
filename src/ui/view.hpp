#ifndef VIEW_HPP
#define VIEW_HPP

#include <stdint.h>

#include <memory>
#include <vector>

#include "SDL.h"
#include "SDL_events.h"
#include "area.hpp"
#include "event.hpp"
#include "position.hpp"
#include "size.hpp"

class View;

typedef std::vector<std::shared_ptr<View>> Views;

class View
{
private:
    Position position;
    Size size;

    Position drawingPosition;
    Size drawingSize;

    bool mustRedraw = true;

    std::function<void(const Event&)> eventHandler;

public:
    View();
    ~View() {}

    virtual Views getSubviews();

    // Position
    Position1D getX() const;
    Position1D getY() const;
    Position getPosition() const;

    void setX(float x);
    void setY(float y);
    void setPosition(float x, float y);

    // Size
    Size1D getWidth() const;
    Size1D getHeight() const;
    Size getSize() const;

    virtual void setWidth(float value);
    virtual void setHeight(float value);
    void setSize(float width, float height);
    void setSize(const Size& size);

    // Drawing
    void redraw();
    virtual void draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) = 0;

    void setDrawingPosition(const Position& position);
    void setDrawingSize(const Size& size);

    const Position& getDrawingPosition() const;
    const Size& getDrawingSize() const;
    const Area getDrawingArea() const;

    // Events
    void propagateEvent(const Event& event);
    void setEventHandler(std::function<void(const Event&)> handler);
};

#endif /* VIEW_HPP */

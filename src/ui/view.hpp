#ifndef VIEW_HPP
#define VIEW_HPP

#include <stdint.h>

#include <functional>
#include <vector>

#include "SDL.h"
#include "position.hpp"
#include "size.hpp"

using std::reference_wrapper;
using std::vector;

class View;

typedef vector<reference_wrapper<View>> Views;

class View
{
private:
    Position position;
    Size size;

public:
    View();
    ~View() {}

    virtual void draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) = 0;
    virtual void processMouseEvent(SDL_MouseButtonEvent& event, int x, int y);
    virtual Views getSubviews();

    Position1D getX() const;
    Position1D getY() const;
    Position getPosition() const;

    void setX(int16_t x);
    void setY(int16_t y);
    void setPosition(int16_t x, int16_t y);

    Size1D getWidth() const;
    Size1D getHeight() const;
    Size getSize() const;

    virtual void setWidth(uint16_t value);
    virtual void setHeight(uint16_t value);
    void setSize(uint16_t width, uint16_t height);
    void setSize(const Size& size);
};

#endif /* VIEW_HPP */

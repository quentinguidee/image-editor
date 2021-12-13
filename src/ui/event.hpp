#ifndef EVENT_HPP
#define EVENT_HPP

#include "SDL.h"
#include "position.hpp"

class Event
{
private:
    SDL_Event* event;

public:
    Event(SDL_Event* event);
    ~Event() {}

    Position getMousePosition() const;

    bool mouseClick() const;
    bool mouseScroll() const;

    float getScrollX() const;
    float getScrollY() const;
};

#endif /* EVENT_HPP */

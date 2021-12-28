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

    bool mouseLeftClick() const;
    bool mouseLeftReleased() const;
    bool mouseScroll() const;
    bool keyPressed() const;
    bool windowEvent() const;
    bool quitEvent() const;

    // Scroll
    float getScrollX() const;
    float getScrollY() const;

    // Keys
    bool getKeyState(SDL_Scancode scancode) const;

    bool keyAlt() const;

    // Window
    bool windowSizeChanged() const;
};

#endif /* EVENT_HPP */

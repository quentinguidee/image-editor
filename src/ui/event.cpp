#include "event.hpp"

#include "SDL.h"
#include "position.hpp"

Event::Event(SDL_Event* event) :
    event(event)
{
}

Position Event::getMousePosition() const
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    return Position(x, y);
}

bool Event::mouseClick() const
{
    return event->type == SDL_MOUSEBUTTONDOWN &&
           event->button.button == SDL_BUTTON_LEFT;
}

bool Event::mouseScroll() const
{
    return event->type == SDL_MOUSEWHEEL;
}

float Event::getScrollX() const
{
    return event->wheel.preciseX;
}

float Event::getScrollY() const
{
    return event->wheel.preciseY;
}

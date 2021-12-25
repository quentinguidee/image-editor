#include "event.hpp"

#include <iostream>

#include "SDL.h"
#include "SDL_keyboard.h"
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
    return event->type == SDL_MOUSEBUTTONDOWN;
}

bool Event::mouseScroll() const
{
    return event->type == SDL_MOUSEWHEEL;
}

bool Event::keyPressed() const
{
    return event->type == SDL_KEYDOWN;
}

bool Event::windowEvent() const
{
    return event->type == SDL_WINDOWEVENT;
}

bool Event::quitEvent() const
{
    return event->type == SDL_QUIT;
}

float Event::getScrollX() const
{
    // TODO: use wheel.preciseX (new in SDL2.0.18)
    return event->wheel.x;
}

float Event::getScrollY() const
{
    // TODO: use wheel.preciseY (new in SDL2.0.18)
    return event->wheel.y;
}

bool Event::getKeyState(SDL_Scancode scancode) const
{
    return SDL_GetKeyboardState(NULL)[scancode];
}

bool Event::keyAlt() const
{
    return getKeyState(SDL_SCANCODE_LALT);
}

bool Event::windowSizeChanged() const
{
    return event->window.event == SDL_WINDOWEVENT_SIZE_CHANGED;
}

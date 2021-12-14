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
    return event->type == SDL_MOUSEBUTTONDOWN &&
           event->button.button == SDL_BUTTON_LEFT;
}

bool Event::mouseScroll() const
{
    return event->type == SDL_MOUSEWHEEL;
}

bool Event::keyPressed() const
{
    return event->type == SDL_KEYDOWN;
}

float Event::getScrollX() const
{
    return event->wheel.preciseX;
}

float Event::getScrollY() const
{
    return event->wheel.preciseY;
}

bool Event::getKeyState(SDL_Scancode scancode) const
{
    return SDL_GetKeyboardState(NULL)[scancode];
}

bool Event::keyAlt() const
{
    return getKeyState(SDL_SCANCODE_LALT);
}

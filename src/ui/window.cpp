#include "window.hpp"

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "color.hpp"
#include "event.hpp"
#include "font.hpp"
#include "sdl_draw.hpp"

Window::Window(const string& title, View& root) :
    title(title), root(root) {}

void Window::run()
{
    if (!SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Init(SDL_INIT_VIDEO);

    if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
        IMG::printError();

    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        1400, 750,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    renderer = SDL_CreateRenderer(window, -1, 0);

    running = true;

    draw();

    SDL_Event event;
    // TODO: Create Event() here only once, because the
    // SDL_Event is also only create once. No need to recreate
    // Event() for each loop.
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            handleEvents(&event);
        }
        if (mustRedraw) draw();
    }

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Window::handleEvents(SDL_Event* event)
{
    switch (event->type)
    {
        case SDL_WINDOWEVENT:
            if (event->window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                draw();
            break;
        case SDL_QUIT:
            running = false;
            break;
    }

    if (event->type == SDL_MOUSEBUTTONDOWN ||
        event->type == SDL_MOUSEWHEEL ||
        event->type == SDL_KEYDOWN)
        root.propagateEvent(Event(event));
}

void Window::draw()
{
    if (renderer == nullptr) return;

    Color::BACKGROUND.useAsRenderDrawColor(renderer);

    SDL_RenderClear(renderer);

    Size size = getSize();

    root.draw(renderer, Position::ZERO, size);

    SDL_RenderPresent(renderer);

    mustRedraw = false;
}

Size Window::getSize() const
{
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    return Size(width, height);
}

bool Window::mustRedraw = false;

#include "window.hpp"

#include <SDL.h>

#include "SDL_ttf.h"
#include "color.hpp"
#include "font.hpp"

Window::Window(const string& title, const View& root) :
    title(title), root(root) {}

void Window::run()
{
    if (!SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        1000, 500,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    renderer = SDL_CreateRenderer(window, -1, 0);

    running = true;

    draw();

    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            handleEvents(&event);
        }
    }

    TTF_Quit();
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
}

void Window::draw()
{
    if (renderer == nullptr) return;

    BACKGROUND.useAsRenderDrawColor(renderer);

    SDL_RenderClear(renderer);

    Size size = getSize();

    root.draw(renderer, Position::ZERO, size);

    SDL_RenderPresent(renderer);
}

Size Window::getSize() const
{
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    return Size(width, height);
}

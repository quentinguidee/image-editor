#include "window.hpp"

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "color.hpp"
#include "event.hpp"
#include "font.hpp"
#include "sdl_draw.hpp"

Window::Window(const string& title, std::shared_ptr<View> root) :
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

    SDL_Event sdl_event;
    Event event = Event(&sdl_event);
    while (running)
    {
        while (SDL_PollEvent(&sdl_event))
            handleEvents(event);

        if (mustRedraw) draw();
    }

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Window::handleEvents(const Event& event)
{
    if (event.quitEvent())
    {
        running = false;
        return;
    }

    if (event.windowEvent() && event.windowSizeChanged())
    {
        draw();
        return;
    }

    if (event.mouseClick() || event.mouseScroll() || event.keyPressed())
    {
        root->propagateEvent(Event(event));
        return;
    }
}

void Window::draw()
{
    if (renderer == nullptr) return;

    Color::BACKGROUND.useAsRenderDrawColor(renderer);

    SDL_RenderClear(renderer);

    Size size = getSize();

    root->draw(renderer, Position::ZERO, size);

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

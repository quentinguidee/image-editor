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

    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

    bool running = true;

    BACKGROUND.useAsRenderDrawColor(renderer);

    SDL_RenderClear(renderer);

    Size size = getSize();

    root.draw(renderer, Position::ZERO, size);

    SDL_RenderPresent(renderer);

    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            running = event.type != SDL_QUIT;
        }
    }

    TTF_Quit();
    SDL_Quit();
}

Size Window::getSize() const
{
    int width;
    int height;

    SDL_GetWindowSize(window, &width, &height);
    return Size(width, height);
}

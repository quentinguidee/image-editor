#include "window.hpp"

#include <SDL.h>

Window::Window(string title) :
    title(title) {}

void Window::run()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        1000, 500,
        SDL_WINDOW_SHOWN);

    bool running = true;

    SDL_Event event;
    while (running)
        while (SDL_PollEvent(&event))
            running = event.type != SDL_QUIT;

    SDL_Quit();
}

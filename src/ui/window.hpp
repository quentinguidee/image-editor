#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include "size.hpp"
#include "view.hpp"

using std::string;

class Window
{
private:
    string title;

    const View& root;

    bool running = false;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

public:
    Window(const string& title, const View& root);
    ~Window() {}

    void run();
    void draw();
    void handleEvents(SDL_Event* event);

    Size getSize() const;
};

#endif /* WINDOW_HPP */

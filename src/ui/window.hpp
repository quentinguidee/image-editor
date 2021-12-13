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

    View& root;

    bool running = false;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

public:
    // TODO: this temporary static mustDraw variable is awful,
    // but it's here to easily redraw the window from
    // a view. It works because we only have one window
    // for the moment, but it will not always be the case.
    static bool mustRedraw;

    Window(const string& title, View& root);
    ~Window() {}

    void run();
    void draw();
    void handleEvents(SDL_Event* event);

    Size getSize() const;
};

#endif /* WINDOW_HPP */

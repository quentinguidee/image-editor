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

    SDL_Window* window = nullptr;

public:
    Window(const string& title, const View& root);
    ~Window() {}

    void run();

    Size getSize() const;
};

#endif /* WINDOW_HPP */

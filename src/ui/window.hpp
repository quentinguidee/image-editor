#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include "view.hpp"

using std::string;

class Window
{
private:
    string title;

    const View& root;

public:
    Window(const string& title, const View& root);
    ~Window() {}

    void run();
};

#endif /* WINDOW_HPP */

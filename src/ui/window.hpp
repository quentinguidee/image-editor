#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

using std::string;

class Window
{
private:
    string title;

public:
    Window(string title);
    ~Window() {}

    void run();
};

#endif /* WINDOW_HPP */

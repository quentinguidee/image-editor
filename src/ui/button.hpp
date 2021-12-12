#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "has_background.hpp"
#include "view.hpp"

class Button : public View, public HasBackground
{
private:
    bool isToggle = false;
    bool toggled = false;

public:
    Button();
    ~Button() {}

    void useToggleBehaviour();

    bool isPressed() const;
    void toggle();
};

#endif /* BUTTON_HPP */

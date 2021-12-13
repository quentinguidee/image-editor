#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "has_background.hpp"
#include "view.hpp"

class Button : public View, public HasBackground
{
private:
    bool isToggle = false;
    bool toggled = false;

    Color fillColorSelected;
    Color fillColorUnselected;

public:
    Button();
    ~Button() {}

    void useToggleBehaviour();

    bool isPressed() const;
    void toggle();
    void setToggle(bool value);
    void unselect();
    void select();

    void setFillColorSelected(const Color& color);
    void setFillColorUnselected(const Color& color);
};

#endif /* BUTTON_HPP */

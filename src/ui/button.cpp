#include "button.hpp"

#include "rounded_rectangle.hpp"

Button::Button()
{
    setSize(36, 36);

    RoundedRectangle* background = new RoundedRectangle();
    background->setRadius(6);
    background->setSize(getSize());
    setBackgroundShape(background);
}

void Button::useToggleBehaviour()
{
    isToggle = true;
}

bool Button::isPressed() const
{
    return toggled;
}

void Button::toggle()
{
    toggled = !toggled;
}

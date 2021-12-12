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

#include "button.hpp"

#include "rounded_rectangle.hpp"

Button::Button() :
    fillColorUnselected(Color::BACKGROUND),
    fillColorSelected(Color::BACKGROUND_LIGHT)
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
    setToggle(!toggled);
}

void Button::setToggle(bool value)
{
    toggled = value;
    toggled ? setFillColor(fillColorSelected) : setFillColor(fillColorUnselected);
}

void Button::unselect()
{
    setToggle(false);
}

void Button::select()
{
    setToggle(true);
}

void Button::setFillColorSelected(const Color& color)
{
    fillColorSelected = color;
    if (toggled)
        setFillColor(color);
}

void Button::setFillColorUnselected(const Color& color)
{
    fillColorUnselected = color;
    if (!toggled)
        setFillColor(color);
}

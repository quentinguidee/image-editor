#include "tools.hpp"

#include "../ui/rounded_rectangle.hpp"

Tools::Tools()
{
    setSize(48, 300);
    setFillColor(Color::BACKGROUND_DARK);

    RoundedRectangle *background = new RoundedRectangle();
    background->setRadius(8);
    background->setSize(getSize());
    setBackgroundShape(background);
}

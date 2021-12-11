#include "tools.hpp"

#include "../ui/img.hpp"
#include "../ui/rounded_rectangle.hpp"
#include "../ui/sdl_draw.hpp"

Tools::Tools() :
    pointer(Img("src/assets/icons/ArrowIcon.png")),
    rectangle(Img("src/assets/icons/RectangleIcon.png"))
{
    setSize(48, 300);
    setFillColor(Color::BACKGROUND_DARK);

    RoundedRectangle *background = new RoundedRectangle();
    background->setRadius(8);
    background->setSize(getSize());
    setBackgroundShape(background);

    pointer.setSize(40, 40);
    pointer.setPosition(4, 4);

    rectangle.setSize(40, 40);
    rectangle.setPosition(4, 4);

    addView(pointer);
    addView(rectangle);
}

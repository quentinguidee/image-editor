#include "tools.hpp"

#include "../ui/img.hpp"
#include "../ui/rounded_rectangle.hpp"
#include "../ui/sdl_draw.hpp"

Tools::Tools() :
    pointerButton(ImageButton("src/assets/icons/ArrowIcon.png")),
    rectangleButton(ImageButton("src/assets/icons/RectangleIcon.png"))
{
    setSize(48, 300);
    setFillColor(Color::BACKGROUND_DARK);

    RoundedRectangle *background = new RoundedRectangle();
    background->setRadius(8);
    background->setSize(getSize());
    setBackgroundShape(background);

    pointerButton.setSize(36, 36);
    pointerButton.setPosition(6, 6);
    pointerButton.setFillColor(Color::BACKGROUND_DARKER);
    pointerButton.useToggleBehaviour();

    rectangleButton.setSize(36, 36);
    rectangleButton.setPosition(6, 6);
    rectangleButton.setFillColor(Color::BACKGROUND_DARKER);
    rectangleButton.useToggleBehaviour();

    addView(pointerButton);
    addView(rectangleButton);
}

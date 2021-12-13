#include "tools.hpp"

#include <iostream>

#include "../ui/img.hpp"
#include "../ui/rounded_rectangle.hpp"
#include "../ui/sdl_draw.hpp"

Tools::Tools() :
    pointerButton(ImageButton("src/assets/icons/ArrowIcon.png")),
    shapeButton(ImageButton("src/assets/icons/RectangleIcon.png"))
{
    setSize(48, 300);
    setFillColor(Color::BACKGROUND_DARK);

    RoundedRectangle* background = new RoundedRectangle();
    background->setRadius(8);
    background->setSize(getSize());
    setBackgroundShape(background);

    pointerButton.setSize(36, 36);
    pointerButton.setPosition(6, 6);
    pointerButton.setFillColor(Color::BACKGROUND_DARKER);
    pointerButton.useToggleBehaviour();
    pointerButton.setOnClick([this](const Position& position) -> void { onPointerButtonClick(position); });

    shapeButton.setSize(36, 36);
    shapeButton.setPosition(6, 6);
    shapeButton.setFillColor(Color::BACKGROUND_DARKER);
    shapeButton.useToggleBehaviour();
    shapeButton.setOnClick([this](const Position& position) -> void { onShapeButtonClick(position); });

    addView(pointerButton);
    addView(shapeButton);
}

void Tools::onPointerButtonClick(const Position& position)
{
    std::cout << "Pointer click event" << std::endl;
}

void Tools::onShapeButtonClick(const Position& position)
{
    std::cout << "Shape click event" << std::endl;
}

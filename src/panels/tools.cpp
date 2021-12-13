#include "tools.hpp"

#include <iostream>
#include <typeinfo>

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
    pointerButton.setFillColorUnselected(Color::BACKGROUND_DARKER);
    pointerButton.setFillColorSelected(Color::BACKGROUND);
    pointerButton.useToggleBehaviour();
    pointerButton.setOnClick([this](const Position& position) -> void { onPointerButtonClick(position); });

    shapeButton.setSize(36, 36);
    shapeButton.setPosition(6, 6);
    shapeButton.setFillColorUnselected(Color::BACKGROUND_DARKER);
    shapeButton.setFillColorSelected(Color::BACKGROUND);
    shapeButton.useToggleBehaviour();
    shapeButton.setOnClick([this](const Position& position) -> void { onShapeButtonClick(position); });

    addView(pointerButton);
    addView(shapeButton);
}

void Tools::onPointerButtonClick(const Position& position)
{
    unselectAll();
    std::cout << "Pointer click event" << std::endl;
    pointerButton.select();
}

void Tools::onShapeButtonClick(const Position& position)
{
    unselectAll();
    std::cout << "Shape click event" << std::endl;
    shapeButton.select();
}

void Tools::unselectAll()
{
    Views views = getSubviews();
    for (int i = 0; i < views.size(); i++)
    {
        try
        {
            ImageButton& button = dynamic_cast<ImageButton&>(views[i].get());
            button.unselect();
        } catch (std::bad_cast e)
        {
            std::cout << "Warning: Cast to ImageButton failed." << std::endl;
        }
    }
}

#include "tools.hpp"

#include <iostream>
#include <typeinfo>

#include "../ui/img.hpp"
#include "../ui/rounded_rectangle.hpp"
#include "../ui/sdl_draw.hpp"

Tools::Tools() :
    pointerButton(ImageButton("src/assets/icons/ArrowIcon.png")),
    shapeButton(ImageButton("src/assets/icons/RectangleIcon.png")),
    pencilButton(ImageButton("src/assets/icons/PencilIcon.png"))
{
    setSize(48, 128);
    setFillColor(Color::BACKGROUND_DARK);

    RoundedRectangle* background = new RoundedRectangle();
    background->setRadius(8);
    background->setSize(getSize());
    setBackgroundShape(background);

    pointerButton.setSize(36, 36);
    pointerButton.setPosition(6, 6);
    pointerButton.setFillColorSelected(Color::BACKGROUND_LIGHT);
    pointerButton.setFillColorUnselected(Color::BACKGROUND_DARK);
    pointerButton.useToggleBehaviour();
    pointerButton.setEventHandler([this](const Event& event) -> void { pointerButtonEventHandler(event); });

    shapeButton.setSize(36, 36);
    shapeButton.setPosition(6, 4);
    shapeButton.setFillColorSelected(Color::BACKGROUND_LIGHT);
    shapeButton.setFillColorUnselected(Color::BACKGROUND_DARK);
    shapeButton.useToggleBehaviour();
    shapeButton.setEventHandler([this](const Event& event) -> void { shapeButtonEventHandler(event); });

    pencilButton.setSize(36, 36);
    pencilButton.setPosition(6, 4);
    pencilButton.setFillColorSelected(Color::BACKGROUND_LIGHT);
    pencilButton.setFillColorUnselected(Color::BACKGROUND_DARK);
    pencilButton.useToggleBehaviour();
    pencilButton.setEventHandler([this](const Event& event) -> void { pencilButtonEventHandler(event); });

    addView(pointerButton);
    addView(shapeButton);
    addView(pencilButton);
}

void Tools::pointerButtonEventHandler(const Event& event)
{
    if (event.mouseClick())
    {
        unselectAll();
        std::cout << "Pointer click event" << std::endl;
        pointerButton.select();
        redraw();
    }
}

void Tools::shapeButtonEventHandler(const Event& event)
{
    if (event.mouseClick())
    {
        unselectAll();
        std::cout << "Shape click event" << std::endl;
        shapeButton.select();
        redraw();
    }
}

void Tools::pencilButtonEventHandler(const Event& event)
{
    if (event.mouseClick())
    {
        unselectAll();
        std::cout << "Pencil click event" << std::endl;
        pencilButton.select();
        redraw();
    }
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
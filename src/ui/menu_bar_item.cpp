#include "menu_bar_item.hpp"

#include <iostream>

#include "position.hpp"
#include "rounded_rectangle.hpp"
#include "sdl_draw.hpp"
#include "size.hpp"

MenuBarItem::MenuBarItem(const std::string &text) :
    text(std::make_shared<Text>(text))
{
    setPosition(6, 6);
    setBackgroundShape(std::make_shared<RoundedRectangle>(5));

    setFillColorSelected(Color::BACKGROUND_LIGHT);
    setFillColorUnselected(Color::BACKGROUND_DARK);

    Size size = this->text->getSize() + Size(24, 14);
    getBackgroundShape()->setSize(size);
    setSize(size);

    addEventHandler([this](const Event &event) -> void {
        if (event.mouseLeftClick()) select();
        if (event.mouseLeftReleased()) unselect();
        redraw();
    });
}

void MenuBarItem::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize)
{
    Position position = getPosition() + offset;
    setDrawingPosition(position);

    Size size = getSize();
    size.ensureIsSmallerThan(maxSize);
    setDrawingSize(size);

    if (isPressed())
        drawFill(renderer, position, maxSize);

    text->draw(renderer, position + Position(12, 6), maxSize);
}

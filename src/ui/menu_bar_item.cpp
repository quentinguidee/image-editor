#include "menu_bar_item.hpp"

#include "position.hpp"
#include "rounded_rectangle.hpp"
#include "size.hpp"

MenuBarItem::MenuBarItem(const std::string &text) :
    text(std::make_shared<Text>(text))
{
    setHeight(30);
    setPosition(3, 6);
    setBackgroundShape(std::make_shared<RoundedRectangle>(5));
    setFillColor(Color::BACKGROUND_LIGHT);
    setEventHandler([this](const Event &event) -> void {

    });
}

void MenuBarItem::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize)
{
    Position position = getPosition() + offset;
    setDrawingPosition(position);

    if (isPressed())
    {
        getBackgroundShape()->setSize(text->getDrawingSize() + Size(8, 16));
        drawFill(renderer, position, maxSize);
    }

    text->draw(renderer, offset + Position(18, 12), maxSize);

    setDrawingSize(getBackgroundShape()->getDrawingSize());
}

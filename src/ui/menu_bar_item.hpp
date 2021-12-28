#ifndef MENU_BAR_ITEM_HPP
#define MENU_BAR_ITEM_HPP

#include <memory>

#include "button.hpp"
#include "text.hpp"

class MenuBarItem : public Button
{
private:
    std::shared_ptr<Text> text;

public:
    MenuBarItem(const std::string &text);
    ~MenuBarItem() {}

    void draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize) override;
};

#endif /* MENU_BAR_ITEM_HPP */

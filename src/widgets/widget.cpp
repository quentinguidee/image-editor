#include "widget.hpp"

#include "../ui/text.hpp"

Widget::Widget(const string& title) :
    title(title), titleText(std::make_shared<Text>(title))
{
    titleText->uppercase();
    titleText->setFont(Font::BOLD);
    titleText->setPosition(16, 16);

    addView(titleText);
}

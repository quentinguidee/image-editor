#include "toolbar.hpp"

Toolbar::Toolbar() :
    logo(std::make_shared<Text>("Image Editor"))
{
    logo->setFont(Font::BOLD);
    logo->uppercase();
    logo->setPosition(20, 12);

    setFillColor(Color::BACKGROUND_DARK);
    setSize(Size1D::INFINITE, 42);

    addView(logo);
}

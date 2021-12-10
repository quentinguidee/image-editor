#include "toolbar.hpp"

Toolbar::Toolbar() :
    logo("Image Editor")
{
    logo.setFont(Font::BOLD);
    logo.uppercase();
    logo.setPosition(20, 12);

    setFillColor(Color::BACKGROUND_DARK);
    setSize(Size1D::INFINITE, 42);

    addView(logo);
}

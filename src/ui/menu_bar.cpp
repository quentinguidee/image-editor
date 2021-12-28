#include "menu_bar.hpp"

#include <memory>

#include "menu_bar_item.hpp"

MenuBar::MenuBar()
{
    setFillColor(Color::BACKGROUND_DARK);
    setSize(Size1D::INFINITE, 42);
}

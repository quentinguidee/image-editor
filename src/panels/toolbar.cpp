#include "toolbar.hpp"

#include <memory>

#include "../ui/menu_bar_item.hpp"

Toolbar::Toolbar()
{
    addView(std::make_shared<MenuBarItem>("File"));
    addView(std::make_shared<MenuBarItem>("Edit"));
    addView(std::make_shared<MenuBarItem>("Help"));
}

#include "tool.hpp"

#include "../ui/color.hpp"

Tool::Tool(const std::string& iconPath) :
    ImageButton(iconPath),
    iconPath(iconPath)
{
    setSize(36, 36);
    setFillColorSelected(Color::BACKGROUND_LIGHT);
    setFillColorUnselected(Color::BACKGROUND_DARK);
    setPosition(6, 6);

    useToggleBehaviour();
}

std::string Tool::getIconPath() const
{
    return iconPath;
}

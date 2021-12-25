#include "resources.hpp"

std::string Resources::getIcon(const std::string& name)
{
    return "src/resources/icons/" + name + ".png";
}

std::string Resources::getFont(const std::string& name)
{
    return "src/resources/fonts/" + name + ".ttf";
}

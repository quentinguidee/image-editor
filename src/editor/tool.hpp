#ifndef TOOL_HPP
#define TOOL_HPP

#include <string>

#include "../ui/image_button.hpp"

class Tool : public ImageButton
{
private:
    std::string iconPath;

public:
    Tool(const std::string& iconPath);
    ~Tool() {}

    std::string getIconPath() const;
};

#endif /* TOOL_HPP */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <vector>

#include "../ui/vertical_layout.hpp"
#include "tool.hpp"

class Tools : public VerticalLayout
{
private:
    std::shared_ptr<Tool> activeTool;

public:
    Tools();
    ~Tools() {}
};

#endif /* TOOLS_HPP */

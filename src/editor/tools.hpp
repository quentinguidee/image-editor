#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <vector>

#include "../ui/vertical_layout.hpp"
#include "tool.hpp"

class Tools : public VerticalLayout
{
private:
    std::vector<std::shared_ptr<Tool>> tools;

    uint8_t activeToolID = 0;

public:
    Tools();
    ~Tools() {}

    void unselectAll();
};

#endif /* TOOLS_HPP */

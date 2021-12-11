#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "../ui/img.hpp"
#include "../ui/vertical_layout.hpp"

class Tools : public VerticalLayout
{
private:
    Img pointer;
    Img rectangle;

public:
    Tools();
    ~Tools() {}
};

#endif /* TOOLS_HPP */

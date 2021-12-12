#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "../ui/image_button.hpp"
#include "../ui/vertical_layout.hpp"

class Tools : public VerticalLayout
{
private:
    ImageButton pointerButton;
    ImageButton rectangleButton;

public:
    Tools();
    ~Tools() {}
};

#endif /* TOOLS_HPP */

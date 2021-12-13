#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "../ui/image_button.hpp"
#include "../ui/vertical_layout.hpp"

class Tools : public VerticalLayout
{
private:
    ImageButton pointerButton;
    ImageButton shapeButton;

public:
    Tools();
    ~Tools() {}

    // Change tools
    void onPointerButtonClick(const Position& position);
    void onShapeButtonClick(const Position& position);
};

#endif /* TOOLS_HPP */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "../ui/image_button.hpp"
#include "../ui/vertical_layout.hpp"

class Tools : public VerticalLayout
{
private:
    ImageButton pointerButton;
    ImageButton shapeButton;

    int selection;

public:
    Tools();
    ~Tools() {}

    // Change tools
    void pointerButtonEventHandler(const Event& event);
    void shapeButtonEventHandler(const Event& event);

    void unselectAll();
};

#endif /* TOOLS_HPP */

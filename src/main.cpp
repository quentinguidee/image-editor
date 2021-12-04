#include "ui/color.hpp"
#include "ui/rectangle.hpp"
#include "ui/window.hpp"

int main()
{
    Rectangle rectangle = Rectangle();
    rectangle.setFillColor(BACKGROUND_DARK);
    rectangle.setPosition(20, 20);
    rectangle.setSize(80, 50);

    Window window = Window("Image Editor", rectangle);
    window.run();

    return 0;
}

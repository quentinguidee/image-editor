#include "ui/color.hpp"
#include "ui/rectangle.hpp"
#include "ui/window.hpp"

int main()
{
    Rectangle rectangle = Rectangle();
    rectangle.fill(RED);

    Window window = Window("Image Editor", rectangle);
    window.run();

    return 0;
}

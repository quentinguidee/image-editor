#include "ui/color.hpp"
#include "ui/horizontal_layout.hpp"
#include "ui/rectangle.hpp"
#include "ui/size.hpp"
#include "ui/window.hpp"

int main()
{
    HorizontalLayout leftPane = HorizontalLayout();
    leftPane.setFillColor(BACKGROUND);
    leftPane.setSize(Size::INFINITE);

    HorizontalLayout rightPane = HorizontalLayout();
    rightPane.setFillColor(BACKGROUND_DARK);
    rightPane.setSize(Size(240, Size1D::INFINITE));

    HorizontalLayout root = HorizontalLayout();
    root.addView(leftPane);
    root.addView(rightPane);
    root.setSize(Size::UNDEFINED);

    string title = "Image Editor";
    Window window = Window(title, root);

    window.run();

    return 0;
}

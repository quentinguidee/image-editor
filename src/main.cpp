#include "editor/image_editor.hpp"
#include "panels/widgets_panel.hpp"
#include "ui/color.hpp"
#include "ui/horizontal_layout.hpp"
#include "ui/rectangle.hpp"
#include "ui/size.hpp"
#include "ui/text.hpp"
#include "ui/window.hpp"

int main()
{
    ImageEditor imageEditor = ImageEditor();
    imageEditor.setSize(Size::INFINITE);

    WidgetsPanel widgetsPanel = WidgetsPanel();
    widgetsPanel.setFillColor(BACKGROUND_DARK);
    widgetsPanel.setSize(Size(240, Size1D::INFINITE));

    HorizontalLayout root = HorizontalLayout();
    root.addView(imageEditor);
    root.addView(widgetsPanel);
    root.setSize(Size::UNDEFINED);

    string title = "Image Editor";
    Window window = Window(title, root);

    window.run();

    return 0;
}

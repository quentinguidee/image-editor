#include "editor/image_editor.hpp"
#include "panels/toolbar.hpp"
#include "panels/widgets_panel.hpp"
#include "ui/color.hpp"
#include "ui/horizontal_layout.hpp"
#include "ui/rectangle.hpp"
#include "ui/size.hpp"
#include "ui/text.hpp"
#include "ui/vertical_layout.hpp"
#include "ui/window.hpp"

int main()
{
    Toolbar toolbar = Toolbar();
    toolbar.setSize(Size1D::INFINITE, 32);

    ImageEditor imageEditor = ImageEditor();
    imageEditor.setSize(Size::INFINITE);

    WidgetsPanel widgetsPanel = WidgetsPanel();
    widgetsPanel.setFillColor(BACKGROUND_DARK);
    widgetsPanel.setSize(Size(240, Size1D::INFINITE));

    HorizontalLayout content = HorizontalLayout();
    content.addView(imageEditor);
    content.addView(widgetsPanel);
    content.setSize(Size::INFINITE);

    VerticalLayout root = VerticalLayout();
    root.addView(toolbar);
    root.addView(content);
    root.setSize(Size::INFINITE);

    string title = "Image Editor";
    Window window = Window(title, root);

    window.run();

    return 0;
}

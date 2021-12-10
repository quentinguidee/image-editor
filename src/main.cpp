#include "editor/image_editor.hpp"
#include "panels/toolbar.hpp"
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

    ImageEditor editor = ImageEditor();
    editor.setSize(Size::INFINITE);

    VerticalLayout root = VerticalLayout();
    root.addView(toolbar);
    root.addView(editor);
    root.setSize(Size::INFINITE);

    string title = "Image Editor";
    Window window = Window(title, root);

    window.run();

    return 0;
}

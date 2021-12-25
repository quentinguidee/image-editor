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
    std::shared_ptr<Toolbar> toolbar = std::make_shared<Toolbar>();

    std::shared_ptr<ImageEditor> editor = std::make_shared<ImageEditor>();
    editor->setSize(Size::INFINITE);

    std::shared_ptr<VerticalLayout> root = std::make_shared<VerticalLayout>();
    root->addView(toolbar);
    root->addView(editor);
    root->setSize(Size::INFINITE);

    string title = "Image Editor";
    Window window = Window(title, root);

    window.run();

    return 0;
}

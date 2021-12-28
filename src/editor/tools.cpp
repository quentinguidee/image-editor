#include "tools.hpp"

#include <iostream>
#include <memory>

#include "../resources/resources.hpp"
#include "../ui/img.hpp"
#include "../ui/rounded_rectangle.hpp"

Tools::Tools()
{
    addView(std::make_shared<Tool>(Resources::getIcon("ArrowIcon")));
    addView(std::make_shared<Tool>(Resources::getIcon("RectangleIcon")));
    addView(std::make_shared<Tool>(Resources::getIcon("PencilIcon")));

    setSize(48, 132);
    setFillColor(Color::BACKGROUND_DARK);

    std::shared_ptr<RoundedRectangle> background = std::make_shared<RoundedRectangle>();
    background->setRadius(8);
    background->setSize(getSize());
    setBackgroundShape(background);

    for (size_t i = 0; i < getViews().size(); i++)
    {
        getView(i)->addEventHandler([this, i](const Event& event) -> void {
            if (event.mouseLeftClick())
            {
                if (activeTool != nullptr) activeTool->unselect();
                activeTool = getView<Tool>(i);
                if (activeTool == nullptr)
                    std::cerr << "Couldn't cast View to Tool" << std::endl;
                activeTool->select();
                redraw();
            }
        });
    }
}

#include "tools.hpp"

#include <memory>

#include "../resources/resources.hpp"
#include "../ui/img.hpp"
#include "../ui/rounded_rectangle.hpp"

Tools::Tools() :
    tools(std::vector<std::shared_ptr<Tool>>())
{
    tools.push_back(std::make_shared<Tool>(Resources::getIcon("ArrowIcon")));
    tools.push_back(std::make_shared<Tool>(Resources::getIcon("RectangleIcon")));
    tools.push_back(std::make_shared<Tool>(Resources::getIcon("PencilIcon")));

    setSize(48, 132);
    setFillColor(Color::BACKGROUND_DARK);

    std::shared_ptr<RoundedRectangle> background = std::make_shared<RoundedRectangle>();
    background->setRadius(8);
    background->setSize(getSize());
    setBackgroundShape(background);

    for (size_t i = 0; i < tools.size(); i++)
    {
        addView(tools[i]);
        tools[i]->setEventHandler([this, i](const Event& event) -> void {
            if (event.mouseClick())
            {
                unselectAll();
                activeTool = tools[i];
                activeTool->select();
                redraw();
            }
        });
    }
}

void Tools::unselectAll()
{
    for (size_t i = 0; i < tools.size(); i++)
        tools[i]->unselect();

    activeTool = nullptr;
}

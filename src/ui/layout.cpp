#include "layout.hpp"

#include <memory>

#include "rectangle.hpp"

Layout::Layout() :
    views(std::vector<std::shared_ptr<View>>())
{
    setBackgroundShape(std::make_shared<Rectangle>());
}

void Layout::addView(std::shared_ptr<View> view)
{
    views.push_back(view);
}

std::vector<std::shared_ptr<View>> Layout::getViews()
{
    return views;
}

std::shared_ptr<View> Layout::getView(int i)
{
    return views[i];
}

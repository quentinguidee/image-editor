#include "layout.hpp"
#include <memory>

#include "rectangle.hpp"

Layout::Layout() :
    views(Views())
{
    setBackgroundShape(std::make_shared<Rectangle>());
}

void Layout::addView(std::shared_ptr<View> view)
{
    views.push_back(view);
}

Views Layout::getSubviews()
{
    return views;
}

#include "layout.hpp"

#include "rectangle.hpp"

Layout::Layout() :
    views(Views())
{
    setBackgroundShape(new Rectangle());
}

void Layout::addView(std::shared_ptr<View> view)
{
    views.push_back(view);
}

Views Layout::getSubviews()
{
    return views;
}

#include "layout.hpp"

#include "rectangle.hpp"

Layout::Layout() :
    views(vector<reference_wrapper<const View>>())
{
    setBackgroundShape(new Rectangle());
}

void Layout::addView(const View& view)
{
    views.push_back(view);
}

const vector<reference_wrapper<const View>>& Layout::getViews() const
{
    return views;
}

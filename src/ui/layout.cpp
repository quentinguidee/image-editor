#include "layout.hpp"

#include "rectangle.hpp"

Layout::Layout() :
    views(vector<reference_wrapper<const View>>())
{
}

void Layout::addView(const View& view)
{
    views.push_back(view);
}

const vector<reference_wrapper<const View>>& Layout::getViews() const
{
    return views;
}

void Layout::drawFill(SDL_Renderer* renderer, const Position& offset, const Size& forcedSize) const
{
    Rectangle background = Rectangle();
    background.setFillColor(getFillColor());

    background.draw(renderer, offset, forcedSize);
}

#ifndef HORIZONTAL_LAYOUT_HPP
#define HORIZONTAL_LAYOUT_HPP

#include "fillable.hpp"
#include "layout.hpp"
#include "rectangle.hpp"

class HorizontalLayout : public Layout
{
private:
public:
    HorizontalLayout();
    ~HorizontalLayout() {}

    void draw(SDL_Renderer* renderer, const Position& offset, const Size& forcedSize) const override;
};

#endif /* HORIZONTAL_LAYOUT_HPP */

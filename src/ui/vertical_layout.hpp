#ifndef VERTICAL_LAYOUT_HPP
#define VERTICAL_LAYOUT_HPP

#include "linear_layout.hpp"

class VerticalLayout : public LinearLayout
{
private:
public:
    VerticalLayout() {}
    ~VerticalLayout() {}

    void draw(SDL_Renderer* renderer, const Position& offset, const Size& forcedSize) const override;
};

#endif /* VERTICAL_LAYOUT_HPP */

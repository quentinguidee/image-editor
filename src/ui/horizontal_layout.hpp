#ifndef HORIZONTAL_LAYOUT_HPP
#define HORIZONTAL_LAYOUT_HPP

#include "linear_layout.hpp"

class HorizontalLayout : public LinearLayout
{
private:
public:
    HorizontalLayout();
    ~HorizontalLayout() {}

    void draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) override;
};

#endif /* HORIZONTAL_LAYOUT_HPP */

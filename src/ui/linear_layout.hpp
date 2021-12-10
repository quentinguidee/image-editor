#ifndef LINEAR_LAYOUT_HPP
#define LINEAR_LAYOUT_HPP

#include "layout.hpp"
#include "rectangle.hpp"

class LinearLayout : public Layout
{
private:
public:
    LinearLayout();
    ~LinearLayout() {}

    void drawStack(SDL_Renderer* renderer, const Position& offset, const Size& maxSize, uint8_t dimension) const;
};

#endif /* LINEAR_LAYOUT_HPP */

#ifndef ROUNDED_RECTANGLE_HPP
#define ROUNDED_RECTANGLE_HPP

#include "shape.hpp"

class RoundedRectangle : public Shape
{
private:
    uint8_t radius = 0;

public:
    RoundedRectangle() {}
    ~RoundedRectangle() {}

    void setRadius(uint8_t radius);

    void draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) const override;
    void drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) const override;
};

#endif /* ROUNDED_RECTANGLE_HPP */

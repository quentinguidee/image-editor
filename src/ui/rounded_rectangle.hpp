#ifndef ROUNDED_RECTANGLE_HPP
#define ROUNDED_RECTANGLE_HPP

#include "shape.hpp"

class RoundedRectangle : public Shape
{
private:
    uint8_t radius;

public:
    RoundedRectangle(int radius = 5);
    ~RoundedRectangle() {}

    void setRadius(uint8_t radius);

    void draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) override;
    void drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) override;
};

#endif /* ROUNDED_RECTANGLE_HPP */

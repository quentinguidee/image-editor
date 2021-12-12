#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "view.hpp"

class Rectangle : public Shape
{
private:
public:
    Rectangle() {}
    ~Rectangle() {}

    void draw(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) override;
    void drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) override;
};

#endif /* RECTANGLE_HPP */

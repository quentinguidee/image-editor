#ifndef FILLABLE_HPP
#define FILLABLE_HPP

#include "color.hpp"
#include "position.hpp"
#include "size.hpp"

class Fillable
{
private:
    Color fillColor;

public:
    Fillable();
    ~Fillable() {}

    void setFillColor(const Color& color);
    const Color& getFillColor() const;

    void beforeDrawFill(SDL_Renderer* renderer) const;
    virtual void drawFill(SDL_Renderer* renderer, const Position& offset, const Size& forcedSize) const = 0;
};

#endif /* FILLABLE_HPP */

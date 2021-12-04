#ifndef FILLABLE_HPP
#define FILLABLE_HPP

#include "color.hpp"

class Fillable
{
private:
    Color fillColor;

public:
    Fillable();
    ~Fillable() {}

    void fill(const Color& color);
    const Color& getFillColor() const;

    void beforeDrawFill(SDL_Renderer* renderer) const;
    virtual void drawFill(SDL_Renderer* renderer) const = 0;
};

#endif /* FILLABLE_HPP */

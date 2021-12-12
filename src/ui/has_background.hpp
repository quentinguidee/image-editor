#ifndef HAS_BACKGROUND_HPP
#define HAS_BACKGROUND_HPP

#include "fillable.hpp"
#include "shape.hpp"

class HasBackground : public Fillable
{
private:
    Shape* shape;

public:
    HasBackground();
    ~HasBackground();

    void setBackgroundShape(Shape* shape);
    const Shape* getBackgroundShape() const;

    void drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) override;
};

#endif /* HAS_BACKGROUND_HPP */

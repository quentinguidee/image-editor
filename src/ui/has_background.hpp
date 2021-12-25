#ifndef HAS_BACKGROUND_HPP
#define HAS_BACKGROUND_HPP

#include "fillable.hpp"
#include "shape.hpp"

class HasBackground : public Fillable
{
private:
    std::shared_ptr<Shape> shape;

public:
    HasBackground();
    ~HasBackground() {}

    void setBackgroundShape(std::shared_ptr<Shape> shape);
    const std::shared_ptr<Shape> getBackgroundShape() const;

    void drawFill(SDL_Renderer* renderer, const Position& offset, const Size& maxSize) override;
};

#endif /* HAS_BACKGROUND_HPP */

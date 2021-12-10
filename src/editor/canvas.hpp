#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "../ui/view.hpp"
#include "image.hpp"

class Canvas : public View
{
private:
    Image image;

public:
    Canvas();
    ~Canvas() {}

    void draw(SDL_Renderer *renderer, const Position &offset, const Size &forcedSize) const override;
};

#endif /* CANVAS_HPP */

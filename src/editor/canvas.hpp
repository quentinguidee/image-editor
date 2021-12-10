#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "../ui/view.hpp"

class Canvas : public View
{
private:
public:
    Canvas();
    ~Canvas() {}

    void draw(SDL_Renderer *renderer, const Position &offset, const Size &forcedSize) const override;
};

#endif /* CANVAS_HPP */

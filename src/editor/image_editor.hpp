#ifndef IMAGE_EDITOR_HPP
#define IMAGE_EDITOR_HPP

#include "../ui/view.hpp"
#include "canvas.hpp"
#include "tools.hpp"

class ImageEditor : public View
{
private:
    Canvas canvas;
    Tools tools;

public:
    ImageEditor();
    ~ImageEditor() {}

    void draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize) override;
    Views getSubviews() override;

    void eventHandler(const Event &event);
    void eventZoom(const Position &position, float scrollY);
    void eventMove(float scrollX, float scrollY);
};

#endif /* IMAGE_EDITOR_HPP */

#ifndef IMAGE_EDITOR_HPP
#define IMAGE_EDITOR_HPP

#include "../panels/tools.hpp"
#include "../ui/view.hpp"
#include "canvas.hpp"

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
};

#endif /* IMAGE_EDITOR_HPP */

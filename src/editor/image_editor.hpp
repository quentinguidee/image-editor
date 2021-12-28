#ifndef IMAGE_EDITOR_HPP
#define IMAGE_EDITOR_HPP

#include "../ui/view.hpp"
#include "canvas.hpp"
#include "tools.hpp"

class ImageEditor : public Layout
{
private:
    std::shared_ptr<Canvas> canvas;
    std::shared_ptr<Tools> tools;

public:
    ImageEditor();
    ~ImageEditor() {}

    void draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize) override;

    void eventHandler(const Event &event);
    void eventZoom(const Position &position, float scrollY);
    void eventMove(float scrollX, float scrollY);
};

#endif /* IMAGE_EDITOR_HPP */

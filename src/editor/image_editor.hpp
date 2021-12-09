#ifndef IMAGE_EDITOR_HPP
#define IMAGE_EDITOR_HPP

#include "../ui/view.hpp"

class ImageEditor : public View
{
private:
public:
    ImageEditor() {}
    ~ImageEditor() {}

    void draw(SDL_Renderer *renderer, const Position &offset, const Size &forcedSize) const override;
};

#endif /* IMAGE_EDITOR_HPP */

#ifndef IMAGE_BUTTON_HPP
#define IMAGE_BUTTON_HPP

#include "button.hpp"
#include "img.hpp"

class ImageButton : public Button
{
private:
    Img image;

public:
    ImageButton(const string &imagePath);
    ~ImageButton() {}

    void draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize) override;

    void setWidth(float value) override;
    void setHeight(float value) override;

    Img &getImage();
};

#endif /* IMAGE_BUTTON_HPP */

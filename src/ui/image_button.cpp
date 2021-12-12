#include "image_button.hpp"

#include "img.hpp"
#include "view.hpp"

ImageButton::ImageButton(const string &imagePath) :
    image(imagePath)
{
    // 2/2 are paddings. We could add a padding modifier later.
    image.setPosition(2, 2);
}

void ImageButton::setWidth(uint16_t value)
{
    View::setWidth(value);
    image.setWidth(value - 4);
}

void ImageButton::setHeight(uint16_t value)
{
    View::setHeight(value);
    image.setHeight(value - 4);
}

Img &ImageButton::getImage()
{
    return image;
}

void ImageButton::draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize)
{
    drawFill(renderer, offset + getPosition(), maxSize);

    image.draw(renderer, offset + getPosition(), maxSize);
}

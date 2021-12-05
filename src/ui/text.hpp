#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>

#include "color.hpp"
#include "font.hpp"
#include "view.hpp"

using std::string;

class Text : public View
{
private:
    string value;
    Font font;

    Color textColor;

public:
    Text(const string &value);
    ~Text() {}

    void draw(SDL_Renderer *renderer, const Position &offset, const Size &forcedSize) const override;

    void setTextColor(const Color &color);
    void setFont(const Font &font);

    void uppercase();
};

#endif /* TEXT_HPP */

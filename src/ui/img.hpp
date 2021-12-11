#ifndef IMG_HPP
#define IMG_HPP

#include <string>

#include "view.hpp"

using std::string;

class Img : public View
{
private:
    string path;

public:
    Img(const string &path);
    ~Img() {}

    void draw(SDL_Renderer *renderer, const Position &offset, const Size &maxSize) const override;
};

#endif /* IMG_HPP */

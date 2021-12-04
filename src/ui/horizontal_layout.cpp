#include "horizontal_layout.hpp"

#include <functional>

#include "color.hpp"
#include "layout.hpp"
#include "position.hpp"
#include "rectangle.hpp"
#include "size.hpp"

using std::reference_wrapper;
using std::vector;

HorizontalLayout::HorizontalLayout()
{
}

void HorizontalLayout::draw(SDL_Renderer* renderer, const Position& offset, const Size& forcedSize) const
{
    drawFill(renderer, offset, forcedSize);

    const vector<reference_wrapper<const View>> views = getViews();

    Size1D maxSize = forcedSize.width.isUndefined() ? getWidth() : forcedSize.width;
    Size1D usedSize = Size1D(0);
    Size1D freeSize = Size1D(0);

    uint8_t fullSizeCount = 0;
    for (int i = 0; i < views.size(); i++)
    {
        const View& view = views[i].get();

        Size1D viewSize = view.getWidth();

        if (viewSize.isInfinite())
            fullSizeCount++;
        else
            usedSize += viewSize;
    }

    freeSize.width = maxSize.width - usedSize.width;

    Size1D sizePerView = Size1D(fullSizeCount == 0 ? 0 : freeSize.width / fullSizeCount);

    Position currentOffset = offset;

    for (int i = 0; i < views.size(); i++)
    {
        const View& view = views[i].get();

        Size s = view.getSize();
        if (s.width.isInfinite())
            s.width = sizePerView;
        if (s.height > getSize().height)
            s.height = getSize().height;

        view.draw(renderer, currentOffset, s);

        currentOffset.x += Position1D(s.width);
    }
}

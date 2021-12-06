#include "linear_layout.hpp"

#include <functional>

#include "color.hpp"
#include "layout.hpp"
#include "position.hpp"
#include "rectangle.hpp"
#include "size.hpp"

using std::reference_wrapper;
using std::vector;

LinearLayout::LinearLayout()
{
}

void LinearLayout::drawStack(SDL_Renderer* renderer, const Position& offset, const Size& forcedSize, uint8_t dimension) const
{
    drawFill(renderer, offset, forcedSize);

    const vector<reference_wrapper<const View>> views = getViews();

    Size1D maxSize = forcedSize[dimension].isUndefined() ? getSize()[dimension] : forcedSize[dimension];
    Size1D usedSize = Size1D(0);
    Size1D freeSize = Size1D(0);

    uint8_t fullSizeCount = 0;
    for (int i = 0; i < views.size(); i++)
    {
        const View& view = views[i].get();

        Size1D viewSize = view.getSize()[dimension];

        if (viewSize.isInfinite())
            fullSizeCount++;
        else
            usedSize += viewSize;
    }

    freeSize = maxSize - usedSize;

    Size1D sizePerView = Size1D(fullSizeCount == 0 ? 0 : freeSize.width / fullSizeCount);

    Position currentOffset = offset;

    for (int i = 0; i < views.size(); i++)
    {
        const View& view = views[i].get();

        Size s = view.getSize();

        if (dimension == 0)
        {
            if (s.width.isInfinite())
                s.width = sizePerView;
            if (s.height > getSize().height)
                s.height = getSize().height;
        }
        else
        {
            if (s.height.isInfinite())
                s.height = sizePerView;
            if (s.width > getSize().width)
                s.width = getSize().width;
        }

        view.draw(renderer, currentOffset, s);

        if (dimension == 0)
            currentOffset.x += Position1D(s.width);
        else
            currentOffset.y += Position1D(s.height);
    }
}

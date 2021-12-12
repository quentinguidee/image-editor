#include "linear_layout.hpp"

#include <functional>

#include "color.hpp"
#include "layout.hpp"
#include "position.hpp"
#include "rectangle.hpp"
#include "size.hpp"
#include "view.hpp"

LinearLayout::LinearLayout()
{
}

void LinearLayout::drawStack(SDL_Renderer* renderer, const Position& offset, const Size& maxSize, uint8_t dimension)
{
    drawFill(renderer, offset, maxSize);

    setDrawingPosition(getPosition() + offset);

    Size size = getSize();
    size.ensureIsSmallerThan(maxSize);
    setDrawingSize(size);

    Views views = getSubviews();

    Size1D realMaxSize = size[dimension];
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

    freeSize = realMaxSize - usedSize;

    Size1D sizePerView = Size1D(fullSizeCount == 0 ? 0 : freeSize.width / fullSizeCount);

    Position currentOffset = offset;

    for (int i = 0; i < views.size(); i++)
    {
        View& view = views[i].get();

        Size childMaxSize = view.getSize();

        if (dimension == 0)
        {
            if (childMaxSize.width.isInfinite())
                childMaxSize.width = sizePerView;

            if (childMaxSize.height > getSize().height)
                childMaxSize.height = getSize().height;
            else if (childMaxSize.height > maxSize.height)
                childMaxSize.height = maxSize.height;
        }
        else
        {
            if (childMaxSize.height.isInfinite())
                childMaxSize.height = sizePerView;

            if (childMaxSize.width > getSize().width)
                childMaxSize.width = getSize().width;
            else if (childMaxSize.width > maxSize.width)
                childMaxSize.width = maxSize.width;
        }

        view.draw(renderer, currentOffset, childMaxSize);

        if (dimension == 0)
            currentOffset.x += Position1D(childMaxSize.width + view.getX());
        else
            currentOffset.y += Position1D(childMaxSize.height + view.getY());
    }
}

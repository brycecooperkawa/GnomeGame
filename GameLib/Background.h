/**
 * @file Background.h
 * @author Logan Gillis
 * @author Austin Stickney
 *
 * Item that displays a background.
 */

#ifndef PROJECT1_BACKGROUND_H
#define PROJECT1_BACKGROUND_H

#include "Item.h"
#include "ItemVisitor.h"

/**
 * Item that displays a background in-game.
 */
class Background : public Item {
private:
    /// The underlying item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmap;

public:
    Background(Game* game, std::shared_ptr<wxImage> image);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX);

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitBackground(this); }
};

#endif //PROJECT1_BACKGROUND_H

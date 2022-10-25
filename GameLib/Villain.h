/**
 * @file Villain.h
 * @author Austin Stickney
 *
 */

#ifndef PROJECT1_VILLAIN_H
#define PROJECT1_VILLAIN_H

#include "Item.h"
#include "ItemVisitor.h"

/**
 * Base Class for villains in our game
 */
class Villain : public Item {
private:
    /// The underlying item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmap;

    ///Speed the villain moves on the Y-axis
    double mSpeedY;

    ///Top height of the villain
    double mTopHeight;

public:
    Villain(Game* game, std::shared_ptr<wxImage> image);

    void Update(double elapsed) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitVillain(this); }
};

#endif //PROJECT1_VILLAIN_H

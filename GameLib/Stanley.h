/**
 * @file Stanley.h
 * @author Austin Stickney
 */

#ifndef PROJECT1_STANLEY_H
#define PROJECT1_STANLEY_H

#include "Item.h"
#include "ItemVisitor.h"

/**
 * Base class for Stanley in our game.
 */
class Stanley : public Item {
private:
/// The underlying item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmap;

    /// Whether stanley has been collected or not
    bool mCollected = false;

    /// Timer for collect animation
    double mAnimationTimer = 0;

    /// Location the stanley is collected at
    double mCollectedLocation;

    /// Size for animation text
    double mTextSize = 20;

public:
    Stanley(Game* game, std::shared_ptr<wxImage> image);

    void Update(double elapsed) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    bool GetCollected() const { return mCollected; }

    void SetCollected(bool collected);

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitStanley(this); }
};

#endif //PROJECT1_STANLEY_H

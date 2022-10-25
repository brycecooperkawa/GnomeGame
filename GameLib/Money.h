/**
 * @file Money.h
 * @author Logan Gillis
 *
 * The money item class.
 */

#ifndef PROJECT1_MONEY_H
#define PROJECT1_MONEY_H

#include "Item.h"
#include "Game.h"

/**
 * Base Class for money in our game
 */
class Money : public Item {
private:
    /// Game this money belongs to
    Game* mGame;

    /// Value of the money item
    int mValue = 0;

    /// Image to draw item
    std::shared_ptr<wxImage> mImage;

    /// Bitmap of image
    std::shared_ptr<wxBitmap> mBitmap;

    /// Whether the money has been collected or not
    bool mCollected = false;

    /// Timer for collect animation
    double mAnimationTimer = 0;

public:
    Money(Game* game, std::shared_ptr<wxImage> image, int value);

    void Update(double elapsed) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * True or false whether the loan has been collected
    * @return If its been collected
    */
    bool GetCollected() const { return mCollected; }

    /**
    * Set the animation if its been collected
    * @return If its been collected, and the animation timer
    */
    void SetCollected(bool collected) { mCollected = collected; mAnimationTimer = 5; }

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitMoney(this); }

    /**
    * Get the value of the loan
    * @return Value of the loan
    */
    int GetValue() const { return mValue; }
};

#endif //PROJECT1_MONEY_H

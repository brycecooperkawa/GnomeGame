/**
 * @file Loan.h
 * @author Bryce Cooperkawa
 *
 * Loan item that decreases score.
 */

#ifndef PROJECT1_LOAN_H
#define PROJECT1_LOAN_H

#include "Item.h"
#include "Game.h"

/**
 * Loan item that decreases score.
 */
class Loan : public Item {
private:
    /// Value of the item
    int mValue = 0;

    /// Image to draw item
    std::shared_ptr<wxImage> mImage;

    /// Whether or not the loan has been collected
    bool mCollected = false;

    /// Timer for collect animation
    double mAnimationTimer = 0;

public:
    Loan(Game* game, std::shared_ptr<wxImage> image, int value);

    void Update(double elapsed) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitLoan(this); }

    /**
     * Get the value of the loan
     * @return Value of the loan
     */
    int GetValue() const { return mValue; }

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
};

#endif //PROJECT1_LOAN_H

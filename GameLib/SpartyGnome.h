/**
 * @file SpartyGnome.h
 * @author Bryce Cooperkawa
 * @author Matthew Norris
 * @author Austin Stickney
 * @author John Foss
 * @author Logan Gillis
 */

#ifndef PROJECT1_SPARTYGNOME_H
#define PROJECT1_SPARTYGNOME_H

#include "Item.h"
#include "ItemVisitor.h"

/**
 * Class that describes the playable character, Sparty Gnome
 */
class SpartyGnome : public Item {
private:
    /// The game the gnome is a part of
    Game* mGame;

    /// The gnome image
    std::unique_ptr<wxImage> mGnomeImage;

    /// The bitmap of the gnome
    std::unique_ptr<wxBitmap> mGnomeBitmap;

    /// Turn to true if left was pressed
    bool mLeft = false;
    /// Turn to true if right was pressed
    bool mRight = false;
    /// Turn to true if space was pressed
    bool mSpace = false;

    /// Timer for walking right animation (for steps)
    double mRightTimer=0;
    /// Timer for walking left animation (for steps)
    double mLeftTimer=0;

    ///Timer that keeps track of in game time
    double mTimer=0;

    /// 2D vector for holding velocity
    Vector mV;

public:
    /// Default constructor (disabled)
    SpartyGnome() = delete;

    /// Copy constructor (disabled)
    SpartyGnome(const SpartyGnome &) = delete;

    /// Assignment operator
    void operator=(const SpartyGnome &) = delete;

    SpartyGnome(Game* game);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Update(double elapsed) override;

    void moveRight();

    void moveLeft();

    void moveJump();

    void stopMoveRight();

    void stopMoveLeft();

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitGnome(this); }

    void Reset();
};

#endif //PROJECT1_SPARTYGNOME_H

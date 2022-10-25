/**
 * @file Item.h
 * @author Austin Stickney
 *
 * Base class for any item in our game.
 */

#ifndef PROJECT1_ITEM_H
#define PROJECT1_ITEM_H

#include "Vector.h"

class Game;
class ItemVisitor;

/**
 * Base class for any item in our game.
 */
class Item {
private:
    /// The game this item is contained in
    Game *mGame;

    ///< X location for the center of the item
    double mX = 0;

    ///< Y location for the center of the item
    double  mY = 0;

    /// The underlying item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmap;

    Vector mPos;

public:
    Item(Game* game, std::shared_ptr<wxImage> image);

    /**
     * Destructor
     */
    virtual ~Item() {}

    /**
    * The X location of the item
    * @return X location in pixels
    */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    Vector GetP() { mPos.Set(mX, mY); return mPos; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    /**
     * The width of the item
     * @return half the width of the item in pixels
     */
    virtual double GetWid() const { return (mItemBitmap->GetWidth()); }

    /**
     * The height of the item
     * @return half the height of the item in pixels
     */
    virtual double GetHit() const { return (mItemBitmap->GetHeight()); }

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = default;

    /// Assignment operator
    void operator=(const Item &) = delete;

    /**
    * Handle updates for animation
    * @param elapsed The time since the last update
    */
    virtual void Update(double elapsed) {}

    /**
    * Get the game
    * @return mGame The game this item is contained in
    */
    Game *GetGame() { return mGame; }

    virtual void XmlLoad(wxXmlNode *node);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    virtual void Accept(ItemVisitor* visitor) = 0;
};

#endif //PROJECT1_ITEM_H

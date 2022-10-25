/**
 * @file Door.h
 * @author Austin Stickney
 */

#ifndef PROJECT1_DOOR_H
#define PROJECT1_DOOR_H

#include "Item.h"
#include "ItemVisitor.h"

/**
 * The door item so the player can advance to the next level.
 */
class Door : public Item {
private:
    /// The underlying item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmap;

    /// Whether the door has been used or not
    bool mUsed = false;

public:
    Door(Game* game, std::shared_ptr<wxImage>& image);

    /**
    * Get if Sparty has reached the door
    * @return if the door has been used
    */
    bool GetUsed() const { return mUsed; }

    /**
    * Set if Sparty has reached the door
    */
    void SetUsed(bool used) { mUsed = used; }

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitDoor(this); }
};

#endif //PROJECT1_DOOR_H

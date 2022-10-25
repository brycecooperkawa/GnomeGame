/**
 * @file Wall.h
 * @author Austin Stickney
 */

#ifndef PROJECT1_WALL_H
#define PROJECT1_WALL_H

#include "Item.h"
#include "ItemVisitor.h"

/**
 * Base Class for walls in our game
 */
class Wall : public Item {
private:
    /// The underlying item image
    std::shared_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmap;

    /// The width of a Wall
    double mWidth;
    /// The height of a Wall
    double mHeight;

public:
    Wall(Game* game, std::shared_ptr<wxImage> image);

    void XmlLoad(wxXmlNode *node) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    double GetWid() const override { return mWidth;}

    double GetHit() const override { return mHeight;}

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitWall(this); }
};

#endif //PROJECT1_WALL_H

/**
 * @file Platform.h
 * @author Austin Stickney
 *
 * Base Class for the platform objects
 */

#ifndef PROJECT1_PLATFORM_H
#define PROJECT1_PLATFORM_H

#include "Item.h"
#include "ItemVisitor.h"

/**
 * Base class for any platform in our game.
 */
class Platform : public Item {
private:
    /// The underlying item image (left side)
    std::shared_ptr<wxImage> mLeftImage;

    /// The bitmap we can display for this item (left side)
    std::shared_ptr<wxBitmap> mLeftBitmap;

    /// The underlying item image (middle)
    std::shared_ptr<wxImage> mMidImage;

    /// The bitmap we can display for this item (middle)
    std::shared_ptr<wxBitmap> mMidBitmap;

    /// The underlying item image (right side)
    std::shared_ptr<wxImage> mRightImage;

    /// The bitmap we can display for this item (right side)
    std::shared_ptr<wxBitmap> mRightBitmap;

    /// The width of a platform
    double mWidth = 0;

    /// The height of a platform
    double mHeight = 0;

public:
    Platform(Game* game, std::shared_ptr<wxImage> leftImage, std::shared_ptr<wxImage> midImage,
            std::shared_ptr<wxImage> rightImage);

    void XmlLoad(wxXmlNode *node) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitPlatform(this); }

    /**
    * Get the width of the platform
    */
    double GetWid() const override { return mWidth; }

    /**
    * Get the height of the platform
    */
    double GetHit() const override {return mHeight; }

};

#endif //PROJECT1_PLATFORM_H

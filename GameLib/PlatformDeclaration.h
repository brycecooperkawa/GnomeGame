/**
 * @file PlatformDeclaration.h
 * @author Logan Gillis
 *
 * Class that loads and stores information about a platform.
 */

#ifndef PROJECT1_PLATFORMDECLARATION_H
#define PROJECT1_PLATFORMDECLARATION_H

#include "Declaration.h"

/**
 * Class that describes a platform declaration
 */
class PlatformDeclaration : public Declaration {
private:
    /// Image to be displayed on the leftmost side
    std::shared_ptr<wxImage> mLeftImage;

    /// Image to be displayed in the middle
    std::shared_ptr<wxImage> mMidImage;

    /// Image to be displayed on the rightmost side
    std::shared_ptr<wxImage> mRightImage;

public:
    void XmlLoad(wxXmlNode *node) override;

    std::shared_ptr<Item> GenerateItem(Game* game) override;
};

#endif //PROJECT1_PLATFORMDECLARATION_H

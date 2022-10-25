/**
 * @file WallDeclaration.h
 * @author Logan Gillis
 *
 * Stores unique information about walls.
 */

#ifndef PROJECT1_WALLDECLARATION_H
#define PROJECT1_WALLDECLARATION_H

#include "Declaration.h"

/**
 * Class that describes a wall declaration
 */
class WallDeclaration : public Declaration {
private:
    /// Image for the wall
    std::shared_ptr<wxImage> mImage;

public:
    void XmlLoad(wxXmlNode *node) override;

    std::shared_ptr<Item> GenerateItem(Game* game) override;
};

#endif //PROJECT1_WALLDECLARATION_H

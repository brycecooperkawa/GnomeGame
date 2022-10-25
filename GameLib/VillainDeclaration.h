/**
 * @file VillainDeclaration.h
 * @author Logan Gillis
 *
 * Holds unique info about a villain.
 */

#ifndef PROJECT1_VILLAINDECLARATION_H
#define PROJECT1_VILLAINDECLARATION_H

#include "Declaration.h"


/**
 * Class that describes a villain declaration
 */
class VillainDeclaration : public Declaration {
private:
    std::shared_ptr<wxImage> mImage;

public:
    void XmlLoad(wxXmlNode *node) override;
    std::shared_ptr<Item> GenerateItem(Game* game) override;
};

#endif //PROJECT1_VILLAINDECLARATION_H

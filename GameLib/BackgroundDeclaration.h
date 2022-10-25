/**
 * @file BackgroundDeclaration.h
 * @author Logan Gillis
 *
 * Declaration to hold unique info about a background.
 */

#ifndef PROJECT1_BACKGROUNDDECLARATION_H
#define PROJECT1_BACKGROUNDDECLARATION_H

#include "Declaration.h"

/**
 * Class that holds unique info about a background.
 */
class BackgroundDeclaration : public Declaration {
private:
    /// The underlying item image
    std::shared_ptr<wxImage> mImage;

public:
    void XmlLoad(wxXmlNode *node) override;
    std::shared_ptr<Item> GenerateItem(Game* game) override;
};

#endif //PROJECT1_BACKGROUNDDECLARATION_H

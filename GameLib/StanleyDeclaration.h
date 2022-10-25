/**
 * @file StanleyDeclaration.h
 * @author Austin Stickney
 *
 * Holds unique information for Stanley item.
 */

#ifndef PROJECT1_STANLEYDECLARATION_H
#define PROJECT1_STANLEYDECLARATION_H

#include "Declaration.h"

/**
 * Class that describes a stanley declaration
 */
class StanleyDeclaration : public Declaration {
private:
    std::shared_ptr<wxImage> mImage;

public:
    void XmlLoad(wxXmlNode *node) override;

    std::shared_ptr<Item> GenerateItem(Game* game) override;
};

#endif //PROJECT1_STANLEYDECLARATION_H

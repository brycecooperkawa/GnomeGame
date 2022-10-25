/**
 * @file MoneyDeclaration.h
 * @author Logan Gillis
 *
 * Holds unique info about money.
 */

#ifndef PROJECT1_MONEYDECLARATION_H
#define PROJECT1_MONEYDECLARATION_H

#include "Declaration.h"

/**
 * Class that describes a money declaration
 */
class MoneyDeclaration : public Declaration {
private:
    /// The image
    std::shared_ptr<wxImage> mImage;

    ///Value of the money item
    int mValue = 0;

public:
    void XmlLoad(wxXmlNode *node) override;

    std::shared_ptr<Item> GenerateItem(Game* game) override;
};

#endif //PROJECT1_MONEYDECLARATION_H

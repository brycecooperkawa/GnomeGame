/**
 * @file LoanDeclaration.h
 * @author Bryce Cooperkawa
 *
 * Unique info for loan
 */

#ifndef PROJECT1_LOANDECLARATION_H
#define PROJECT1_LOANDECLARATION_H

#include "Declaration.h"

/**
 * Class that describes a loan declaration
 */
class LoanDeclaration : public Declaration {
private:
    /// The image
    std::shared_ptr<wxImage> mImage;

    /// The value of the loan
    int mValue = 0;

public:
    void XmlLoad(wxXmlNode *node) override;

    std::shared_ptr<Item> GenerateItem(Game* game) override;
};

#endif //PROJECT1_LOANDECLARATION_H

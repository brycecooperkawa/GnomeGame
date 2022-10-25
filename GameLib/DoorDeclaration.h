/**
 * @file DoorDeclaration.h
 * @author Austin Stickney
 */

#ifndef PROJECT1_DOORDECLARATION_H
#define PROJECT1_DOORDECLARATION_H

#include "Declaration.h"

/**
 * Class that describes a door declaration
 */
class DoorDeclaration : public Declaration{
private:
    std::shared_ptr<wxImage> mImage;

public:
    void XmlLoad(wxXmlNode *node) override;
    std::shared_ptr<Item> GenerateItem(Game* game) override;
};

#endif //PROJECT1_DOORDECLARATION_H

/**
 * @file Declaration.h
 * @author Logan Gillis
 *
 * Base class to hold unique information about items.
 */

#ifndef PROJECT1_DECLARATION_H
#define PROJECT1_DECLARATION_H

#include <wx/xml/xml.h>

class Item;
class Game;

/**
 * Base class for any declaration in an XML file.
 */
class Declaration {
private:

public:
    virtual void XmlLoad(wxXmlNode *node) {}
    virtual std::shared_ptr<Item> GenerateItem(Game* game) = 0;
};

#endif //PROJECT1_DECLARATION_H

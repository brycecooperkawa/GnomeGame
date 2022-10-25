/**
 * @file VillainDeclaration.cpp
 * @author Logan Gillis
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "VillainDeclaration.h"
#include "Villain.h"

using namespace std;

/**
 * Loads villain data from XML.
 * @param node XML node to load from.
 */
void VillainDeclaration::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    mImage = make_shared<wxImage>(L"images/" + node->GetAttribute(L"image"), wxBITMAP_TYPE_ANY);
}

/**
 * Generates an instance of villain.
 * @param game The game the item belongs to.
 * @return The new item.
 */
shared_ptr<Item> VillainDeclaration::GenerateItem(Game* game)
{
    return make_shared<Villain>(game, mImage);
}
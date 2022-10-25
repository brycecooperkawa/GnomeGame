/**
 * @file WallDeclaration.cpp
 * @author Logan Gillis
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "WallDeclaration.h"
#include "Wall.h"

using namespace std;

/**
 * Loads wall data from XML.
 * @param node XML node to load from.
 */
void WallDeclaration::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    mImage = make_shared<wxImage>(L"images/" + node->GetAttribute(L"image"), wxBITMAP_TYPE_ANY);
}

/**
 * Generates an instance of wall.
 * @param game The game the item belongs to.
 * @return The new item.
 */
shared_ptr<Item> WallDeclaration::GenerateItem(Game* game)
{
    return make_shared<Wall>(game, mImage);
}
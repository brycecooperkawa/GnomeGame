/**
 * @file DoorDeclaration.cpp
 * @author Austin Stickney
 */

#include "pch.h"
#include "DoorDeclaration.h"
#include "Door.h"

using namespace std;

/**
 * Loads door data from XML.
 * @param node XML node to load from.
 */
void DoorDeclaration::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    mImage = make_shared<wxImage>(L"images/" + node->GetAttribute(L"image"), wxBITMAP_TYPE_ANY);
}

/**
 * Generates an instance of a door.
 * @param game The game the item belongs to.
 * @return The new item.
 */
shared_ptr<Item> DoorDeclaration::GenerateItem(Game* game)
{
    return make_shared<Door>(game, mImage);
}
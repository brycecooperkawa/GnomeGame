/**
 * @file StanleyDeclaration.cpp
 * @author Austin Stickney
 */

#include "pch.h"
#include "StanleyDeclaration.h"
#include "Stanley.h"

using namespace std;

/**
 * Loads Stanley data from XML.
 * @param node XML node to load from.
 */
void StanleyDeclaration::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    mImage = make_shared<wxImage>(L"images/" + node->GetAttribute(L"image"), wxBITMAP_TYPE_ANY);
}

/**
 * Generates an instance of Stanley.
 * @param game The game the item belongs to.
 * @return The new item.
 */
shared_ptr<Item> StanleyDeclaration::GenerateItem(Game* game)
{
    return make_shared<Stanley>(game, mImage);
}
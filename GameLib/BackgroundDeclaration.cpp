/**
 * @file BackgroundDeclaration.cpp
 * @author Logan Gillis
 */

#include "pch.h"
#include "BackgroundDeclaration.h"
#include "Background.h"

using namespace std;

/**
 * Loads background data from XML.
 * @param node XML node to load from.
 */
void BackgroundDeclaration::XmlLoad(wxXmlNode *node)
{
    mImage = make_shared<wxImage>(L"images/" + node->GetAttribute("image"), wxBITMAP_TYPE_ANY);
}

/**
 * Generates an instance of background.
 * @param game The game the background will belong to.
 * @return The new background.
 */
shared_ptr<Item> BackgroundDeclaration::GenerateItem(Game* game)
{
    return make_shared<Background>(game, mImage);
}
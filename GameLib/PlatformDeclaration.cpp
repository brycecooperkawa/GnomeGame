/**
 * @file PlatformDeclaration.cpp
 * @author Logan Gillis
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "PlatformDeclaration.h"
#include "Platform.h"

using namespace std;

/**
 * Loads platform data from XML.
 * @param node XML node to load from.
 */
void PlatformDeclaration::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    mLeftImage = make_shared<wxImage>(L"images/" + node->GetAttribute(L"left-image"), wxBITMAP_TYPE_ANY);
    mMidImage = make_shared<wxImage>(L"images/" + node->GetAttribute(L"mid-image"), wxBITMAP_TYPE_ANY);
    mRightImage = make_shared<wxImage>(L"images/" + node->GetAttribute(L"right-image"), wxBITMAP_TYPE_ANY);
}

/**
 * Generates an instance of platform.
 * @param game The game the item belongs to.
 * @return The new item.
 */
shared_ptr<Item> PlatformDeclaration::GenerateItem(Game* game)
{
    return make_shared<Platform>(game, mLeftImage, mMidImage, mRightImage);
}
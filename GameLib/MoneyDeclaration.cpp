/**
 * @file MoneyDeclaration.cpp
 * @author Logan Gillis
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "MoneyDeclaration.h"
#include "Money.h"

using namespace std;

/**
 * Loads money data from XML.
 * @param node XML node to load from.
 */
void MoneyDeclaration::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    mImage = make_shared<wxImage>(L"images/" + node->GetAttribute(L"image"), wxBITMAP_TYPE_ANY);
    mValue = wxAtoi(node->GetAttribute(L"value"));
}

/**
 * Generates an instance of money.
 * @param game The game the item belongs to.
 * @return The new item.
 */
shared_ptr<Item> MoneyDeclaration::GenerateItem(Game* game)
{
    return make_shared<Money>(game, mImage, mValue);
}
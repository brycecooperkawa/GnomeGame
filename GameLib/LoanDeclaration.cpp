/**
 * @file LoanDeclaration.cpp
 * @author Bryce Cooperkawa
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "LoanDeclaration.h"
#include "Loan.h"

using namespace std;

/**
 * Loads money data from XML.
 * @param node XML node to load from.
 */
void LoanDeclaration::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    mImage = make_shared<wxImage>(L"images/" + node->GetAttribute(L"image"), wxBITMAP_TYPE_ANY);
    mValue = wxAtoi(node->GetAttribute(L"value"));
}

/**
 * Generates an instance of a loan.
 * @param game The game the item belongs to.
 * @return The new item.
 */
shared_ptr<Item> LoanDeclaration::GenerateItem(Game* game)
{
    return make_shared<Loan>(game, mImage, mValue);
}


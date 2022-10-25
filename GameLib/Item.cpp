/**
 * @file Item.cpp
 * @author Austin Stickney
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 * @param game Game this platform is a member of
 */
Item::Item(Game* game, shared_ptr<wxImage> image) : mGame(game)
{
    mItemImage = image;
    mItemBitmap = make_shared<wxBitmap>(*mItemImage);
}

/** Load general postion data of an item
 *
 * @param node The Xml node being loaded from
 */
void Item::XmlLoad(wxXmlNode* node)
{
    // Set item location
    node->GetAttribute(L"x", L"0").ToDouble(&mX);
    node->GetAttribute(L"y", L"0").ToDouble(&mY);
    this->SetLocation(mX,mY);
}

/**
 * Draw this item
 * @param graphics The wxWidgets graphics context on which to draw
 */
void Item::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    int wid = mItemImage->GetWidth();
    int hit = mItemImage->GetHeight();
    graphics->DrawBitmap(graphics->CreateBitmap(*mItemBitmap),
                         (int)GetX() - wid / 2, (int)GetY() - hit / 2,
                         wid + 1, hit);
}
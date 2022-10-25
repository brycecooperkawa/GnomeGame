/**
 * @file Wall.cpp
 * @author Austin Stickney
 */

#include "pch.h"
#include "Wall.h"

using namespace std;

/**
 * Constructor
 * @param game Game object this background belongs to
 */
Wall::Wall(Game* game, shared_ptr<wxImage> image) : Item(game, image)
{
    mItemImage = image;
    mItemBitmap = make_shared<wxBitmap>(*image);
}

/**
 * Load the attributes for a platform node.
 *
 * @param node The Xml node we are loading the platform from
 */
void Wall::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
    node->GetAttribute(L"width", L"0").ToDouble(&mWidth);
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);
}

/**
 * Allows the background to be scrolled
 * @param graphics a pointer to the graphics content
 * @param scrollX the distance to scroll in the x direction
 */
void Wall::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    auto length = mHeight/32;

    while (length >= 1)
    {
        graphics->DrawBitmap(graphics->CreateBitmap(*mItemBitmap),
                (int)GetX() - mWidth / 2, (int)GetY() - mHeight / 2 + 32*(length-1),
                mWidth, 32);
        length -= 1;
    }
}
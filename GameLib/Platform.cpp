/**
 * @file Platform.cpp
 * @author Austin Stickney
 */

#include "pch.h"
#include "Platform.h"
#include "Game.h"
#include <string>
#include <memory>

using namespace std;

/**
 * Constructor
 * @param game Game this platform is a member of
 */
Platform::Platform(Game* game, shared_ptr<wxImage> leftImage, shared_ptr<wxImage> midImage,
        shared_ptr<wxImage> rightImage) : Item(game, midImage)
{
    mLeftImage = leftImage;
    mLeftBitmap = make_shared<wxBitmap>(*mLeftImage);

    mMidImage = midImage;
    mMidBitmap = make_shared<wxBitmap>(*mMidImage);

    mRightImage = rightImage;
    mRightBitmap = make_shared<wxBitmap>(*mRightImage);
}

/**
 * Load the attributes for a platform node.
 *
 * @param node The Xml node we are loading the platform from
 */
void Platform::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
    node->GetAttribute(L"width", L"0").ToDouble(&mWidth);
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);
}


/**
 * Draw a Platform
 * @param graphics The wxWidgets graphics context on which to draw
 */
void Platform::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    auto length = mWidth / 32;
    while (length > 0)
    {
        if (length == mWidth / 32)
        {
            graphics->DrawBitmap(graphics->CreateBitmap(*mRightBitmap),
                    (int)GetX() - mWidth / 2 + 32*(length-1), (int) GetY()-mHeight / 2,
                    32, mHeight);
        }

        if (length > 1 && length < mWidth / 32)
        {
            graphics->DrawBitmap(graphics->CreateBitmap(*mMidBitmap),
                    (int)GetX() - mWidth / 2 + 32*(length-1), (int)GetY() - mHeight / 2,
                    33, mHeight);
        }

        if (length == 1)
        {
            graphics->DrawBitmap(graphics->CreateBitmap(*mLeftBitmap),
                    (int)GetX() - mWidth / 2, (int)GetY() - mHeight / 2,
                    33, mHeight);
        }

        length--;
    }
}



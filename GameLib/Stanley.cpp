/**
 * @file Stanley.cpp
 * @author Austin Stickney
 */

#include "pch.h"
#include "Stanley.h"

using namespace std;

/**
 * Constructor
 * @param game Game object this background belongs to
 */
Stanley::Stanley(Game* game, shared_ptr<wxImage> image) : Item(game, image)
{
    mItemImage = image;
    mItemBitmap = make_shared<wxBitmap>(*mItemImage);
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Stanley::Update(double elapsed)
{
    if (mAnimationTimer > 0)
    {
        Item::SetLocation(Item::GetX(), Item::GetY() + (1000 * elapsed));
        mAnimationTimer -= elapsed;
        mTextSize += mTextSize * elapsed * 2;
    }
}

/**
 * Draw this stanley
 * @param graphics The wxWidgets graphics context on which to draw
 */
void Stanley::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);

    if (mAnimationTimer > 0)
    {
        wxFont font((int)mTextSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, wxColour(0, 125, 0));

        graphics->DrawText("Tuition Increase!", Item::GetX(),
                mCollectedLocation - (Item::GetY() - mCollectedLocation));
    }
}

/**
 * Sets the status of this Stanley to collected
 * so it can't be collected again.
 * @param collected New collected value
 */
void Stanley::SetCollected(bool collected)
{
    mCollected = collected;
    mAnimationTimer = 2;
    mCollectedLocation = Item::GetY();
}

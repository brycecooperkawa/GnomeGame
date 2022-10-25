/**
 * @file Villain.cpp
 * @author Austin Stickney
 */

#include "pch.h"
#include "Villain.h"

using namespace std;

/**
 * Constructor
 * @param game Game object this background belongs to
 */
Villain::Villain(Game* game, shared_ptr<wxImage> image) : Item(game, image)
{
    mItemImage = image;
    mItemBitmap = make_shared<wxBitmap>(*mItemImage);
    mSpeedY = 300/1.25;
    mTopHeight = GetY()+540;
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Villain::Update(double elapsed)
{
    SetLocation(GetX(),
                GetY() - mSpeedY * elapsed);
    if(mSpeedY > 0 && GetY() <= mTopHeight - 10)
    {
        mSpeedY = -mSpeedY;
    }
    if(mSpeedY < 0 && GetY() >= 840)
    {
        mSpeedY = -mSpeedY;
    }
}
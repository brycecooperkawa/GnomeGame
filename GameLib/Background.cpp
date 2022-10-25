/**
 * @file Background.cpp
 * @author Logan Gillis
 * @author Austin Stickney
 */

#include "pch.h"
#include "Background.h"

using namespace std;

/**
 * Constructor
 * @param game Game this platform is a member of
 * @param image The image used to display this platform
 */
Background::Background(Game* game, shared_ptr<wxImage> image) : Item(game, image)
{
    mItemImage = image;
    mItemBitmap = make_shared<wxBitmap>(*image);
}


/**
 * Allows the background to be scrolled
 * @param graphics a pointer to the graphics content
 * @param scrollX the distance to scroll in the x direction
 */
void Background::Draw(shared_ptr<wxGraphicsContext> graphics, int scrollX)
{
    //mItemImage and mItemBitmap in this need to be replaced in order for this to work correctly
    //we need to make a class that stores pictures of the background or find some other way to
    //correctly implement the background because what is currently being done is just me
    //hard coding it in there, need it to scale to the window size and fill the whole thing
    int wid = mItemImage->GetWidth();
    int hit = mItemImage->GetHeight();
    graphics->DrawBitmap(graphics->CreateBitmap(*mItemBitmap),(int)GetX() - wid / 2 + scrollX, (int)GetY() - hit / 2,wid + 1, hit);
}


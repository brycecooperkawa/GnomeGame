/**
 * @file Door.cpp
 * @author Austin Stickney
 * @author Matthew Norris
 */

#include "pch.h"
#include "Door.h"

using namespace std;

/**
 * Constructor
 * @param game Game this platform is a member of
 */
Door::Door(Game* game, shared_ptr<wxImage>& image) : Item(game, image)
{
    mItemImage = image;
    mItemBitmap = make_shared<wxBitmap>(*mItemImage);
}
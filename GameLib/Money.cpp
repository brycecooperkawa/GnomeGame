/**
 * @file Money.cpp
 * @author Logan Gillis
 */

#include "pch.h"
#include "Money.h"

using namespace std;

/**
 * Constructor
 * @param game Game object this money belongs to
 */
Money::Money(Game* game, shared_ptr<wxImage> image, int value) : Item(game, image) {
    mGame = game;
    mImage = image;
    mBitmap = make_shared<wxBitmap>(*mImage);
    mValue = value;
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Money::Update(double elapsed)
{
    if (mAnimationTimer > 0)
    {
        Item::SetLocation(Item::GetX(), Item::GetY() - (1000 * elapsed));
        mAnimationTimer -= elapsed;
    }
}

/**
 * Draw this money
 * @param graphics The wxWidgets graphics context on which to draw
 */
void Money::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);

    if (mAnimationTimer > 0)
    {
        wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, wxColour(0, 0, 0));

        graphics->DrawText("$" + to_string(static_cast<int>(mValue * mGame->GetMultiplier())),
                Item::GetX(), Item::GetY());
    }
}
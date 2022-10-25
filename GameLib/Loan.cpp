/**
 * @file Loan.cpp
 * @author Bryce Cooperkawa
 */

#include "pch.h"
#include "Loan.h"

using namespace std;

/**
 * Constructor
 * @param game Game object this loan belongs to
 */
Loan::Loan(Game* game, shared_ptr<wxImage> image, int value) : Item(game, image) {
    mImage = image;
    mValue = value;
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Loan::Update(double elapsed)
{
    if (mAnimationTimer > 0)
    {
        Item::SetLocation(Item::GetX(), Item::GetY() - (1000 * elapsed));
        mAnimationTimer -= elapsed;
    }
}

/**
 * Draw a loan
 * @param graphics The wxWidgets graphics context on which to draw
 */
void Loan::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);

    if (mAnimationTimer > 0)
    {
        wxFont font(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, wxColour(100, 0, 0));

        graphics->DrawText("$" + to_string(mValue), Item::GetX(), Item::GetY());
    }
}
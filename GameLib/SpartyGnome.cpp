/**
 * @file SpartyGnome.cpp
 * @author Bryce Cooperkawa
 * @author Matthew Norris
 * @author Austin Stickney
 */

#include "pch.h"
#include <string>
#include "SpartyGnome.h"
#include "Game.h"
#include "Vector.h"

using namespace std;

/// Default gnome image (not moving)
const wstring ImageDefault = L"images/gnome.png";

/// Gnome walking right image (step 1)
const wstring ImageRight1 = L"images/gnome-walk-right-1.png";

/// Gnome walking right image (step 2)
const wstring ImageRight2 = L"images/gnome-walk-right-2.png";

/// Gnome walking left image (step 1)
const wstring ImageLeft1 = L"images/gnome-walk-left-1.png";

/// Gnome walking left image (step 2)
const wstring ImageLeft2 = L"images/gnome-walk-left-2.png";

/// Sad gnome (dead)
const wstring ImageDead = L"images/gnome-sad.png";

/// Gravity in virtual pixels per second per second
const double Gravity = 1000.0;

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 500.00;

/// character jump speed in pixels per second
const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;

/**
 * Constructor
 * @param game the game that the gnome is apart of
 */
SpartyGnome::SpartyGnome(Game *game) : Item(game, make_shared<wxImage>(ImageDefault, wxBITMAP_TYPE_ANY))
{
    mGame = game;
    mGnomeImage = make_unique<wxImage>(ImageDefault, wxBITMAP_TYPE_ANY);
    mGnomeBitmap = make_unique<wxBitmap>(*mGnomeImage);
    mV = Vector(0, 0);
}

/**
 * Draw the sparty gnome
 * @param graphics The wxWidgets graphics context on which to draw
 */
void SpartyGnome::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    int wid = mGnomeImage->GetWidth();
    int hit = mGnomeImage->GetHeight();
    graphics->DrawBitmap(graphics->CreateBitmap(*mGnomeBitmap),
            (int)GetX() - wid / 2, (int)GetY() - hit / 2,
            wid + 1, hit);
}

/**
 * Handle updates in time of our gnome
 *
 * This is called before we draw and allows us to
 * move our gnome. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void SpartyGnome::Update(double elapsed)
{
    Vector p = GetP();

    Vector newV(mV.X(), mV.Y() + Gravity * elapsed);

    Vector newP = p + newV * elapsed;

    SetLocation(p.X(), newP.Y());

    mTimer += elapsed;

    auto collided = GetGame()->CollisionTest();
    for (auto item : collided)
    {
        if(newV.Y() > 0)
        {
            newP.SetY(item->GetY() - item->GetHit()/2 - GetHit()/2 - Epsilon);
        }
        else
        {
            newP.SetY(item->GetY() + item->GetHit()/2 + GetHit()/2 + Epsilon);
        }
        newV.SetY(0);
    }

    SetLocation(newP.X(), p.Y());
    collided = GetGame()->CollisionTest();
    for(auto item : collided)
    {
        if(newV.X() > 0)
        {
            newP.SetX(item->GetX() -item->GetWid() / 2 - GetWid() / 2 - Epsilon);
        }
        else
        {
            newP.SetX(item->GetX() + item->GetWid() / 2 + GetWid() / 2 + Epsilon);
        }
        newV.SetX(0);
    }

    mV = newV;
    SetLocation(newP.X(), newP.Y());

    // If the keyboard has been pressed update the items location
    // If the space bar was pressed, the character will jump
    if (mSpace)
    {
        if (mV.Y() == 0)
        {
            mV.SetY(JumpSpeed);
        }
        mSpace = false;
    }

    // If the player has died, display sad gnome image
    if (mGame->hasLost())
    {
        mGnomeImage = make_unique<wxImage>(ImageDead, wxBITMAP_TYPE_ANY);
        mGnomeBitmap = make_unique<wxBitmap>(*mGnomeImage);
    }
    // If the right button was pressed, the character will move right
    else if (mV.X() == HorizontalSpeed)
    {
        //makes the gnome step with its first foot while moving to the right
        if (mRightTimer < 0.25)
        {
            mGnomeImage = make_unique<wxImage>(ImageRight1, wxBITMAP_TYPE_ANY);
            mGnomeBitmap = make_unique<wxBitmap>(*mGnomeImage);
        }
        //makes the gnome step with its second foot after a certain amount of time
        else
        {
            mGnomeImage = make_unique<wxImage>(ImageRight2, wxBITMAP_TYPE_ANY);
            mGnomeBitmap = make_unique<wxBitmap>(*mGnomeImage);
        }

        //resets the timer which makes the gnome step with first foot
        if(mRightTimer>.5)
        {
            mRightTimer = 0;
        }

        //keeps track of how long the gnome has been moving to the right
        mRightTimer += elapsed;
    }
    // If the right button was pressed, the character will move left
    else if (mV.X() == -HorizontalSpeed)
    {
        //makes the gnome step with its first foot while moving to the right
        if (mLeftTimer < 0.25)
        {
            //if being moved to the right the gnome is turned to the right
            mGnomeImage = make_unique<wxImage>(ImageLeft1, wxBITMAP_TYPE_ANY);
            mGnomeBitmap = make_unique<wxBitmap>(*mGnomeImage);
        }
        //makes the gnome step with its second foot after a certain amount of time
        else
        {
            //if being moved to the right the gnome is turned to the right
            mGnomeImage = make_unique<wxImage>(ImageLeft2, wxBITMAP_TYPE_ANY);
            mGnomeBitmap = make_unique<wxBitmap>(*mGnomeImage);
        }

        //resets the timer which makes the gnome step with first foot
        if (mLeftTimer > 0.5)
        {
            mLeftTimer = 0;
        }

        //keeps track of how long the gnome has been moving to the left
        mLeftTimer += elapsed;
    }
    //if nothing is pressed ie the gnome isn't moving then the gnome is faced forward again
    else
    {
        //makes the gnome face front again
        mGnomeImage = make_unique<wxImage>(ImageDefault, wxBITMAP_TYPE_ANY);
        mGnomeBitmap = make_unique<wxBitmap>(*mGnomeImage);
    }
}

/**
 * Function called when gnome is moving right
 * Sets mRight to true
 */
void SpartyGnome::moveRight()
{
    mV.SetX(HorizontalSpeed);
    mRight = true;
}

/**
 * Function called when gnome is moving left
 * Sets mLeft to true
 */
void SpartyGnome::moveLeft()
{
    mV.SetX(-HorizontalSpeed);
    mLeft = true;
}

/**
 * Function called when gnome is jumping
 * Sets mSpace to true
 */
void SpartyGnome::moveJump()
{
    mSpace = true;
}


/**
 * Function called when gnome is done moving right
 * Sets mRight to false
 */
void SpartyGnome::stopMoveRight()
{
    if (mV.X() == HorizontalSpeed)
    {
        mV.SetX(0);
    }
    mRight = false;
}

/**
 * Function called when gnome is done moving left
 * Sets mLeft to false
 */
void SpartyGnome::stopMoveLeft()
{
    if (mV.X() == -HorizontalSpeed)
    {
        mV.SetX(0);
    }
    mLeft = false;
}

/**
 * Resets the gnome
 */
void SpartyGnome::Reset()
{
    //sets all values to 0 so gnome doesn't continue falling when new level is loaded
    mTimer=0;
    mRight=false;
    mLeft=false;
    mSpace=false;
    mV = Vector(0, 0);
    mGnomeImage = make_unique<wxImage>(ImageDefault, wxBITMAP_TYPE_ANY);
    mGnomeBitmap = make_unique<wxBitmap>(*mGnomeImage);
}



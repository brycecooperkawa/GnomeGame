/**
 * @file Game.cpp
 * @author Matthew Norris
 * @author Austin Stickney
 * @author Logan Gillis
 */

#include "pch.h"
#include "Game.h"
#include "Item.h"
#include "SpartyGnome.h"
#include "Scoreboard.h"
#include "CollisionVisitor.h"
#include "Level.h"

using namespace std;

/// Game area height in virtual pixels
const static int Height = 1024;

/**
 * Game Constructor, initializes variables and loads levels
 */
Game::Game()
{
    // Create SpartyGnome and set it for the game
    mGnome = make_shared<SpartyGnome>(this);

    // Create scoreboard and set it for the game
    mScoreboard = make_shared<Scoreboard>(this);

    // Load each level and set current to 1
    mLevels.push_back(make_unique<Level>(this, L"levels/level0.xml", mDeclarations));
    mLevels.push_back(make_unique<Level>(this, L"levels/level1.xml", mDeclarations));
    mLevels.push_back(make_unique<Level>(this, L"levels/level2.xml", mDeclarations));
    mLevels.push_back(make_unique<Level>(this, L"levels/level3.xml", mDeclarations));
    SetLevel(1);
}

/**
 * Draw the game area
 * @param graphics The wxWidgets graphics context on which to draw
 * @param width Width of the client window
 * @param height Height of the client window
 */
void Game::OnDraw(shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    // Automatic Scaling
    mScale = double(height) / double(Height);
    graphics->Scale(mScale, mScale);

    auto virtualWidth = (double)width/mScale;
    graphics->PushState();

    // Compute the amount to scroll in the x-dimension
    auto xOffset = (double)-mGnome->GetX() + virtualWidth / 2.0f;
    graphics->Translate(xOffset, 0);

    // Draws all the items that are currently included in the game
    for (auto& item : mItems)
    {
        item->Draw(graphics);
    }

    graphics->PopState();

    // Draw the scoreboard
    DrawScoreboard(graphics);
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
    if (mPauseTime > 0)
    {
        mPauseTime -= elapsed;
    }
    else
    {
        for (auto item : mItems)
        {
            item->Update(elapsed);
        }
    }

    // Updates the scoreboard with the latest time
    UpdateScoreboard(elapsed);

    if (mStartingLevel && mPauseTime <= 0)
    {
        mStartingLevel = false;
    }

    if (mResetLevel && mPauseTime <= 0)
    {
        SetLevel(mLevel);
    }

    if (mAdvanceLevel && mPauseTime <= 0)
    {
        int level = mLevel;
        if (level != 3) level++;
        SetLevel(level);
    }
}

void Game::OnKeyDown(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
        case WXK_RIGHT:
            // Move the player to the right until key is unpressed
            mGnome->moveRight();
            break;

        case WXK_LEFT:
            // Move player to the left until key is unpressed
            mGnome->moveLeft();
            break;

        case WXK_SPACE:
            // Make the player jump
            mGnome->moveJump();
            break;
    }
}

void Game::OnKeyUp(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
        case WXK_RIGHT:
            mGnome->stopMoveRight();
            break;

        case WXK_LEFT:
            mGnome->stopMoveLeft();
            break;
    }
}

/**
  * Draw the scoreboard of our game
  * @param graphics The wxWidgets graphics context on which to draw
  */
void Game::DrawScoreboard(shared_ptr<wxGraphicsContext> graphics)
{
    mScoreboard->Draw(graphics);
}

/**
  * Update the scoreboard timer of our game
  * @param elapsed The elapsed time of our game window
  */
void Game::UpdateScoreboard(double elapsed)
{
    mScoreboard->Update(elapsed);
}

/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void Game::Accept(ItemVisitor* visitor)
{
    for (auto& item : mItems)
    {
        item->Accept(visitor);
    }
}

/**  Add a tile to the city
* @param tile New tile to add
*/
void Game::Add(shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
  * Update the scoreboard timer of our game
  *
  * @param elapsed The elapsed time of our game window
  */
void Game::SetLevel(int number)
{
    mPauseTime = 3;
    mAdvanceLevel = false;
    mResetLevel = false;
    mStartingLevel = true;
    mLevel = number;
    mScoreboard->SetLevel(number);
    mItems.clear();
    mScoreboard->Clear();
    mLevels[number]->SetAsLevel(mGnome);
}

/**
 * Resets the current level back to its original state.
 */
void Game::RestartLevel()
{
    mResetLevel = true;
    mPauseTime = 3;
}

/**
 * Advances the game to the next level.
 */
void Game::NextLevel()
{
    mAdvanceLevel = true;
    mPauseTime = 3;
}

/**
 * Update the scoreboard score of the game
 * @param score The amount to add
*/
void Game::UpdateScore(double score)
{
    // Updates the scoreboard with the current score (with multiplier)
    mScoreboard->Score(score * mScoreMultiplier);
}

/**
 * Test SpartyGnome is colliding with an item (checks each item)
 * @return Whether or not SpartyGnome is currently colliding with something
 */
set<Item*> Game::CollisionTest()
{
    CollisionVisitor visitor(this, mGnome);
    mCollidingItems.clear();
    for (auto& object : mItems)
    {
        object->Accept(&visitor);
        if (visitor.isColliding())
        {
            auto collidingItem = visitor.GetCollidingItem();
            if (collidingItem == nullptr)
            {
                continue;
            }
            else
            {
                mCollidingItems.insert(collidingItem);
            }
        }
    }
    return mCollidingItems;
}
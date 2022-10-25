/**
 * @file Scoreboard.cpp
 * @author Matthew Norris
 * @author Logan Gillis
 */

#include "pch.h"
#include "Scoreboard.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 * @param game Game this scoreboard is a member of
 */
Scoreboard::Scoreboard(Game *game) : mGame(game) {}

/**
 * Draws the scoreboard of our game
 * @param graphics The graphics context of our game
 */
void Scoreboard::Draw(shared_ptr<wxGraphicsContext>& graphics)
{
    wxFont font(100, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(106, 138, 224));

    string timeString;

    int min = (int)mTimer / 60;         // Calculate whole minutes
    int seconds = (int)mTimer % 60;     // Calculate remaining seconds

    timeString += to_string(min) + ":";

    if (seconds < 10) timeString += "0";
    timeString += to_string(seconds);

    // If the game (level) is starting, display begin message
    if (mGame->isStarting())
    {
        graphics->SetFont(font, wxColour(0, 0, 245));
        graphics->DrawText("Level " + to_string(mLevel) + " Begin", 300, 450);
        graphics->SetFont(font, wxColour(106, 138, 224));
    }

    graphics->DrawText(timeString, 10, 10);
    graphics->DrawText("$" + to_string((int)mScore), 1200, 10);

    // If the game has just been lost, display lose message
    if (mGame->hasLost())
    {
        graphics->SetFont(font, wxColour(0, 0, 245));
        graphics->DrawText("You Lose!", 400, 450);
    }

    // If the game has just been won, display win message
    if (mGame->hasWon())
    {
        graphics->SetFont(font, wxColour(0, 0, 245));
        graphics->DrawText("You win!", 400, 450);
    }
}

/**
 * Updates the scoreboard of our game, adds elapsed time to timer
 * @param elapsed The elapsed time of the game window
 */
void Scoreboard::Update(double elapsed)
{
    if (mGame->GetPauseTime() <= 0) mTimer += elapsed;
}

/**
 * Resets the scoreboard of our game
 */
void Scoreboard::Clear() { mTimer = 0; mScore = 0; }

/**
 * Adds score to the game when the gnome touches money
 * @param MoneyEarned amount to be added
 */
void Scoreboard::Score(double MoneyEarned) { mScore += MoneyEarned; }

/**
 * Sets the level number for the initial game display
 * @param number number of the level we're playing
 */
void Scoreboard::SetLevel(int number) { mLevel = number; }
/**
 * @file Game.h
 * @author Matthew Norris
 * @author Logan Gillis
 */

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include <wx/xml/xml.h>
#include <map>
#include <set>
#include "ItemVisitor.h"
#include "Declaration.h"
#include "Level.h"

class Item;
class SpartyGnome;
class Background;
class Platform;
class Scoreboard;
class Declaration;

/**
 * Class that describes our game and holds all items.
 */
class Game {
private:
    /// The current level index being played
    int mLevel = 1;

    /// All of the items in our game
    std::vector<std::shared_ptr<Item>> mItems;

    /// The levels that can be loaded
    std::vector<std::unique_ptr<Level>> mLevels;

    /// Declarations used for loading
    std::map<std::string, std::shared_ptr<Declaration>> mDeclarations;

    /// Scale of the window
    double mScale = 1;

    /// The player
    std::shared_ptr<SpartyGnome> mGnome;

    /// The scoreboard for displaying score and time
    std::shared_ptr<Scoreboard> mScoreboard;

    bool mStartingLevel = false;

    /// Whether the game should advance to the next level or not
    bool mAdvanceLevel = false;

    /// Whether the game should
    bool mResetLevel = false;

    /// offset for end of game
    double mPauseTime = 0;

    /// Score multiplier for tuition up
    double mScoreMultiplier = 1.0;

    /// Items that are colliding with spartyGnome
    std::set<Item*> mCollidingItems;

public:
    Game();

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    void Update(double elapsed);

    void OnKeyDown(wxKeyEvent& event);

    void OnKeyUp(wxKeyEvent& event);

    void DrawScoreboard(std::shared_ptr<wxGraphicsContext> graphics);

    void Accept(ItemVisitor *visitor);

    void Add(std::shared_ptr<Item> item);

    void SetLevel(int number);

    void RestartLevel();

    void NextLevel();

    void UpdateScore(double score);

    std::set<Item*> CollisionTest();

    /**
     * Gets the current pause time.
     * @return Current pause time
     */
    double GetPauseTime() const { return mPauseTime; }

    /**
     * Adds to the score multiplier.
     * @param value Amount to increase the score multiplier by
     */
    void IncMultiplier(double value) { mScoreMultiplier += value; }

    /**
     * Gets the current score multiplier.
     * @return The current score multiplier.
     */
    double GetMultiplier() { return mScoreMultiplier; }

    void UpdateScoreboard(double elapsed);

    /**
     * Returns whether or not the game is currently
     * in a "win" state.
     * @return Whether or not the level has been won.
     */
    bool hasWon() const { return mAdvanceLevel; }

    /**
     * Returns whether or not the game is currently
     * in a "lose" state.
     * @return Whether or not the level has been lost.
     */
    bool hasLost() const { return mResetLevel; }

    /**
     * Returns whether or not the game is currently
     * starting up.
     * @return Whether or not the level is starting.
     */
    bool isStarting() const { return mStartingLevel; }
};


#endif //PROJECT1_GAME_H

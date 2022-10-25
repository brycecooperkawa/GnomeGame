/**
 * @file Scoreboard.h
 * @author Matthew Norris
 *
 */

#ifndef PROJECT1_SCOREBOARD_H
#define PROJECT1_SCOREBOARD_H

class Game;

/**
 * Class that displays time, score, and other messages
 */
class Scoreboard {
public:
    /// Default constructor (disabled)
    Scoreboard() = delete;

    /// Copy constructor (disabled)
    Scoreboard(const Scoreboard &) = delete;

    /// Assignment operator
    void operator=(const Scoreboard &) = delete;

    Scoreboard(Game *game);

    virtual void Draw(std::shared_ptr<wxGraphicsContext>& graphics);

    void Update(double elapsed);

    void Clear();

    void Score(double MoneyEarned);

    void SetLevel(int number);

private:
    /// Game this scoreboard is a part of
    Game* mGame;

    /// Timer for our game
    double mTimer = 0;

    /// Score for our game
    double mScore = 0;

    /// Level of our game, default is 1
    int mLevel = 1;
};


#endif //PROJECT1_SCOREBOARD_H

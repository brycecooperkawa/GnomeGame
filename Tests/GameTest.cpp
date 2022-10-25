/**
 * @file GameTest.cpp
 * @author Matthew Norris
 * @author Austin Stickney
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <SpartyGnome.h>
#include <Villain.h>
#include <Wall.h>
#include <Background.h>


using namespace std;

/// Background filename
const wstring backgroundImage = L"images/backgroundForest.png";

/// Wall filename
const std::wstring Wall1ImageName = L"images/wall1.png";

/// Villain filename
const std::wstring UofMImageName = L"images/UofM.png";

/** Mock class for testing Walls */
class WallMock : public Wall {
public:
    WallMock(Game *game) : Wall(game, Wall1ImageName) {}
};

/** Mock class for testing Backgrounds */
class BackgroundMock : public Background {
public:
    BackgroundMock(Game *game) : Background(game, backgroundImage) {}
};

/** Mock class for testing Villains */
class VillainMock : public Villain {
public:
    VillainMock(Game *game) : Villain(game, UofMImageName) {}
};

class TestVisitor : public ItemVisitor
{
public:

    virtual void VisitGnome(SpartyGnome* gnome) override { mNumGnome++; }

    virtual void VisitBackground(Background* background) override { mNumBackground++; }

    virtual void VisitWall(Wall* wall) override { mNumWall++; }

    virtual void VisitVillain(Villain* villain) override { mNumVillain++; }

    virtual void VisitPlatform(Platform* platform) override { mNumPlatform++; }


    int mNumGnome = 0;
    int mNumWall = 0;
    int mNumBackground = 0;
    int mNumVillain = 0;
    int mNumPlatform = 0;
};

TEST(GameTest, Construct) {
    Game game;
}

TEST(GameTest, Visitor)
{
    // Construct a city object
    Game game;

    // Test visit functions of all our other items
    auto item4 = make_shared<WallMock>(&game);
    auto item5 = make_shared<SpartyGnome>(&game);
    auto item6 = make_shared<BackgroundMock>(&game);
    auto item7 = make_shared<VillainMock>(&game);

    // Add all items
    game.Add(item4);
    game.Add(item5);
    game.Add(item6);
    game.Add(item7);

    // Ensure visit for all other items working
    TestVisitor visitor2;
    game.Accept(&visitor2);
    ASSERT_EQ(1, visitor2.mNumGnome) <<
                                          L"Visitor number of Gnomes";
    ASSERT_EQ(1, visitor2.mNumWall) <<
                                     L"Visitor number of Walls";
    ASSERT_EQ(1, visitor2.mNumBackground) <<
                                    L"Visitor number of Backgrounds";
    ASSERT_EQ(1, visitor2.mNumVillain) <<
                                          L"Visitor number of Villains";
}

TEST(GameTest, Load)
{
    Game game;

}
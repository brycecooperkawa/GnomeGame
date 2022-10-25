/**
 * @file WallTest.cpp
 * @author Austin Stickney
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Wall.h>
#include <Game.h>

using namespace std;

/// Wall filenames
const std::wstring Wall1ImageName = L"images/wall1.png";
const std::wstring Wall2ImageName = L"images/wall2.png";

/** Mock class for testing Walls */
class WallMock : public Wall {
public:
    WallMock(Game *game) : Wall(game, Wall1ImageName) {}
};

TEST(WallTest, Construct) {
    Game game;
    WallMock wall(&game);
}

TEST(WallTest, GettersSetters){
    Game game;
    WallMock wall(&game);

    // Test initial values
    ASSERT_NEAR(0, wall.GetX(), 0.0001);
    ASSERT_NEAR(0, wall.GetY(), 0.0001);

    // Test SetLocation, GetX, and GetY
    wall.SetLocation(50, 75);
    ASSERT_NEAR(50, wall.GetX(), 0.0001);
    ASSERT_NEAR(75, wall.GetY(), 0.0001);

    // Test a second with different values
    wall.SetLocation(-25, -100);
    ASSERT_NEAR(-25, wall.GetX(), 0.0001);
    ASSERT_NEAR(-100, wall.GetY(), 0.0001);

    // Test a second with mixed values
    wall.SetLocation(-250, 125);
    ASSERT_NEAR(-250, wall.GetX(), 0.0001);
    ASSERT_NEAR(125, wall.GetY(), 0.0001);
}
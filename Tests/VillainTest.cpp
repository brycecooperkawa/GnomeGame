/**
 * @file VillainTest.cpp
 * @author Austin Stickney
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Villain.h>
#include <Game.h>

using namespace std;

/// Wall filenames
const std::wstring UofMImageName = L"images/UofM.png";
const std::wstring WiscImageName = L"images/wisc.png";

/** Mock class for testing Walls */
class VillainMock : public Villain {
public:
    VillainMock(Game *game) : Villain(game, UofMImageName) {}
};

TEST(VillainTest, Construct) {
    Game game;
    VillainMock villain(&game);
}

TEST(VillainTest, GettersSetters){
    Game game;
    VillainMock villain(&game);

    // Test initial values
    ASSERT_NEAR(0, villain.GetX(), 0.0001);
    ASSERT_NEAR(0, villain.GetY(), 0.0001);

    // Test SetLocation, GetX, and GetY
    villain.SetLocation(50, 75);
    ASSERT_NEAR(50, villain.GetX(), 0.0001);
    ASSERT_NEAR(75, villain.GetY(), 0.0001);

    // Test a second with different values
    villain.SetLocation(-25, -100);
    ASSERT_NEAR(-25, villain.GetX(), 0.0001);
    ASSERT_NEAR(-100, villain.GetY(), 0.0001);

    // Test a second with mixed values
    villain.SetLocation(-250, 125);
    ASSERT_NEAR(-250, villain.GetX(), 0.0001);
    ASSERT_NEAR(125, villain.GetY(), 0.0001);
}
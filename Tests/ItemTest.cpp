/**
 * @file ItemTest.cpp
 * @author Austin Stickney
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>

/// Gnome filename
const std::wstring SpartyImageName = L"images/gnome.png";

/** Mock class for testing the class Item */
class ItemMock : public Item {
public:
    ItemMock(Game *game) : Item(game, SpartyImageName) {}

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * */
    virtual void Accept(ItemVisitor* visitor) override { }
};

TEST(ItemTest, Construct) {
    Game game;
    ItemMock item(&game);
}

TEST(ItemTest, GettersSetters){
    Game game;
    ItemMock item(&game);

    // Test initial values
    ASSERT_NEAR(0, item.GetX(), 0.0001);
    ASSERT_NEAR(0, item.GetY(), 0.0001);

    // Test SetLocation, GetX, and GetY
    item.SetLocation(10.5, 17.2);
    ASSERT_NEAR(10.5, item.GetX(), 0.0001);
    ASSERT_NEAR(17.2, item.GetY(), 0.0001);

    // Test a second with with different values
    item.SetLocation(-72, -107);
    ASSERT_NEAR(-72, item.GetX(), 0.0001);
    ASSERT_NEAR(-107, item.GetY(), 0.0001);
}
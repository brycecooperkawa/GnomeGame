/**
 * @file CollisionVisitor.h
 * @author John Foss
 *
 * Visitor for testing collision between SpartyGnome and other items.
 */

#ifndef PROJECT1_COLLISIONVISITOR_H
#define PROJECT1_COLLISIONVISITOR_H

#include <vector>
#include <memory>
#include "ItemVisitor.h"
#include "Item.h"
#include "Platform.h"
#include "Villain.h"
#include "Background.h"
#include "Wall.h"
#include "Stanley.h"
#include "Door.h"
#include "Money.h"
#include "Loan.h"

/**
 * Class that visits items to check for collision
 */
class CollisionVisitor : public ItemVisitor {
private:
    /// The main game that stores all data
    Game* mGame;

    /// The player
    std::shared_ptr<SpartyGnome> mGnome;

    /// Whether or not the player is colliding with something
    bool mIsColliding = false;

    /// Vector of colliding items
    Item* mCollidingItem = nullptr;

public:
    CollisionVisitor(Game* game, std::shared_ptr<SpartyGnome> gnome) { mGame = game; mGnome = gnome;}

    Item* GetCollidingItem() { return mCollidingItem;}

    bool isColliding() const { return mIsColliding;}

    /**
     * Visit a general item. Used for platforms and walls.
     * @param item Item we are visiting
     */
    void VisitItem(Item *item);

    /**
    * Visit a Platform object
    * @param platform Platform we are visiting
    */
    void VisitPlatform(Platform* platform) override
    {
        VisitItem(platform);
    }

    /**
    * Visit a Wall object
    * @param wall Wall we are visiting
    */
    void VisitWall(Wall* wall)  override
    {
        VisitItem(wall);
    }

    /**
     * Visit a Villain object
     * @param villain Villain we are visiting
     */
    void VisitVillain(Villain* villain) override;

    /**
     * Visit a money object
     * @param money Money we are visiting
     */
    void VisitMoney(Money* money) override;

    /**
     * Visit a door object
     * @param door Door we are visiting
     */
    void VisitDoor(Door* door) override;

    /**
     * Visit a loan object
     * @param loan Loan we are visiting
     */
    void VisitLoan(Loan* loan) override;

    /**
     * Visit a stanley object
     * @param stanley Stanley we are visiting
     */
    void VisitStanley(Stanley* stanley) override;

    /**
     * Visit a background object
     * @param background Background we are visiting
     */
    void VisitBackground(Background* background) override;
};

#endif //PROJECT1_COLLISIONVISITOR_H

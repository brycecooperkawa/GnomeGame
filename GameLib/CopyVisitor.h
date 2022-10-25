/**
 * @file CopyVisitor.h
 * @author Logan Gillis
 *
 * Visitor for copying items from a level to Game.
 */

#ifndef PROJECT1_COPYVISITOR_H
#define PROJECT1_COPYVISITOR_H

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
 * Class that visits items for copying items from
 * a level to a game.
 */
class CopyVisitor : public ItemVisitor {
private:
    Game* mGame;

public:
    CopyVisitor(Game* game)
    {
        mGame = game;
    }

    ~CopyVisitor() {}

    /**
    * Visit a PlatformGrass object
    * @param grass grass we are visiting
    */
    void VisitPlatform(Platform* platform) override
    {
        Platform newPlatform = *platform;
        mGame->Add(std::make_shared<Platform>(newPlatform));
    }

    /**
    * Visit a Villain object
    * @param villain villain we are visiting
    */
    void VisitVillain(Villain* villain) override
    {
        Villain newVillain = *villain;
        mGame->Add(std::make_shared<Villain>(newVillain));
    }

    /**
    * Visit a Background object
    * @param background background we are visiting
    */
    void VisitBackground(Background* background) override
    {
        Background newBackground = *background;
        mGame->Add(std::make_shared<Background>(newBackground));
    }

    /**
    * Visit a Wall object
    * @param wall wall we are visiting
    */
    void VisitWall(Wall* wall) override
    {
        Wall newWall = *wall;
        mGame->Add(std::make_shared<Wall>(newWall));
    }

    /**
    * Visit a Stanley object
    * @param stanley Stanley we are visiting
    */
    void VisitStanley(Stanley* stanley) override
    {
        Stanley newStanley = *stanley;
        mGame->Add(std::make_shared<Stanley>(newStanley));
    }

    /**
    * Visit a door object
    * @param door Door we are visiting
    */
    void VisitDoor(Door* door) override
    {
        Door newDoor = *door;
        mGame->Add(std::make_shared<Door>(newDoor));
    }

    /**
     * Visit a money object
     * @param money Money we are visiting
     */
    void VisitMoney(Money* money) override
    {
        Money newMoney = *money;
        mGame->Add(std::make_shared<Money>(newMoney));
    }

    /**
     * Visit a loan object
     * @param loan Money we are visiting
     */
    void VisitLoan(Loan* loan) override
    {
        Loan newLoan = *loan;
        mGame->Add(std::make_shared<Loan>(newLoan));
    }
};

#endif //PROJECT1_COPYVISITOR_H

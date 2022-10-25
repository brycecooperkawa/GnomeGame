/**
 * @file ItemVisitor.h
 * @author Matthew Norris
 * @author Austin Stickney
 *
 * Item visitor base class.
 */

#ifndef PROJECT1_ITEMVISITOR_H
#define PROJECT1_ITEMVISITOR_H

class Platform;
class SpartyGnome;
class Villain;
class Background;
class Wall;
class Stanley;
class Door;
class Money;
class Loan;

/**
 * Class that visits all objects derived from item in the game
 */
class ItemVisitor {
public:
    virtual ~ItemVisitor() {}

    /**
    * Visit a PlatformGrass object
    * @param grass Grass we are visiting
    */
    virtual void VisitPlatform(Platform* platform) {}

    /**
    * Visit a Villain object
    * @param villain Villain we are visiting
    */
    virtual void VisitVillain(Villain* villain) {}

    /**
    * Visit a SpartyGnome object
    * @param gnome SpartyGnome we are visiting
    */
    virtual void VisitGnome(SpartyGnome* gnome) {}

    /**
    * Visit a Background object
    * @param background Background we are visiting
    */
    virtual void VisitBackground(Background* background) {}

    /**
    * Visit a Wall object
    * @param wall Wall we are visiting
    */
    virtual void VisitWall(Wall* wall) {}

    /**
    * Visit a Stanley object
    * @param stanley Stanley we are visiting
    */
    virtual void VisitStanley(Stanley* stanley) {}

    /**
    * Visit a door object
    * @param door Door we are visiting
    */
    virtual void VisitDoor(Door* door) {}

    /**
     * Visit a money object
     * @param money Money we are visiting
     */
    virtual void VisitMoney(Money* money) {}

    /**
     * Visit a loan object
     * @param loan Loan we are visiting
     */
    virtual void VisitLoan(Loan* loan) {}
};

#endif //PROJECT1_ITEMVISITOR_H

/**
 * @file CollisionVisitor.cpp
 * @author John Foss
 */

#include "pch.h"
#include "CollisionVisitor.h"

void CollisionVisitor::VisitItem(Item *item)
{
    auto itemLeft = item->GetX() - item->GetWid() / 2;
    auto itemRight = item->GetX() + item->GetWid() / 2;
    auto itemTop = item->GetY() - item->GetHit() / 2;
    auto itemBottom = item->GetY() + item->GetHit() / 2;


    auto ourLeft = mGnome->GetX() - mGnome->GetWid() / 2;
    auto ourRight = mGnome->GetX() + mGnome->GetWid() / 2;
    auto ourTop = mGnome->GetY() - mGnome->GetHit() / 2;
    auto ourBottom = mGnome->GetY() + mGnome->GetHit() / 2;

    // Test for all the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight < itemLeft ||  // Completely to the left
            ourLeft > itemRight ||  // Completely to the right
            ourTop > itemBottom ||  // Completely below
            ourBottom < itemTop)    // Completely above
    {
        mIsColliding = false;
    }
    else
    {
        mIsColliding = true;
        mCollidingItem = item;
    }
}


void CollisionVisitor::VisitVillain(Villain* villain)
{
    auto itemLeft = villain->GetX() - villain->GetWid() / 2;
    auto itemRight = villain->GetX() + villain->GetWid() / 2;
    auto itemTop = villain->GetY() - villain->GetHit() / 2;
    auto itemBottom = villain->GetY() + villain->GetHit() / 2;


    auto ourLeft = mGnome->GetX() - mGnome->GetWid() / 2;
    auto ourRight = mGnome->GetX() + mGnome->GetWid() / 2;
    auto ourTop = mGnome->GetY() - mGnome->GetHit() / 2;
    auto ourBottom = mGnome->GetY() + mGnome->GetHit() / 2;

    // Test for all the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight > itemLeft &&  // Completely to the left
            ourLeft < itemRight &&  // Completely to the right
            ourTop < itemBottom &&  // Completely below
            ourBottom > itemTop)    // Completely above
    {
        mGame->RestartLevel();
    }
}

void CollisionVisitor::VisitMoney(Money* money)
{
    if (money->GetCollected()) return;

    auto itemLeft = money->GetX() - money->GetWid() / 2;
    auto itemRight = money->GetX() + money->GetWid() / 2;
    auto itemTop = money->GetY() - money->GetHit() / 2;
    auto itemBottom = money->GetY() + money->GetHit() / 2;


    auto ourLeft = mGnome->GetX() - mGnome->GetWid() / 2;
    auto ourRight = mGnome->GetX() + mGnome->GetWid() / 2;
    auto ourTop = mGnome->GetY() - mGnome->GetHit() / 2;
    auto ourBottom = mGnome->GetY() + mGnome->GetHit() / 2;

    // Test for all the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight > itemLeft &&  // Completely to the left
            ourLeft < itemRight &&  // Completely to the right
            ourTop < itemBottom &&  // Completely below
            ourBottom > itemTop)    // Completely above
    {
        money->SetCollected(true);
        mGame->UpdateScore(static_cast<double>(money->GetValue()));
    }
}

void CollisionVisitor::VisitDoor(Door* door)
{
    if (door->GetUsed()) return;

    auto itemLeft = door->GetX() - door->GetWid() / 2;
    auto itemRight = door->GetX() + door->GetWid() / 2;
    auto itemTop = door->GetY() - door->GetHit() / 2;
    auto itemBottom = door->GetY() + door->GetHit() / 2;


    auto ourLeft = mGnome->GetX() - mGnome->GetWid() / 2;
    auto ourRight = mGnome->GetX() + mGnome->GetWid() / 2;
    auto ourTop = mGnome->GetY() - mGnome->GetHit() / 2;
    auto ourBottom = mGnome->GetY() + mGnome->GetHit() / 2;

    // Test for all the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight > itemLeft &&  // Completely to the left
            ourLeft < itemRight &&  // Completely to the right
            ourTop < itemBottom &&  // Completely below
            ourBottom > itemTop)    // Completely above
    {
        door->SetUsed(true);
        mGame->NextLevel();
    }
}

void CollisionVisitor::VisitLoan(Loan* loan)
{
    if (loan->GetCollected()) return;

    auto itemLeft = loan->GetX() - loan->GetWid() / 2;
    auto itemRight = loan->GetX() + loan->GetWid() / 2;
    auto itemTop = loan->GetY() - loan->GetHit() / 2;
    auto itemBottom = loan->GetY() + loan->GetHit() / 2;


    auto ourLeft = mGnome->GetX() - mGnome->GetWid() / 2;
    auto ourRight = mGnome->GetX() + mGnome->GetWid() / 2;
    auto ourTop = mGnome->GetY() - mGnome->GetHit() / 2;
    auto ourBottom = mGnome->GetY() + mGnome->GetHit() / 2;

    // Test for all the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight > itemLeft &&  // Completely to the left
            ourLeft < itemRight &&  // Completely to the right
            ourTop < itemBottom &&  // Completely below
            ourBottom > itemTop)    // Completely above
    {
        loan->SetCollected(true);
        mGame->UpdateScore(static_cast<double>(loan->GetValue()));
    }
}

void CollisionVisitor::VisitStanley(Stanley* stanley)
{
    if (stanley->GetCollected()) return;

    auto itemLeft = stanley->GetX() - stanley->GetWid() / 2;
    auto itemRight = stanley->GetX() + stanley->GetWid() / 2;
    auto itemTop = stanley->GetY() - stanley->GetHit() / 2;
    auto itemBottom = stanley->GetY() + stanley->GetHit() / 2;


    auto ourLeft = mGnome->GetX() - mGnome->GetWid() / 2;
    auto ourRight = mGnome->GetX() + mGnome->GetWid() / 2;
    auto ourTop = mGnome->GetY() - mGnome->GetHit() / 2;
    auto ourBottom = mGnome->GetY() + mGnome->GetHit() / 2;

    // Test for all the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight > itemLeft &&  // Completely to the left
            ourLeft < itemRight &&  // Completely to the right
            ourTop < itemBottom &&  // Completely below
            ourBottom > itemTop)    // Completely above
    {
        stanley->SetCollected(true);
        mGame->IncMultiplier(0.1);
    }
}

void CollisionVisitor::VisitBackground(Background* background)
{
    auto ourTop = mGnome->GetY() - mGnome->GetHit() / 2;

    if (ourTop > background->GetHit())
    {
        mGame->RestartLevel();
    }
}

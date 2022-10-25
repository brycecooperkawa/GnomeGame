/**
 * @file Level.cpp
 * @author Logan Gillis
 * @author Austin Stickney
 */

#include "pch.h"
#include <wx/xml/xml.h>
#include "Level.h"
#include "Game.h"
#include "BackgroundDeclaration.h"
#include "PlatformDeclaration.h"
#include "WallDeclaration.h"
#include "MoneyDeclaration.h"
#include "VillainDeclaration.h"
#include "StanleyDeclaration.h"
#include "DoorDeclaration.h"
#include "CopyVisitor.h"
#include "SpartyGnome.h"
#include "LoanDeclaration.h"

using namespace std;

/**
 * Constructor
 * @param filename Filename for the level being loaded
 */
Level::Level(Game* game, const wxString &filename, map<string, shared_ptr<Declaration>>& declarations)
{
    mGame = game;
    Load(filename, declarations);
}

/**
 * Load/generate a level from an XML file.
 * @param filename The filename of the file to load the level info from.
 */
void Level::Load(const wxString& filename, map<string, shared_ptr<Declaration>>& declarations)
{
    mItems.clear();

    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Level");
        return;
    }

    auto root = xmlDoc.GetRoot();

    // Load in level dimensions and initial player location
    root->GetAttribute(L"start-y", L"0").ToDouble(&mStartY);
    root->GetAttribute(L"start-x", L"0").ToDouble(&mStartX);


    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if (name == L"declarations")
        {
            XmlDeclaration(child, declarations);
        }
        else if (name == L"items")
        {
            XmlItem(child, declarations);
        }
    }
}

/**
 * Load a declaration from an XML node.
 * @param node XML node to load data from.
 */
void Level::XmlDeclaration(wxXmlNode *node, map<string, shared_ptr<Declaration>>& declarations)
{
    auto branch = node->GetChildren();
    for( ; branch; branch=branch->GetNext())
    {
        shared_ptr<Declaration> declaration = nullptr;
        string id(branch->GetAttribute(L"id"));

        // If declaration already exists, skip to the next one
        if (declarations.count(id)) continue;

        auto name = branch->GetName();

        if (name == "background")
        {
            declaration = make_shared<BackgroundDeclaration>();
        }
        else if (name == "platform")
        {
            declaration = make_shared<PlatformDeclaration>();
        }
        else if (name == "wall")
        {
            declaration = make_shared<WallDeclaration>();
        }
        else if (name == "money")
        {
            declaration = make_shared<MoneyDeclaration>();
        }
        else if (name == "villain")
        {
            declaration = make_shared<VillainDeclaration>();
        }
        else if (name == "tuition-up")
        {
            declaration = make_shared<StanleyDeclaration>();
        }
        else if (name == "door")
        {
            declaration = make_shared<DoorDeclaration>();
        }
        else if (name == "loan")
        {
            declaration = make_shared<LoanDeclaration>();
        }

        if (declaration != nullptr)
        {
            declaration->XmlLoad(branch);
            declarations[id] = declaration;
        }
    }
}

/**
 * Load an item from XML.
 * @param node XML node to load data from.
 */
void Level::XmlItem(wxXmlNode* node, map<string, shared_ptr<Declaration>>& declarations)
{
    auto branch = node->GetChildren();
    for( ; branch; branch=branch->GetNext())
    {
        shared_ptr<Item> item;
        string id(branch->GetAttribute(L"id"));

        if (declarations.count(id))
        {
            item = declarations[id]->GenerateItem(mGame);
        }

        if (item != nullptr)
        {
            mItems.push_back(item);
            item->XmlLoad(branch);
        }
    }
}

/**
 * Load the information of this level into game
 * @param gnome The SpartyGnome of the game
 */
void Level::SetAsLevel(shared_ptr<SpartyGnome> gnome)
{
    CopyVisitor visitor(mGame);
    for (auto item : mItems)
    {
        item->Accept(&visitor);
    }
    gnome->SetLocation(mStartX, mStartY);
    mGame->Add(gnome);

    // Set SpartyGnome attributes back to originals
    gnome->Reset();
}
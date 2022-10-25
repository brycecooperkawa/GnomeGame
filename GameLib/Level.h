/**
 * @file Level.h
 * @author Logan Gillis
 * @author Austin Stickney
 *
 * Level class that holds items for levels.
 */

#ifndef PROJECT1_LEVEL_H
#define PROJECT1_LEVEL_H

#include <map>
#include "Item.h"
#include "Declaration.h"
#include "SpartyGnome.h"

/**
 * Class that holds default item values.
 */
class Level {
private:
    /// Game this level belongs to
    Game* mGame;

    /// All items to be displayed in the level
    std::vector<std::shared_ptr<Item>> mItems;

    /// Initial X-position for the player
    double mStartX = 0;
    /// Initial Y-position for the player
    double mStartY = 0;

public:
    void Load(const wxString &filename, std::map<std::string, std::shared_ptr<Declaration>>& declarations);

    int GetX() const {return mStartX;}

    Level(Game* game, const wxString& filename, std::map<std::string, std::shared_ptr<Declaration>>& declarations);

    void XmlDeclaration(wxXmlNode *node, std::map<std::string, std::shared_ptr<Declaration>>& declarations);

    void XmlItem(wxXmlNode *node, std::map<std::string, std::shared_ptr<Declaration>>& declarations);

    void SetAsLevel(std::shared_ptr<SpartyGnome> gnome);
};

#endif //PROJECT1_LEVEL_H

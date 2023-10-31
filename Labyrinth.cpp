#include "Labyrinth.h"
using namespace std;

string checkForMagicItems(MazeCell *start)
{
    if (start == nullptr)
    {
        return "Nothing";
    }

    switch (start->whatsHere)
    {
    case Item::SPELLBOOK:
        return "Spellbook";
    case Item::POTION:
        return "Potion";
    case Item::WAND:
        return "Wand";
    default:
        return "Nothing";
    }
}
void makeMove(MazeCell *&start, const char move)
{
    switch (move)
    {
    case 'S':
        start = start->south;
        break;
    case 'E':
        start = start->east;
        break;
    case 'W':
        start = start->west;
        break;
    case 'N':
        start = start->north;
        break;
    default:
        break;
    }
}
bool isPathToFreedom(MazeCell *start, const string &moves)
{
    // conds
    bool allFound = false;
    bool potionFound = false;
    bool spellBookFound = false;
    bool wandFound = false;

    string temp = checkForMagicItems(start);
    // can not use switch statement because it is a string
    if (temp == "Potion")
        potionFound = true;
    if (temp == "Spellbook")
        spellBookFound = true;
    if (temp == "Wand")
        wandFound = true;
    for (int i = 0; i < moves.size(); ++i)
    {
        // error checking moves
        if (moves.at(i) != 'S' && moves.at(i) != 'N' && moves.at(i) != 'E' && moves.at(i) != 'W')
            return false;

        // moving pointer
        makeMove(start, moves.at(i));

        // check if pointer is null
        if (start == nullptr)
            return false;

        // setting item flags
        string temp = checkForMagicItems(start);
        if (temp == "Potion")
            potionFound = true;
        if (temp == "Spellbook")
            spellBookFound = true;
        if (temp == "Wand")
            wandFound = true;

        // return true if all flags were found
        if (spellBookFound == true && wandFound == true && potionFound == true && i == moves.size() - 1)
        {
            allFound = true;
            return true;
        }

        // return false if not all conditions were met
        if (i == moves.size() - 1 && allFound == false)
            return false;
    }
}

#include "Labyrinth.h"
#include "set.h"
using namespace std;

bool isPathToFreedom(MazeCell* start, const string& moves) {
    Set<Item> magicalItems;

    for (int i = 0; i < moves.size(); i++) {
        if (start->whatsHere != Item::NOTHING) {
            magicalItems.add(start->whatsHere);
        }

        if (moves[i] == 'E') {
            if (start->east != nullptr)
                start = start->east;
            else
                return false;
        }
        else if (moves[i] == 'N') {
            if (start->north != nullptr)
                start = start->north;
            else
                return false;
        }
        else if (moves[i] == 'S') {
            if (start->south != nullptr)
                start = start->south;
            else
                return false;
        }
        else if (moves[i] == 'W') {
            if (start->west != nullptr)
                start = start->west;
            else
                return false;
        }
    }
    if (start->whatsHere != Item::NOTHING) {
        magicalItems.add(start->whatsHere);
    }
    return magicalItems.size() == 3;
}
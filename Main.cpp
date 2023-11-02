#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>
#include <fstream>

/* Change this constant to contain your name.
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const std::string kYourName = "Eason";

/* Change these constants to contain the paths out of your mazes. */
const std::string kPathOutOfTwistyMaze = "";
std::ofstream outfile("log.txt", std::ios::app);
MazeCell *twistyStartLocation = twistyMazeFor(kYourName);
void generateCombinations(const std::string &characters, int length, std::string current = "")
{
    if (length == 0)
    {
        if (isPathToFreedom(twistyStartLocation, current))
        {
            outfile << "C" << current << std::endl;
        }
        else
        {
            outfile << "I" << current << std::endl;
        }
        return;
    }

    for (char c : characters)
    {
        generateCombinations(characters, length - 1, current + c);
    }
}
int main()
{
    generateCombinations("NSEW", 6, "");
    return 0;
}

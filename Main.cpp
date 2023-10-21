#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>
#include <fstream>

const std::string kYourName = "Om and Eason";
std::ofstream outfile("log.txt", std::ios::app);
MazeCell *startLocation = mazeFor(kYourName);

void generateCombinations(const std::string &characters, int length, std::string current = "")
{
    if (length == 0)
    {
        if (isPathToFreedom(startLocation, current))
        {
            outfile << "C" <<current << std::endl;
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
    generateCombinations("NSEW", 13, "");
    return 0;
}
// outfile << "This text will be appended to the file." << std::endl;

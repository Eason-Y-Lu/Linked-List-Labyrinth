#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>
#include <fstream>

const std::string kYourName = "Om and Eason";
std::ofstream outfile("log.txt", std::ios::app);

void generateCombinations(const std::string &characters, int length, std::string current = "")
{
    MazeCell *startLocation = mazeFor(kYourName);
    if (length == 0)
    {
        if (isPathToFreedom(startLocation, current))
        {
            outfile << "Correct" <<current << std::endl;
        }
        else
        {
            outfile << "Incorrect" << current << std::endl;
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
    generateCombinations("NSEW", 12, "");
    return 0;
}
// outfile << "This text will be appended to the file." << std::endl;
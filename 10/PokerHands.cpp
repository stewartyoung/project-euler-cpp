#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream infile("poker.txt");
    std::vector<std::string> lines;
    std::vector<std::string> player1;
    std::vector<std::string> player2;
    for (std::string line; std::getline(infile, line);)
    {
        lines.push_back(line);
        // std::cout << "Player 1: " << line.substr(0, 14) << "\n";
        // std::cout << "Player 2: " << line.substr(15) << "\n";
    }

    for (std::vector<std::string>::const_iterator i = lines.begin(); i != lines.end(); ++i)
    {
        std::cout << *i << '\n';
        std::string line = *i;
        player1.push_back(line.substr(0, 14));
        player2.push_back(line.substr(15));
    }
    return 0;
}
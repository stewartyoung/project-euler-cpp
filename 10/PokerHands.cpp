#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

struct Player
{
    int playerWins;
    vector<string> playerHands;
    map<char, int> cardValueCounts;
    map<char, int> cardSuitsCounts;
} Alice, Bob;

int main()
{
    ifstream infile("poker.txt");
    vector<string> lines;
    vector<string> player1;
    vector<string> player2;

    // populate lines vector
    for (string line; getline(infile, line);)
    {
        lines.push_back(line);
    }

    // populate player hands vector
    for (vector<string>::const_iterator i = lines.begin(); i != lines.end(); ++i)
    {
        cout << *i << '\n';
        string line = *i;
        player1.push_back(line.substr(0, 14));
        player2.push_back(line.substr(15));
    }

    // "parse" the hand
    // std::map of cards to worth e.g. {'2':2, ..., 'A': 14}
    // std::map of card values to count in players hand
    // std::map of suits to their counts

    // calculate "value" of the hand

    // declare winner

    return 0;
}
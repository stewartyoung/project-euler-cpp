#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

struct Player
{
    int player_wins;
    vector<string> player_hands;
    map<char, int> card_value_counts;
    map<char, int> card_suits_counts;
} Alice, Bob;

void populate_hands(string input_game, Player &player1, Player &player2)
{
    ifstream infile(input_game);
    vector<string> lines;

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
        player1.player_hands.push_back(line.substr(0, 14));
        player2.player_hands.push_back(line.substr(15));
    }
}

int main()
{
    populate_hands(string("poker.txt"), Alice, Bob);

    // "parse" the hand
    // std::map of cards to worth e.g. {'2':2, ..., 'A': 14}
    // std::map of card values to count in players hand
    // std::map of suits to their counts

    // calculate "value" of the hand

    // declare winner

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <typeinfo>
using namespace std;

struct Player
{
    int player_wins;
    vector<string> player_hands;
    unordered_map<string, int> card_value_counts;
    unordered_map<string, int> card_suits_counts;
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
        cout << *i << "\n";
        string line = *i;
        player1.player_hands.push_back(line.substr(0, 14));
        player2.player_hands.push_back(line.substr(15));
    }
}

void count_value(Player &player)
{
    // for hand in total hand history
    for (vector<string>::const_iterator i = player.player_hands.begin(); i != player.player_hands.end(); ++i)
    {
        player.card_value_counts["2"] = 0;
        player.card_value_counts["3"] = 0;
        player.card_value_counts["4"] = 0;
        player.card_value_counts["5"] = 0;
        player.card_value_counts["6"] = 0;
        player.card_value_counts["7"] = 0;
        player.card_value_counts["8"] = 0;
        player.card_value_counts["9"] = 0;
        player.card_value_counts["10"] = 0;
        player.card_value_counts["J"] = 0;
        player.card_value_counts["Q"] = 0;
        player.card_value_counts["K"] = 0;
        player.card_value_counts["A"] = 0;
        // card value is 0th, 3rd, 6th, 9th, 12th character on the line
        player.card_value_counts[string(1, i[0][0])]++;
        player.card_value_counts[string(1, i[0][3])]++;
        player.card_value_counts[string(1, i[0][6])]++;
        player.card_value_counts[string(1, i[0][9])]++;
        player.card_value_counts[string(1, i[0][12])]++;
    }
}

int main()
{
    populate_hands(string("poker.txt"), Alice, Bob);
    for (vector<string>::const_iterator i = Alice.player_hands.begin(); i != Alice.player_hands.end(); ++i)
    {
        cout << *i << "\n";
    }

    // "parse" the hand
    // std::map of cards to worth e.g. {"2":2, ..., "A": 14}

    // std::map of card values to count in players hand
    count_value(Alice);
    // std::map of suits to their counts

    // calculate "value" of the hand

    // declare winner

    return 0;
}
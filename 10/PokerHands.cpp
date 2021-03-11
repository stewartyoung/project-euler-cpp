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

void populate_hands(string input_game, Player &player1, Player &player2, bool verbose = false)
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
        if (verbose)
        {
            cout << *i << "\n";
        }
        string line = *i;
        player1.player_hands.push_back(line.substr(0, 14));
        player2.player_hands.push_back(line.substr(15));
    }
}

void count_value(Player &player, bool verbose = false)
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
        player.card_value_counts["T"] = 0;
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
        if (verbose)
        {
            cout << *i << "\n";
            for (auto &it : player.card_value_counts)
            {
                cout << it.first << ":" << it.second << " ";
            }
            cout << endl;
        }
    }
}

void count_suits(Player &player, bool verbose = false)
{
    // for hand in total hand history
    for (vector<string>::const_iterator i = player.player_hands.begin(); i != player.player_hands.end(); ++i)
    {
        player.card_suits_counts["C"] = 0;
        player.card_suits_counts["D"] = 0;
        player.card_suits_counts["H"] = 0;
        player.card_suits_counts["S"] = 0;
        // suits are the 1st, 4th, 7th, 10th, 13th characters on the line
        player.card_suits_counts[string(1, i[0][1])]++;
        player.card_suits_counts[string(1, i[0][4])]++;
        player.card_suits_counts[string(1, i[0][7])]++;
        player.card_suits_counts[string(1, i[0][10])]++;
        player.card_suits_counts[string(1, i[0][13])]++;
        if (verbose)
        {
            cout << *i << "\n";
            for (auto &it : player.card_suits_counts)
            {
                cout << it.first << ":" << it.second;
            }
            cout << endl;
        }
    }
}

int main()
{
    // read in the hands
    populate_hands(string("poker.txt"), Alice, Bob);

    // "parse" the hand
    // std::unordered_map of card values to count in players hand
    count_value(Alice);
    count_value(Bob);
    // std::unordered_map of suits to their counts
    count_suits(Alice);
    count_suits(Bob);

    // calculate "value" of the hand

    // high card: all value_counts < 2
    bool high_card = true;
    for (auto &it : Alice.card_value_counts)
    {
        if (it.second >= 2)
        {
            high_card = false;
            cout << "not a high card\n";
            break;
        }
    }

    // one pair: only one value_counts == 2, all others <= 1

    // two pair: two value_counts == 2

    // three of a kind: only one value_counts == 3, all others <=1

    // flush: a suit_counts == 5

    // full house: one value_counts == 3, one value_counts == 2

    // four of a kind: one value_counts == 4

    // straight flush: all cards are consecutive values and suit_count == 5

    // royal flush: T, J, Q, K, A and suit_count == 5

    // declare winner

    return 0;
}
#pragma once
#include "Constants.h"

#include <string>
#include <vector>
#include <random>
#include <unordered_map>



using namespace std;
static mt19937 mt(01234567);

typedef unordered_map<unsigned long long int, short> evalTable;
typedef unordered_map<unsigned long long int, bool> checkTable;

class Hash {
public:

    unsigned long long int ZobristTable[Constants::BOARD_SIZE][Constants::BOARD_SIZE][3];
    evalTable evalTable;
    checkTable checkTable;
    unsigned long long int randomInt()
    {
        uniform_int_distribution<unsigned long long int>
            dist(0, UINT64_MAX);
        return dist(mt);
    }

    // Initializes the table
    void initTable()
    {
        for (int i = 0; i < Constants::BOARD_SIZE; i++)
            for (int j = 0; j < Constants::BOARD_SIZE; j++)
                for (int k = 0; k < 3; k++)
                    ZobristTable[i][j][k] = randomInt();
    }

    // Computes the hash value of a given board
    unsigned long long int computeHash(const vector<vector<short>>& board)
    {
        unsigned long long int h = 0;
        for (int i = 0; i < Constants::BOARD_SIZE; i++)
        {
            for (int j = 0; j < Constants::BOARD_SIZE; j++)
            {
                if (board[i][j] != 0)
                {
                    int piece = board[i][j];
                    h ^= ZobristTable[i][j][piece];
                }
            }
        }
        return h;
    }

};



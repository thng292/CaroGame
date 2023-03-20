#pragma once
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

#include "Constants.h"

typedef unsigned long long int Ulli;
typedef std::unordered_map<Ulli, short> evalTable;
typedef std::unordered_map<Ulli, bool> checkTable;

using std::vector;

static std::mt19937 mt(01234567);

class Hash {
   public:
    Ulli ZobristTable[Constants::BOARD_SIZE][Constants::BOARD_SIZE][3];
    evalTable evalTable;
    checkTable checkTable;

    inline Ulli randomInt() {
        std::uniform_int_distribution<Ulli> dist(0, UINT64_MAX);
        return dist(mt);
    }

    // Initializes the table
    void initTable();

    // Computes the hash value of a given board
    Ulli computeHash(const vector<vector<short>>& board);
};

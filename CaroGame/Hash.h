#pragma once
#include <array>
#include <random>
#include <unordered_map>
#include <vector>

#include "Constants.h"
#include "GameAction.h"

typedef unsigned long long int Ulli;

using std::vector;

const size_t HASH_TABLE_SIZE = 8192;

class Hash {
    static std::mt19937 mt;
    Ulli ZobristTable[Constants::BOARD_SIZE][Constants::BOARD_SIZE][3];
    std::array<std::pair<Ulli, short>, HASH_TABLE_SIZE>
        hashTable;

    // Initializes the table
    inline constexpr void initTable()
    {
        for (int i = 0; i < Constants::BOARD_SIZE; i++) {
            for (int j = 0; j < Constants::BOARD_SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    ZobristTable[i][j][k] = randomInt();
                }
            }
        }
    }

   public:
    Hash()
    {
        initTable();
        hashTable.fill({0, 0});
    }

    inline bool checkHashExist(Ulli hash)
    {
        return hashTable[hash % HASH_TABLE_SIZE].first == hash;
    };

    inline short getValue(Ulli hash)
    {
        return hashTable[hash % HASH_TABLE_SIZE].second;
    }

    inline void setValue(Ulli hash, short value)
    {
        hashTable[hash % HASH_TABLE_SIZE] = {hash, value};
    }

    inline Ulli randomInt()
    {
        std::uniform_int_distribution<Ulli> dist(0, UINT64_MAX);
        return dist(mt);
    }

    // Computes the hash value of a given board
    Ulli computeHash(const GameAction::Board& board);
};

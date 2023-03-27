//#pragma once
//#include <random>
//#include <unordered_map>
//#include <vector>
//
//#include "Constants.h"
//
//typedef unsigned long long int Ulli;
//typedef std::unordered_map<Ulli, short> evalTable;
//typedef std::unordered_map<Ulli, bool> checkTable;
//
//using std::vector;
//
//class Hash {
//    static std::mt19937 mt;
//    Ulli ZobristTable[Constants::BOARD_SIZE][Constants::BOARD_SIZE][3];
//
//    // Initializes the table
//    inline constexpr void initTable()
//    {
//        for (int i = 0; i < Constants::BOARD_SIZE; i++) {
//            for (int j = 0; j < Constants::BOARD_SIZE; j++) {
//                for (int k = 0; k < 3; k++) {
//                    ZobristTable[i][j][k] = randomInt();
//                }
//            }
//        }
//    }
//
//   public:
//    evalTable evalTable;
//    checkTable checkTable;
//
//    Hash() { initTable(); }
//
//    inline Ulli randomInt()
//    {
//        std::uniform_int_distribution<Ulli> dist(0, UINT64_MAX);
//        return dist(mt);
//    }
//
//    // Computes the hash value of a given board
//    Ulli computeHash(const vector<vector<short>>& board);
//};

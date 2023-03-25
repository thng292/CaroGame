#include "Hash.h"

// Initializes the table

std::mt19937 Hash::mt = std::mt19937(01234567);

// Computes the hash value of a given board
Ulli Hash::computeHash(const GameAction::Board& board)
{
    Ulli h = 0;
    for (int i = 0; i < Constants::BOARD_SIZE; i++) {
        for (int j = 0; j < Constants::BOARD_SIZE; j++) {
            if (board[i][j] != 0) {
                h ^= ZobristTable[i][j][board[i][j]];
            }
        }
    }
    return h;
}

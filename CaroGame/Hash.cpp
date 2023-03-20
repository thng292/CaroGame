#include "Hash.h"

// Initializes the table

void Hash::initTable() {
    for (int i = 0; i < Constants::BOARD_SIZE; i++)
        for (int j = 0; j < Constants::BOARD_SIZE; j++)
            for (int k = 0; k < 3; k++) ZobristTable[i][j][k] = randomInt();
}

// Computes the hash value of a given board
unsigned long long int Hash::computeHash(
    const vector<vector<short>>& board
) {
    unsigned long long int h = 0;
    for (int i = 0; i < Constants::BOARD_SIZE; i++) {
        for (int j = 0; j < Constants::BOARD_SIZE; j++) {
            if (board[i][j] != 0) {
                int piece = board[i][j];
                h ^= ZobristTable[i][j][piece];
            }
        }
    }
    return h;
}

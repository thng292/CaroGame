#include "Evaluation.h"

#include <vector>

#include "Constants.h"
#include "Logic.h"

// Don't change this please it'll break everything
const short score[4] = {1, 10, 50, 200};

short GetHorizontalComboEval(
    const GameAction::Board& board,
    GameAction::Board& comboCheckBoard,
    const GameAction::Point& move,
    const short playerValue
)
{
    short colLast = move.col;
    for (short col = move.col + 1; col < Constants::BOARD_SIZE; ++col) {
        if (board[move.row][col] == playerValue) {
            comboCheckBoard[move.row][col] /= 2;
            colLast = col;
        } else
            break;
    }

    short evalValue = score[(colLast - move.col)];

    bool blockLeft = false, blockRight = false;
    if (move.col == 0)
        blockLeft = true;
    else if (board[move.row][move.col - 1] != 0 && board[move.row][move.col - 1] != playerValue)
        blockLeft = true;
    if (colLast == Constants::BOARD_SIZE - 1)
        blockRight = true;
    else if (board[move.row][colLast + 1] != 0 && board[move.row][colLast + 1] != playerValue)
        blockRight = true;
    if (blockLeft && blockRight)
        evalValue = 0;
    else if (blockLeft || blockRight)
        evalValue /= 2;

    if (evalValue == score[3]) evalValue = score[3] * Evaluation::tempBoost;

    return evalValue;
}

short GetVerticalComboEval(
    const GameAction::Board& board,
    GameAction::Board& comboCheckBoard,
    const GameAction::Point& move,
    const short playerValue
)
{
    short rowLast = move.row;
    for (short row = move.row + 1; row < Constants::BOARD_SIZE; ++row) {
        if (board[row][move.col] == playerValue) {
            comboCheckBoard[row][move.col] /= 3;
            rowLast = row;
        } else
            break;
    }

    short evalValue = score[(rowLast - move.row)];

    bool blockLeft = false, blockRight = false;
    if (move.row == 0)
        blockLeft = true;
    else if (board[move.row - 1][move.col] != 0 && board[move.row - 1][move.col] != playerValue)
        blockLeft = true;
    if (rowLast == Constants::BOARD_SIZE - 1)
        blockRight = true;
    else if (board[rowLast + 1][move.col] != 0 && board[rowLast + 1][move.col] != playerValue)
        blockRight = true;
    if (blockLeft && blockRight)
        evalValue = 0;
    else if (blockLeft || blockRight)
        evalValue /= 2;

    if (evalValue == score[3]) evalValue = score[3] * Evaluation::tempBoost;

    return evalValue;
}

short GetDiagonalRightComboEval(
    const GameAction::Board& board,
    GameAction::Board& comboCheckBoard,
    const GameAction::Point& move,
    const short playerValue
)
{
    short rowLast = move.row, colLast = move.col;

    for (short row = move.row + 1, col = move.col + 1;
         row < Constants::BOARD_SIZE && col < Constants::BOARD_SIZE;
         ++row, ++col) {
        if (board[row][col] == playerValue) {
            comboCheckBoard[row][col] /= 5;
            rowLast = row;
            colLast = col;
        } else
            break;
    }

    short evalValue = score[rowLast - move.row];

    bool blockLeft = false, blockRight = false;
    if (move.row == 0 || move.col == 0)
        blockLeft = true;
    else if (board[move.row - 1][move.col - 1] != 0 && board[move.row - 1][move.col - 1] != playerValue)
        blockLeft = true;

    if (rowLast == Constants::BOARD_SIZE - 1 ||
        colLast == Constants::BOARD_SIZE - 1)
        blockRight = true;
    else if (board[rowLast + 1][colLast + 1] != 0 && board[rowLast + 1][colLast + 1] != playerValue)
        blockRight = true;

    if (blockLeft && blockRight)
        evalValue = 0;
    else if (blockLeft || blockRight)
        evalValue /= 2;

    if (evalValue == score[3]) evalValue = score[3] * Evaluation::tempBoost;

    return evalValue;
}

short GetDiagonalLeftComboEval(
    const GameAction::Board& board,
    GameAction::Board& comboCheckBoard,
    const GameAction::Point& move,
    const short playerValue
)
{
    short rowLast = move.row, colLast = move.col;

    for (short row = move.row + 1, col = move.col - 1;
         row < Constants::BOARD_SIZE && col >= 0;
         ++row, --col) {
        if (board[row][col] == playerValue) {
            comboCheckBoard[row][col] /= 7;
            rowLast = row;
            colLast = col;
        } else
            break;
    }

    short evalValue = score[rowLast - move.row];

    bool blockLeft = false, blockRight = false;
    if (move.row == 0 || move.col == Constants::BOARD_SIZE - 1)
        blockLeft = true;
    else if (board[move.row - 1][move.col + 1] != 0 && board[move.row - 1][move.col + 1] != playerValue)
        blockLeft = true;

    if (rowLast == Constants::BOARD_SIZE - 1 || colLast == 0)
        blockRight = true;
    else if (board[rowLast + 1][colLast - 1] != 0 && board[rowLast + 1][colLast - 1] != playerValue)
        blockRight = true;

    if (blockLeft && blockRight)
        evalValue = 0;
    else if (blockLeft || blockRight)
        evalValue /= 2;

    if (evalValue == score[3]) evalValue = score[3] * Evaluation::tempBoost;

    return evalValue;
}

short Evaluation::GetComboEval(
    const GameAction::Board& board, const short& playerValue
)
{
    GameAction::Board comboCheckBoard(
        Constants::BOARD_SIZE, std::vector<short>(Constants::BOARD_SIZE, 210)
    );

    short evalResult = 0;
    for (short row = 0; row < Constants::BOARD_SIZE; ++row) {
        for (short col = 0; col < Constants::BOARD_SIZE; ++col) {
            if (board[row][col]) {
                short evalValue = 0;
                if (comboCheckBoard[row][col] % 2 == 0) {
                    short eval = GetHorizontalComboEval(
                        board, comboCheckBoard, {row, col}, board[row][col]
                    );
                    if (eval == score[3] && board[row][col] != playerValue)
                        eval = score[3] * tempBoost;
                    else if (eval == score[3] * tempBoost && board[row][col] != playerValue)
                        eval = score[3] * tempBoost * 8;
                    evalValue += eval;
                }
                if (comboCheckBoard[row][col] % 3 == 0) {
                    short eval = GetVerticalComboEval(
                        board, comboCheckBoard, {row, col}, board[row][col]
                    );
                    if (eval == score[3] && board[row][col] != playerValue)
                        eval = score[3] * tempBoost;
                    else if (eval == score[3] * tempBoost && board[row][col] != playerValue)
                        eval = score[3] * tempBoost * 8;
                    evalValue += eval;
                }
                if (comboCheckBoard[row][col] % 5 == 0) {
                    short eval = GetDiagonalRightComboEval(
                        board, comboCheckBoard, {row, col}, board[row][col]
                    );
                    if (eval == score[3] && board[row][col] != playerValue)
                        eval = score[3] * tempBoost;
                    else if (eval == score[3] * tempBoost && board[row][col] != playerValue)
                        eval = score[3] * tempBoost * 8;
                    evalValue += eval;
                }
                if (comboCheckBoard[row][col] % 7 == 0) {
                    short eval = GetDiagonalLeftComboEval(
                        board, comboCheckBoard, {row, col}, board[row][col]
                    );
                    if (eval == score[3] && board[row][col] != playerValue)
                        eval = score[3] * tempBoost;
                    else if (eval == score[3] * tempBoost && board[row][col] != playerValue)
                        eval = score[3] * tempBoost * 8;

                    evalValue += eval;
                }

                if (board[row][col] == playerValue)
                    evalResult += evalValue;
                else
                    evalResult -= evalValue;
            }
        }
    }
    return evalResult;
}

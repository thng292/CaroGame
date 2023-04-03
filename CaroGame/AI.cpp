#include "AI.h"

short AI::Eval(
    const GameAction::Board& board,
    const short& moveCount,
    const GameAction::Point& lastMove,
    bool isMaximizingPlayer
)
{
    short playerValue = (isMaximizingPlayer) ? PLAYER_AI : PLAYER_HUMAN;
    short totalEval = 0;

    totalEval += Evaluation::GetComboEval(board, playerValue);
    return (isMaximizingPlayer) ? totalEval : -totalEval;
}

GameAction::Point AI::GetBestMove(GameAction::Board& board, short& moveCount)
{
    short rowLowerLimit = (_topLeftPoint.row - FIRST_LOOKUP_RANGE >= 0)
                              ? _topLeftPoint.row - FIRST_LOOKUP_RANGE
                              : 0;
    short rowUpperLimit =
        (_bottomRightPoint.row + FIRST_LOOKUP_RANGE < Constants::BOARD_SIZE)
            ? _bottomRightPoint.row + FIRST_LOOKUP_RANGE
            : Constants::BOARD_SIZE - 1;
    short colLowerLimit = (_topLeftPoint.col - FIRST_LOOKUP_RANGE >= 0)
                              ? _topLeftPoint.col - FIRST_LOOKUP_RANGE
                              : 0;
    short colUpperLimit =
        (_bottomRightPoint.col + FIRST_LOOKUP_RANGE < Constants::BOARD_SIZE)
            ? _bottomRightPoint.col + FIRST_LOOKUP_RANGE
            : Constants::BOARD_SIZE - 1;

    short valBest = -INF;
    short alpha = -INF, beta = INF;
    GameAction::Point moveBest;


    for (short row = rowLowerLimit; row <= rowUpperLimit; ++row) {
        for (short col = colLowerLimit; col <= colUpperLimit; ++col) {
            if (board[row][col] == 0) {
                moveBest = {row, col};
                break;
            }
        }
    }

    srand(time(NULL));

    for (short row = rowLowerLimit; row <= rowUpperLimit; ++row) {
        for (short col = colLowerLimit; col <= colUpperLimit; ++col) {
            if (board[row][col] == 0) {
                short valCur;
                GameAction::Point move = {row, col};
                GameAction::MakeMove(board, moveCount, move, PLAYER_AI);
                valCur = MiniMax(
                    board,
                    moveCount,
                    move,
                    alpha,
                    beta,
                    false,
                    _DEPTH - 1
                );

                if (valCur > valBest) {
                    valBest = valCur;
                    moveBest = move;
                } else if (valCur == valBest) {
                    if (rand() % 2) {
                        moveBest = move;
                    }
                }

                GameAction::UndoMove(board, moveCount, move);

                alpha = (valCur > alpha) ? valCur : alpha;
                if (beta < alpha) break;
            }
        }
    }

    return moveBest;
}



short AI::MiniMax(
    GameAction::Board& board,
    short& moveCount,
    const GameAction::Point& lastMove,
    short alpha,
    short beta,
    const bool& isMaximizingPlayer,
    const short& depth
)

{

    const short playerValue = (!isMaximizingPlayer) ? PLAYER_AI : PLAYER_HUMAN;

    short state = Logic::GetGameState(board, moveCount, lastMove, playerValue);
    if (state != Logic::NULL_VALUE) {
        const short evalValue = (playerValue == PLAYER_HUMAN)
                                    ? -MAX_SCORE * state
                                    : MAX_SCORE * state;
        return evalValue;
    }

    if (depth == 0) {
        const short evalValue =
            Eval(board, moveCount, lastMove, !isMaximizingPlayer);
        return evalValue;
    }

    short rowLowerLimit = (lastMove.row - _range >= 0)
                              ? lastMove.row - _range
                              : 0;
    short rowUpperLimit =
        (lastMove.row + _range < Constants::BOARD_SIZE)
            ? lastMove.row + _range
            : Constants::BOARD_SIZE - 1;
    short colLowerLimit = (lastMove.col - _range >= 0)
                              ? lastMove.col - _range
                              : 0;
    short colUpperLimit =
        (lastMove.col + _range < Constants::BOARD_SIZE)
            ? lastMove.col + _range
            : Constants::BOARD_SIZE - 1;


    if (isMaximizingPlayer) {
        short valBest = -INF;
        for (short row = rowLowerLimit; row < rowUpperLimit; ++row) {
            for (short col = colLowerLimit; col < colUpperLimit; ++col) {
                if (board[row][col] == 0) {
                    GameAction::MakeMove(
                        board, moveCount, {row, col}, PLAYER_AI
                    );
                    short valCur = MiniMax(
                        board,
                        moveCount,
                        {row, col},
                        alpha,
                        beta,
                        false,
                        depth - 1
                    );
                    valBest = (valCur > valBest) ? valCur : valBest;
                    GameAction::UndoMove(board, moveCount, {row, col});

                    alpha = (valCur > alpha) ? valCur : alpha;
                    if (beta < alpha) break;
                }
            }
        }
        return valBest;
    } else {
        short valBest = INF;
        for (short row = rowLowerLimit; row < rowUpperLimit; ++row) {
            for (short col = colLowerLimit; col < colUpperLimit; ++col) {
                if (board[row][col] == 0) {
                    GameAction::MakeMove(
                        board, moveCount, {row, col}, PLAYER_HUMAN
                    );
                    short valCur = MiniMax(
                        board,
                        moveCount,
                        {row, col},
                        alpha,
                        beta,
                        true,
                        depth - 1
                    );
                    valBest = (valCur < valBest) ? valCur : valBest;
                    GameAction::UndoMove(board, moveCount, {row, col});

                    beta = (valCur < beta) ? valCur : beta;
                    if (beta < alpha) break;
                }
            }
        }
        return valBest;
    }
}
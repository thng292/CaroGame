#include "AI.h"

#include "View.h"

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

    MoveQueue moveQueue = GetMoveList(
        rowLowerLimit,
        rowUpperLimit,
        colLowerLimit,
        colUpperLimit,
        moveCount,
        board,
        true
    );

    for (short row = rowLowerLimit; row <= rowUpperLimit; ++row) {
        for (short col = colLowerLimit; col <= colUpperLimit; ++col) {
            if (board[row][col] == 0) {
                moveBest = {row, col};
                break;
            }
        }
    }

    srand(time(NULL));
    
    Hash hash;

    while (!moveQueue.empty()) {
        PointEval node = moveQueue.top();
        GameAction::Point move = node.move;
        GameAction::MakeMove(board, moveCount, move, PLAYER_AI);
        if (Logic::GetGameState(board, moveCount, move, PLAYER_AI) ==
            Logic::WIN_VALUE) {
            return move;
        }
        short valCur;
        Ulli hashKey = hash.computeHash(board);
        if (hash.checkTable[hashKey]) {
            valCur = hash.evalTable[hashKey];
        } else {
            valCur = MiniMax(
                board,
                moveCount,
                move,
                alpha,
                beta,
                false,
                _DEPTH - 1,
                _topLeftPoint,
                _bottomRightPoint,
                hash
            );
            hash.checkTable[hashKey] = 1;
            hash.evalTable[hashKey] = valCur;
        }

     

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

        moveQueue.pop();
    }

    cnt;

    return moveBest;
}

short AI::MiniMax(
    GameAction::Board& board,
    short& moveCount,
    const GameAction::Point& lastMove,
    short alpha,
    short beta,
    const bool& isMaximizingPlayer,
    const short& depth,
    const GameAction::Point topLeftPoint,
    const GameAction::Point bottomRightPoint,
    Hash &hash
)

{
    cnt++;

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

      short rowLowerLimit = (topLeftPoint.row - FIRST_LOOKUP_RANGE >= 0)
                              ? topLeftPoint.row - FIRST_LOOKUP_RANGE
                              : 0;
    short rowUpperLimit =
        (bottomRightPoint.row + FIRST_LOOKUP_RANGE < Constants::BOARD_SIZE)
            ? bottomRightPoint.row + FIRST_LOOKUP_RANGE
            : Constants::BOARD_SIZE - 1;
    short colLowerLimit = (topLeftPoint.col - FIRST_LOOKUP_RANGE >= 0)
                              ? topLeftPoint.col - FIRST_LOOKUP_RANGE
                              : 0;
    short colUpperLimit =
        (bottomRightPoint.col + FIRST_LOOKUP_RANGE < Constants::BOARD_SIZE)
            ? bottomRightPoint.col + FIRST_LOOKUP_RANGE
            : Constants::BOARD_SIZE - 1;

    MoveQueue moveQueue = GetMoveList(
        rowLowerLimit,
        rowUpperLimit,
        colLowerLimit,
        colUpperLimit,
        moveCount,
        board,
        isMaximizingPlayer
    );

    if (isMaximizingPlayer) {
        short valBest = -INF;
        while (!moveQueue.empty()) {
            GameAction::Point move = moveQueue.top().move;
            GameAction::MakeMove(board, moveCount, move, PLAYER_AI);

            short valCur;
            Ulli hashKey = hash.computeHash(board);
            if (hash.checkTable[hashKey]) {
                valCur = hash.evalTable[hashKey];
            } else {
                valCur = MiniMax(
                    board,
                    moveCount,
                    move,
                    alpha,
                    beta,
                    false,
                    depth - 1,
                    NewTopLeftPoint({rowLowerLimit, colLowerLimit}, move),
                    NewBottomRightPoint({rowUpperLimit, colUpperLimit}, move),
                    hash
                );
                hash.checkTable[hashKey] = 1;
                hash.evalTable[hashKey] = valCur;
            }

            valBest = (valCur > valBest) ? valCur : valBest;
            GameAction::UndoMove(board, moveCount, move);

            alpha = (valCur > alpha) ? valCur : alpha;
            if (beta < alpha) break;
            moveQueue.pop();
        }
        return valBest;
    } else {
        short valBest = INF;
        while (!moveQueue.empty()) {
            GameAction::Point move = moveQueue.top().move;
            GameAction::MakeMove(board, moveCount, move, PLAYER_HUMAN);
            short valCur;
            Ulli hashKey = hash.computeHash(board);
            if (hash.checkTable[hashKey]) {
                valCur = hash.evalTable[hashKey];
            } else {
                valCur = MiniMax(
                    board,
                    moveCount,
                    move,
                    alpha,
                    beta,
                    true,
                    depth - 1,
                    NewTopLeftPoint({rowLowerLimit, colLowerLimit}, move),
                    NewBottomRightPoint({rowUpperLimit, colUpperLimit}, move),
                    hash
                );
                hash.checkTable[hashKey] = 1;
                hash.evalTable[hashKey] = valCur;
            }
            

            valBest = (valCur < valBest) ? valCur : valBest;
            GameAction::UndoMove(board, moveCount, move);

            beta = (valCur < beta) ? valCur : beta;
            if (beta < alpha) break;
            moveQueue.pop();
        }
        return valBest;
    }
}
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>


#include "AI.h"
#include "Constants.h"
#include "Logic.h"
#include "Evaluation.h"

#include <random>

using namespace std;

GameAction::Point AI::GetFirstMove() {
	srand(time(NULL));
	short row = Constants::BOARD_SIZE / 2 - 2 + (rand() % 3);
	short col = Constants::BOARD_SIZE / 2 - 2 + (rand() % 3);
	return { row, col };
}


short AI::Eval(
	const GameAction::Board& board,
	const short& moveCount,
	const GameAction::Point& lastMove,
	bool isMaximizingPlayer) {

	short playerValue = (isMaximizingPlayer) ? PLAYER_AI : PLAYER_HUMAN;
	short totalEval = 0;

	totalEval += Evaluation::GetComboEval(board, playerValue);
	return (isMaximizingPlayer) ? totalEval : -totalEval;
}

bool isValidPoint(short row, short col) {
	return !(row < 0 || col < 0 || row >= Constants::BOARD_SIZE || col >= Constants::BOARD_SIZE);
}

bool IsGoodMove(const GameAction::Board& board, const GameAction::Point& move, const short& playerValue) {
	for (short row = move.row - 1; row <= move.row + 1; ++row) {
		for (short col = move.col - 1; col <= move.col + 1; ++col) {
			if (isValidPoint(row, col)) {
				if (board[row][col] != 0) return 1;
			}
		}
	}

	return 0;

}

GameAction::Point AI::GetBestMove(
	GameAction::Board& board,
	short& moveCount) {


	short rowLowerLimit = (_topLeftPoint.row - FIRST_LOOKUP_RANGE >= 0) ? _topLeftPoint.row - FIRST_LOOKUP_RANGE : 0;
	short rowUpperLimit = (_bottomRightPoint.row + FIRST_LOOKUP_RANGE < Constants::BOARD_SIZE) ? _bottomRightPoint.row + FIRST_LOOKUP_RANGE : Constants::BOARD_SIZE - 1;
	short colLowerLimit = (_topLeftPoint.col - FIRST_LOOKUP_RANGE >= 0) ? _topLeftPoint.col - FIRST_LOOKUP_RANGE : 0;
	short colUpperLimit = (_bottomRightPoint.col + FIRST_LOOKUP_RANGE < Constants::BOARD_SIZE) ? _bottomRightPoint.col + FIRST_LOOKUP_RANGE : Constants::BOARD_SIZE - 1;

	short valBest = -INF;
	short alpha = -INF, beta = INF;
	GameAction::Point moveBest;


	short searchSize = (rowUpperLimit - rowLowerLimit + 1) * (colUpperLimit - colLowerLimit + 1);

	short moveListSize = searchSize - moveCount;
	std::vector<GameAction::Point>moveList;
	moveList.resize(moveListSize);
	short right = 0, left = moveListSize - 1;


	for (short row = rowLowerLimit; row <= rowUpperLimit; ++row) {
		for (short col = colLowerLimit; col <= colUpperLimit; ++col) {
			if (board[row][col] == 0) {
				moveBest = { row, col };
				if (IsGoodMove(board, { row, col }, PLAYER_AI)) moveList[right++] = { row, col };
				else moveList[left--] = { row, col };


			}
		}
	}

	srand(time(NULL));

	for (size_t i = 0; i < moveListSize; ++i) {
		short valCur;
		GameAction::MakeMove(board, moveCount, moveList[i], PLAYER_AI);
		unsigned long long int hashKey = hash.computeHash(board);
		if (hash.checkTable[hashKey]) valCur = hash.evalTable[hashKey];
		else {
			valCur = MiniMax(board, moveCount, moveList[i], alpha, beta, false, _depth - 1, _topLeftPoint, _bottomRightPoint);
			hash.checkTable[hashKey] = 1;
			hash.evalTable[hashKey] = valCur;
		}

		if (valCur > valBest) {
			valBest = valCur;
			moveBest = moveList[i];
		}
		else if (valCur == valBest) {
			if (rand() % 2) {
				moveBest = moveList[i];
			}
		}

		GameAction::UndoMove(board, moveCount, moveList[i]);

		alpha = (valCur > alpha) ? valCur : alpha;
		if (beta < alpha) break;

	}

	return moveBest;
}

GameAction::Point NewTopLeftPoint(const GameAction::Point& topLeftPoint, const GameAction::Point& point) {
	GameAction::Point newPoint = topLeftPoint;
	if (point.row < topLeftPoint.row) newPoint.row = point.row;
	if (point.col < topLeftPoint.col) newPoint.col = point.col;
	return newPoint;

}

GameAction::Point NewBottomRightPoint(const GameAction::Point& bottomRightPoint, const GameAction::Point& point) {
	GameAction::Point newPoint = bottomRightPoint;
	if (point.row > bottomRightPoint.row) newPoint.row = point.row;
	if (point.col > bottomRightPoint.col)  newPoint.col = point.col;
	return newPoint;

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
	const GameAction::Point bottomRightPoint)

{
	cnt++;

	const short playerValue = (!isMaximizingPlayer) ? PLAYER_AI : PLAYER_HUMAN;



	short state = Logic::GetGameState(board, moveCount, lastMove, playerValue);
	if (state != Logic::NULL_VALUE) {
		const short evalValue = (playerValue == PLAYER_HUMAN) ? -MAX_SCORE * state : MAX_SCORE * state;
		return evalValue;
	}

	if (depth == 0) {
		const short evalValue = Eval(board, moveCount, lastMove, !isMaximizingPlayer);
		return evalValue;

	}

	short rowLowerLimit = (topLeftPoint.row - FIRST_LOOKUP_RANGE >= 0) ? topLeftPoint.row - FIRST_LOOKUP_RANGE : 0;
	short rowUpperLimit = (bottomRightPoint.row + FIRST_LOOKUP_RANGE < Constants::BOARD_SIZE) ? bottomRightPoint.row + FIRST_LOOKUP_RANGE : Constants::BOARD_SIZE - 1;
	short colLowerLimit = (topLeftPoint.col - FIRST_LOOKUP_RANGE >= 0) ? topLeftPoint.col - FIRST_LOOKUP_RANGE : 0;
	short colUpperLimit = (bottomRightPoint.col + FIRST_LOOKUP_RANGE < Constants::BOARD_SIZE) ? bottomRightPoint.col + FIRST_LOOKUP_RANGE : Constants::BOARD_SIZE - 1;


	short searchSize = (rowUpperLimit - rowLowerLimit + 1) * (colUpperLimit - colLowerLimit + 1);

	short moveListSize = searchSize - moveCount;
	std::vector<GameAction::Point>moveList;
	moveList.resize(moveListSize);
	short right = 0, left = moveListSize - 1;

	const short tempValue = (isMaximizingPlayer) ? PLAYER_AI : PLAYER_HUMAN;


	for (short row = rowLowerLimit; row <= rowUpperLimit; ++row) {
		for (short col = colLowerLimit; col <= colUpperLimit; ++col) {
			if (board[row][col] == 0) {
				if (IsGoodMove(board, { row, col }, tempValue)) moveList[right++] = { row, col };
				else moveList[left--] = { row, col };


			}
		}
	}


	if (isMaximizingPlayer) {
		short valBest = -INF;
		for (size_t i = 0; i < moveListSize; ++i) {
			short valCur;
			GameAction::MakeMove(board, moveCount, moveList[i], PLAYER_AI);
			unsigned long long int hashKey = hash.computeHash(board);
			if (hash.checkTable[hashKey]) valCur = hash.evalTable[hashKey];
			else {
				valCur = MiniMax(board, moveCount, moveList[i], alpha, beta, false, depth - 1, NewTopLeftPoint({ rowLowerLimit, colLowerLimit }, { moveList[i].row, moveList[i].col }), NewBottomRightPoint({ rowUpperLimit, colUpperLimit }, { moveList[i].row, moveList[i].col }));
				hash.checkTable[hashKey] = 1;
				hash.evalTable[hashKey] = valCur;
			}
			valBest = (valCur > valBest) ? valCur : valBest;
			GameAction::UndoMove(board, moveCount, moveList[i]);

			alpha = (valCur > alpha) ? valCur : alpha;
			if (beta < alpha) break;


		}
		return valBest;
	}
	else {
		short valBest = INF;
		for (size_t i = 0; i < moveListSize; ++i) {
			short valCur;
			GameAction::MakeMove(board, moveCount, moveList[i], PLAYER_HUMAN);
			unsigned long long int hashKey = hash.computeHash(board);
			if (hash.checkTable[hashKey]) valCur = hash.evalTable[hashKey];
			else {
				valCur = MiniMax(board, moveCount, moveList[i], alpha, beta, true, depth - 1, NewTopLeftPoint({ rowLowerLimit, colLowerLimit }, { moveList[i].row, moveList[i].col }), NewBottomRightPoint({ rowUpperLimit, colUpperLimit }, { moveList[i].row, moveList[i].col }));
				hash.checkTable[hashKey] = 1;
				hash.evalTable[hashKey] = valCur;
			}
			valBest = (valCur < valBest) ? valCur : valBest;
			GameAction::UndoMove(board, moveCount, moveList[i]);

			beta = (valCur < beta) ? valCur : beta;
			if (beta < alpha) break;


		}
		return valBest;
	}
}


void AI::UpdatePrivateValues(GameAction::Point point) {
	if (point.row < _topLeftPoint.row) _topLeftPoint.row = point.row;
	if (point.col < _topLeftPoint.col) _topLeftPoint.col = point.col;

	if (point.row > _bottomRightPoint.row) _bottomRightPoint.row = point.row;
	if (point.col > _bottomRightPoint.col)  _bottomRightPoint.col = point.col;
	cnt = 0;
}

void AI::SetDifficulty(const short& difficulty)
{
	switch (difficulty) {
	case AI_DIFFICULTY_EASY:
		_depth = 1;
		break;
	case AI_DIFFICULTY_NORMAL:
		_depth = 2;
		break;
	case AI_DIFFICULTY_HARD:
		_depth = 4;
		break;
	}
}





















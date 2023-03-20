#pragma once
#include <vector>
#include "GameState.h"

using namespace std;

namespace GameAction {
	struct Point {
		short row, col;
	};

	typedef std::vector<vector<short>>Board;

	void MakeMove(
		Board& board,
		short& moveCount,
		const Point& move,
		const short& playerValue);

	void UndoMove(
		Board& board,
		short& moveCount,
		const Point& move);

	void ResetGameState(
		GameState& gameState
	);

	void InitBoard(Board& board, short& moveCount, Point& topLeftCorner, Point& bottomRightCorner);
	//void InitBoard(vector<vector<short>>& boardGameMatrix, short& moveCount);
}
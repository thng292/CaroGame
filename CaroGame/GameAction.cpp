#include "GameAction.h"

namespace GameAction {
	void MakeMove(GameView::GameBoard& gameBoard, short& moveCount, const short& row, const short& col, const short& playerValue)
	{
		gameBoard[row][col] = playerValue;
		moveCount++;
	}
	void UndoMove(GameView::GameBoard& gameBoard, short& moveCount, const short& row, const short& col, const short& playerValue)
	{
		gameBoard[row][col] = 0;
		moveCount--;
	}
}
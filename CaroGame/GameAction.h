#pragma once
#include "GameView.h"

namespace GameAction {
	void MakeMove(
		GameView::GameBoard& gameBoard,
		short& moveCount,
		const short& row,
		const short& col,
		const short& playerValue);

	void UndoMove(
		GameView::GameBoard& gameBoard,
		short& moveCount,
		const short& row,
		const short& col,
		const short& playerValue);

}
#include <fstream>

#include "GameAction.h"
#include "Constants.h"

using namespace std;

namespace GameAction {
	void MakeMove(
		Board& board,
		short& moveCount,
		const Point& move,
		const short& playerValue) {

		board[move.row][move.col] = playerValue;
		moveCount++;
	}
	void UndoMove(
		Board& board,
		short& moveCount,
		const Point& move) {

		board[move.row][move.col] = 0;
		moveCount--;
	}

	void ResetGameState(GameState& gameState)
	{
		GameState temp;
		gameState = temp;
	}

	void InitBoard(Board& board, short& moveCount, Point& topLeftPoint, Point& bottomRightPoint) {
		ifstream fileInput;
		fileInput.open("moves.txt");
		moveCount = 0;
		board.resize(Constants::BOARD_SIZE);

		for (short i = 0; i < Constants::BOARD_SIZE; ++i) board[i].resize(Constants::BOARD_SIZE);

		fileInput >> topLeftPoint.row >> topLeftPoint.col >> bottomRightPoint.row >> bottomRightPoint.col;
		for (size_t i = 0; i < Constants::BOARD_SIZE; ++i) {
			for (size_t j = 0; j < Constants::BOARD_SIZE; ++j) {
				fileInput >> board[i][j];
				if (board[i][j] != 0) moveCount++;
			}
		}

		fileInput.close();
		//MakeMove(board, moveCount,  1, 1, Constants::PLAYER_AI);
		/*MakeMove(board, moveCount, 2, 1, Constants::PLAYER_AI);
		MakeMove(board, moveCount, 2, 2, Constants::PLAYER_HUMAN);
		MakeMove(board, moveCount, 2, 3, Constants::PLAYER_HUMAN);*/

	}

}
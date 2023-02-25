#include <vector>

#include "Game.h"
#include "Constants.h"

using namespace std;

namespace Game {
	void MakeMove(
		vector<vector<short>>& boardGameMatrix,
		int& moveCount,
		const int& row,
		const int& col,
		const int& playerValue) {

		boardGameMatrix[row][col] = playerValue;
		moveCount++;
	}
	void UndoMove(
		vector<vector<short>>& boardGameMatrix,
		int& moveCount,
		const int& row,
		const int& col) {

		boardGameMatrix[row][col] = 0;
		moveCount--;
	}

	void InitBoard(vector<vector<short>>& boardGameMatrix, int& moveCount) {
		moveCount = 0;
		boardGameMatrix.resize(Constants::BOARD_SIZE);
		for (int i = 0;i < Constants::BOARD_SIZE;++i) boardGameMatrix[i].resize(Constants::BOARD_SIZE);
	}

}
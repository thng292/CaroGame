#pragma once
#include <vector>

using namespace std;

namespace Logic {
	int GetGameState(
		const vector<vector<short>>& boardGameMatrix,
		const int& moveCount,
		const int& rowCur,
		const int& colCur,
		const int& playerValue);

	bool CheckDraw(
		const vector<vector<short>>& boardGameMatrix,
		const int& moveCount);

	bool CheckVerticalWin(
		const vector<vector<short>>& boardGameMatrix,
		const int& rowCur,
		const int& colCur,
		const int& playerValue);

	bool CheckHorizontalWin(
		const vector<vector<short>>& boardGameMatrix,
		const int& rowCur,
		const int& colCur,
		const int& playerValue);

	bool CheckLeftDiagonalWin(
		const vector<vector<short>>& boardGameMatrix,
		const int& rowCur,
		const int& colCur,
		const int& playerValue);

	bool CheckRightDiagonalWin(
		const vector<vector<short>>& boardGameMatrix,
		const int& rowCur,
		const int& colCur,
		const int& playerValue);
}
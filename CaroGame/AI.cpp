#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

#include "AI.h"
#include "Constants.h"
#include "Logic.h"
using namespace std;

namespace AI {
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

	int Eval(
		const vector<vector<short>>& boardGameMatrix,
		const int& moveCount,
		const int& rowLastMove,
		const int& colLastMove,
		bool isMaximizingPlayer) {

		int playerValue = (!isMaximizingPlayer) ? Constants::PLAYER_AI : Constants::PLAYER_HUMAN;
		return Logic::GetGameState(boardGameMatrix, moveCount, rowLastMove, colLastMove, playerValue);
	}
  
	pair<short, short> GetBestMove(
		vector<vector<short>>& boardGameMatrix,
		int& moveCount,
		const int& rowLastMove,
		bool isMaximizingPlayer,
		const int& colLastMove) {

		int valBest = -Constants::INF;
		pair<short, short>moveBest;
		for (int row = 0;row < boardGameMatrix.size();++row) {
			for (int col = 0;col < boardGameMatrix.size();++col) {
				if (boardGameMatrix[row][col] == 0) {
					MakeMove(boardGameMatrix, moveCount, row, col, Constants::PLAYER_AI);

					int valCur = MiniMax(boardGameMatrix, moveCount, row, col, false);
					if (valCur > valBest) {
						valBest = valCur;
						moveBest.first = row;
						moveBest.second = col;
					}

					UndoMove(boardGameMatrix, moveCount, row, col);
				}
			}
		}
		return moveBest;
	}

	int MiniMax(
		vector<vector<short>>& boardGameMatrix,
		int& moveCount,
		const int& rowLastMove,
		const int& colLastMove,
		const bool& isMaximizingPlayer) {

		const int evalValue = Eval(boardGameMatrix, moveCount, rowLastMove, colLastMove, isMaximizingPlayer);
		if (evalValue != Constants::NULL_VALUE) {
			return evalValue;
		}

		if (isMaximizingPlayer) {
			int valBest = -Constants::INF;
			for (int row = 0;row < boardGameMatrix.size();++row) {
				for (int col = 0;col < boardGameMatrix.size();++col) {
					if (boardGameMatrix[row][col] == 0) {
						MakeMove(boardGameMatrix, moveCount, row, col, Constants::PLAYER_AI);
						int valCur = MiniMax(boardGameMatrix, moveCount, row, col, false);
						valBest = (valCur > valBest) ? valCur : valBest;
						UndoMove(boardGameMatrix, moveCount, row, col);
					}
				}
			}
			return valBest;
		}
		else {
			int valBest = Constants::INF;
			for (int row = 0;row < boardGameMatrix.size();++row) {
				for (int col = 0;col < boardGameMatrix.size();++col) {
					if (boardGameMatrix[row][col] == 0) {
						MakeMove(boardGameMatrix, moveCount, row, col, Constants::PLAYER_HUMAN);
						int valCur = MiniMax(boardGameMatrix, moveCount, row, col, true);
						valBest = (valCur < valBest) ? valCur : valBest;
						UndoMove(boardGameMatrix, moveCount, row, col);
					}
				}
			}
			return valBest;
		}
	}

}


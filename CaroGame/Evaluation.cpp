#include <vector>
#include <math.h>


#include "Evaluation.h"
#include "Constants.h"
#include "Logic.h"
#include "Ui.h"

using namespace std;

namespace Evaluation {
	int GetGameStateEval(
		const vector<vector<short>>& boardGameMatrix, 
		const int&moveCount, 
		const int& rowCur, 
		const int& colCur, 
		const int& playerValue) {
		int evalValue = Logic::GetGameState(boardGameMatrix, moveCount, rowCur, colCur, playerValue);
		evalValue = (evalValue == Constants::NULL_VALUE) ? 0 : evalValue;
		return evalValue * Constants::MAX_SCORE;
	}

	int GetHorizontalComboEval(
		const vector<vector<short>>& boardGameMatrix,
		vector<vector<short>> &comboCheckBoard,
		const int rowCur,
		const int colCur,
		const int playerValue) {

		int colLast = colCur;
		for (int col = colCur + 1; col < Constants::BOARD_SIZE - 1;++col) {
			if (boardGameMatrix[rowCur][col] == playerValue) {
				comboCheckBoard[rowCur][col] = 1;
				colLast = col;
			}
			else break;
		}

		int evalValue = pow(2, colLast - colCur + 1);

		bool blockLeft = false, blockRight = false;
		if (colCur == 0) blockLeft = true;
		else if (boardGameMatrix[rowCur][colCur - 1] != 0 && boardGameMatrix[rowCur][colCur - 1] != playerValue) blockLeft = true;
		if (colLast == Constants::BOARD_SIZE - 1) blockRight = true;
		else if (boardGameMatrix[rowCur][colLast + 1] != 0 && boardGameMatrix[rowCur][colLast + 1] != playerValue) blockRight = true;
		if (blockLeft && blockRight) evalValue = 0;
		else if (blockLeft || blockRight) evalValue /= 2;

		return evalValue;
	}

	int GetVerticalComboEval(
		const vector<vector<short>>& boardGameMatrix,
		vector<vector<short>>& comboCheckBoard,
		const int rowCur,
		const int colCur,
		const int playerValue) {

		int rowLast = rowCur;
		for (int row = rowCur + 1; row < Constants::BOARD_SIZE - 1;++row) {
			if (boardGameMatrix[row][colCur] == playerValue) {
				comboCheckBoard[row][colCur] = 2;
				rowLast = row;
			}
			else break;
		}

		int evalValue = pow(2, rowLast - rowCur + 1);

		bool blockLeft = false, blockRight = false;
		if (rowCur == 0) blockLeft = true;
		else if (boardGameMatrix[rowCur - 1][colCur] != 0 && boardGameMatrix[rowCur - 1][colCur] != playerValue) blockLeft = true;
		if (rowLast == Constants::BOARD_SIZE - 1) blockRight = true;
		else if (boardGameMatrix[rowLast + 1][colCur] != 0 && boardGameMatrix[rowLast + 1][colCur] != playerValue) blockRight = true;
		if (blockLeft && blockRight) evalValue = 0;
		else if (blockLeft || blockRight) evalValue /= 2;

		return evalValue;

	}

	int GetDiagonalRightComboEval(
		const vector<vector<short>>& boardGameMatrix,
		vector<vector<short>>& comboCheckBoard,
		const int rowCur,
		const int colCur,
		const int playerValue) {
		int rowLast = rowCur, colLast = colCur;
		for (int row = rowCur + 1, col = colCur + 1; 
			row < Constants::BOARD_SIZE - 1 && col < Constants::BOARD_SIZE - 1;
			++row,++col) {
			if (boardGameMatrix[row][col] == playerValue) {
				comboCheckBoard[row][col] = 3;
				rowLast = row;
				colLast = col;
			}
			else break;
		}

		int evalValue = pow(2, rowLast - rowCur + 1);

		bool blockLeft = false, blockRight = false;
		if (rowCur == 0 || colCur == 0) blockLeft = true;
		else if (boardGameMatrix[rowCur - 1][colCur - 1] != 0 && boardGameMatrix[rowCur - 1][colCur - 1] != playerValue) blockLeft = true;

		if (rowLast == Constants::BOARD_SIZE - 1 || colLast == Constants::BOARD_SIZE - 1) blockRight = true;
		else if (boardGameMatrix[rowLast + 1][colLast + 1] != 0 && boardGameMatrix[rowLast + 1][colLast + 1] != playerValue) blockRight = true;

		if (blockLeft && blockRight) evalValue = 0;
		else if (blockLeft || blockRight) evalValue /= 2;

		return evalValue;
	}

	int GetDiagonalLeftComboEval(
		const vector<vector<short>>& boardGameMatrix,
		vector<vector<short>>& comboCheckBoard,
		const int rowCur,
		const int colCur,
		const int playerValue) {

		int rowLast = rowCur, colLast = colCur;
		for (int row = rowCur - 1, col = colCur - 1;
			row >= 0 && col >= 0;
			--row, --col) {
			if (boardGameMatrix[row][col] == playerValue) {
				comboCheckBoard[row][col] = 4;
				rowLast = row;
				colLast = col;
			}
			else break;
		}

		int evalValue = pow(2, rowLast - rowCur + 1);

		bool blockLeft = false, blockRight = false;
		if (rowCur == 0 || colCur == Constants::BOARD_SIZE - 1) blockLeft = true;
		else if (boardGameMatrix[rowCur - 1][colCur + 1] != 0 && boardGameMatrix[rowCur - 1][colCur + 1] != playerValue) blockLeft = true;

		if (rowLast == Constants::BOARD_SIZE - 1 || colLast == 0) blockRight = true;
		else if (boardGameMatrix[rowLast + 1][colLast - 1] != 0 && boardGameMatrix[rowLast + 1][colLast - 1] != playerValue) blockRight = true;

		if (blockLeft && blockRight) evalValue = 0;
		else if (blockLeft || blockRight) evalValue /= 2;

		return evalValue;
	}

	int GetComboEval(
		const vector<vector<short>>& boardGameMatrix,
		const int& playerValue) {

		vector<vector<short>> comboCheckBoard(Constants::BOARD_SIZE, vector<short>(Constants::BOARD_SIZE, 0));

		int evalResult = 0;
		for (int row = 0;row < Constants::BOARD_SIZE;++row) {
			for (int col = 0;col < Constants::BOARD_SIZE;++col) {
				if (boardGameMatrix[row][col]) {
					int evalValue = 0;
					if (comboCheckBoard[row][col] < 1) {
						evalValue += GetHorizontalComboEval(boardGameMatrix, comboCheckBoard, row, col, boardGameMatrix[row][col]);
					}
					if (comboCheckBoard[row][col] < 2) {
						evalValue += GetVerticalComboEval(boardGameMatrix, comboCheckBoard, row, col, boardGameMatrix[row][col]);
					}
					if (comboCheckBoard[row][col] < 3) {
						evalValue += GetDiagonalRightComboEval(boardGameMatrix, comboCheckBoard, row, col, boardGameMatrix[row][col]);
					}
					if (comboCheckBoard[row][col] < 4) {
						evalValue += GetDiagonalLeftComboEval(boardGameMatrix, comboCheckBoard, row, col, boardGameMatrix[row][col]);
					}
					if (boardGameMatrix[row][col] == playerValue) evalResult += evalValue;
					else evalResult -= evalValue;
				}
				
			}
		}
		return evalResult;
	}
	
	int GetAdjacentNodeValue(
		const vector<vector<short>>& boardGameMatrix,
		const int& rowCur,
		const int& colCur,
		const int& playerValue) {

		if (rowCur < 0 || colCur < 0 || rowCur == Constants::BOARD_SIZE || colCur == Constants::BOARD_SIZE) return -1;
		
		if (boardGameMatrix[rowCur][colCur] == 0) return 1;
		if (boardGameMatrix[rowCur][colCur] == playerValue) return 2;

		return -1;
	}
	

	int GetNodeValueEval(const vector<vector<short>>& boardGameMatrix,
		const int& playerValue) {
		int evalResult = 0;
		for (int row = 0;row < Constants::BOARD_SIZE;++row) {
			for (int col = 0;col < Constants::BOARD_SIZE;++col) {
				if (boardGameMatrix[row][col] != 0) {
					int evalValue = 0;
					evalValue += GetAdjacentNodeValue(boardGameMatrix, row - 1, col - 1, boardGameMatrix[row][col]);
					evalValue += GetAdjacentNodeValue(boardGameMatrix, row - 1, col, boardGameMatrix[row][col]);
					evalValue += GetAdjacentNodeValue(boardGameMatrix, row - 1, col + 1, boardGameMatrix[row][col]);
					evalValue += GetAdjacentNodeValue(boardGameMatrix, row, col + 1, boardGameMatrix[row][col]);
					evalValue += GetAdjacentNodeValue(boardGameMatrix, row + 1, col + 1, boardGameMatrix[row][col]);
					evalValue += GetAdjacentNodeValue(boardGameMatrix, row + 1, col, boardGameMatrix[row][col]);
					evalValue += GetAdjacentNodeValue(boardGameMatrix, row + 1, col - 1, boardGameMatrix[row][col]);
					evalValue += GetAdjacentNodeValue(boardGameMatrix, row, col - 1, boardGameMatrix[row][col]);
				
					if (boardGameMatrix[row][col] == playerValue) evalResult += evalValue;
					else evalResult -= evalValue;
				}			
			}
		}
		return evalResult;
	}
}
#pragma once

namespace Constants {
	const int PLAYER_AI = -1, PLAYER_HUMAN = 1;
	const int WIN_VALUE_COUNT = 3;
	const int INF = 1000, NULL_VALUE = -5;

	const int BOARD_SIZE = 3;

	const int BOARD_ROW_NUM= BOARD_SIZE + 1, BOARD_COLUMN_NUM = BOARD_ROW_NUM;
	const int CELL_WIDTH = 6, CELL_HEIGHT = CELL_WIDTH - 2;
	const int X_PIVOT = 10, Y_PIVOT = 0;
}
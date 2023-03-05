//#include <Windows.h>
//#include "Board.h"
//
//namespace Board {
//
//	/*void DrawRow(short x, short y) {
//		for (short row = 0; row < Constants::BOARD_SIZE; ++row) {
//			char* s = (char*)malloc(Constants::BOARD_SIZE * Constants::CELL_WIDTH);
//			memset(s, )
//		}
//	}*/
//
//	void DrawGameRows(short x, short y) {
//		auto stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//		DWORD tmp = 0;
//		for (short row = 0; row < Constants::BOARD_SIZE + 1; ++row) {
//			FillConsoleOutputCharacter(stdHandle, L'\u2550',
//				Constants::CELL_GAME_WIDTH * Constants::BOARD_SIZE,
//				{ x, y + row * Constants::CELL_HEIGHT },
//				&tmp);
//		}
//		
//	}
//
//	void ChangeBoardCorners(short x, short y) {
//		View::WriteToView(x, y, L'\u2554');
//		View::WriteToView(x + Constants::BOARD_SIZE * Constants::CELL_GAME_WIDTH, y, L'\u2557');
//		View::WriteToView(x, y + Constants::BOARD_SIZE * Constants::CELL_HEIGHT, L'\u255A');
//		View::WriteToView(x + Constants::BOARD_SIZE * Constants::CELL_GAME_WIDTH, 
//			y + Constants::BOARD_SIZE * Constants::CELL_HEIGHT, L'\u255D');
//	}
//
//	void ChangeBoardTopBottomCorners(short x, short y) {
//		for (short i = 1; i < Constants::BOARD_SIZE; ++i) {
//			View::WriteToView(x + i * Constants::CELL_GAME_WIDTH, y, L'\u2566');
//			View::WriteToView(x + i * Constants::CELL_GAME_WIDTH, y + Constants::BOARD_SIZE * Constants::CELL_HEIGHT, L'\u2569');
//
//		}
//	}
//
//	void ChangeBoardCellCorners(short x, short y) {
//		for (short row = 1; row < Constants::BOARD_SIZE; ++row) {
//			for (short col = 1; col < Constants::BOARD_SIZE; ++col) {
//				View::WriteToView(x + col * Constants::CELL_GAME_WIDTH, y + row * Constants::CELL_HEIGHT, L'\u256C');
//
//			}
//		}
//	}
//
//	void ChangeBoardSideCorners(short x, short y) {
//		for (short i = 1; i < Constants::BOARD_SIZE; ++i) {
//			View::WriteToView(x, y + i * Constants::CELL_HEIGHT, L'\u2560');
//			View::WriteToView(x + Constants::BOARD_SIZE * Constants::CELL_GAME_WIDTH, y + i * Constants::CELL_HEIGHT, L'\u2563');
//
//		}
//	}
//
//	void DrawGameColumns(short x, short y) {
//		for (short col = 0; col < Constants::BOARD_SIZE + 1; ++col) {
//			for (short i = 0; i < Constants::BOARD_SIZE; ++i) {
//				for (short j = 0; j < Constants::CELL_HEIGHT; j++)
//				{
//					View::WriteToView(x + col * Constants::CELL_GAME_WIDTH,
//						y + i * Constants::CELL_HEIGHT + j, L'\u2551');
//
//				}
//			}
//			
//		}
//		
//	}
//
//	void DrawTimeContainer(short x, short y) {
//		View::Rect rect = {y, x, x + Constants::CELL_TIME_WIDTH ,y + Constants::CELL_HEIGHT};
//		View::DrawRect(rect);
//		View::WriteToView(x + 4, y + 1, L"05:00");
//	}
//
//	void DrawPlayerContainer(short x, short y) {
//		View::Rect rect = { y, x, x + Constants::CELL_PLAYER_WIDTH * 1 ,y + Constants::CELL_HEIGHT };
//		View::DrawRect(rect);
//		View::WriteToView(x + 3, y + 1, L"X");
//
//	}
//
//	void DrawWinCountContainer(short x, short y) {
//		View::Rect rect = { y, x, x + (Constants::CELL_WIN_COUNT_WIDTH) ,y + Constants::CELL_HEIGHT };
//		View::DrawRect(rect);
//		View::WriteToView(x + 3, y + 1, L"03");
//
//	}
//
//	void FixGameStatusCorners(short x, short y) {
//		short xCur = x;
//		xCur += Constants::CELL_TIME_WIDTH;
//		View::WriteToView(xCur, y, L'\u2566');
//		View::WriteToView(xCur, y + Constants::CELL_HEIGHT, L'\u2569');
//		xCur += Constants::CELL_WIN_COUNT_WIDTH;
//		View::WriteToView(xCur, y, L'\u2566');
//		View::WriteToView(xCur, y + Constants::CELL_HEIGHT, L'\u2569');
//		xCur += Constants::CELL_PLAYER_WIDTH;
//		View::WriteToView(xCur, y, L'\u2566');
//		View::WriteToView(xCur, y + Constants::CELL_HEIGHT, L'\u2569');
//		xCur += Constants::CELL_PLAYER_WIDTH;
//		View::WriteToView(xCur, y, L'\u2566');
//		View::WriteToView(xCur, y + Constants::CELL_HEIGHT, L'\u2569');
//		xCur += Constants::CELL_WIN_COUNT_WIDTH;
//		View::WriteToView(xCur, y, L'\u2566');
//		View::WriteToView(xCur, y + Constants::CELL_HEIGHT, L'\u2569');
//	}
//
//	void DrawGameStatusContainer(short x, short y) {
//		short xCur = x;
//		View::WriteToView(x + Constants::X_CENTER_TEXT, y - 1, L"Game Status");
//		DrawTimeContainer(x, y);
//		xCur += Constants::CELL_TIME_WIDTH;
//		DrawWinCountContainer(xCur, y);
//		xCur += Constants::CELL_WIN_COUNT_WIDTH;
//		DrawPlayerContainer(xCur, y);
//		xCur += Constants::CELL_PLAYER_WIDTH;
//		DrawPlayerContainer(xCur, y);
//		xCur += Constants::CELL_PLAYER_WIDTH;
//		DrawWinCountContainer(xCur, y);
//		xCur += Constants::CELL_WIN_COUNT_WIDTH;
//		DrawTimeContainer(xCur, y);
//
//		FixGameStatusCorners(x, y);
//
//	}
//
//	void FixGameBoardCorners(short x, short y) {
//		ChangeBoardCorners(x, y);
//		ChangeBoardTopBottomCorners(x, y);
//		ChangeBoardCellCorners(x, y);
//		ChangeBoardSideCorners(x, y);
//	}
//
//
//	void DrawGameBoard(short x, short y) {
//		DrawGameRows(x, y);
//		DrawGameColumns(x, y);
//		FixGameBoardCorners(x, y);
//	
//		DrawGameBoardHorizontalLabels(x, y);
//		DrawGameBoardVerticalLabels(x, y);
//	}
//
//	void DrawPlayerInfoContainer(short x, short y) {
//		View::WriteToView(x + Constants::X_CENTER_TEXT, y - 1, L"Player Info");
//
//		View::Rect rect = { y, x, x + Constants::CELL_PLAYER_INFO_WIDTH ,y + Constants::CELL_HEIGHT * 2};
//		View::DrawRect(rect);
//		
//		rect = { y, x + Constants::CELL_PLAYER_INFO_WIDTH, x + Constants::CELL_PLAYER_INFO_WIDTH * 2 ,y + Constants::CELL_HEIGHT * 2 };
//		View::DrawRect(rect);
//
//		View::WriteToView(x + Constants::CELL_PLAYER_INFO_WIDTH, y, L'\u2566');
//		View::WriteToView(x + Constants::CELL_PLAYER_INFO_WIDTH, y + Constants::CELL_HEIGHT * 2, L'\u2569');
//
//		View::WriteToView(x + 2, y + 1, L"Player ABC:...");
//		View::WriteToView(x + 2 + Constants::CELL_PLAYER_INFO_WIDTH, y + 1, L"Player XYZ:...");
//
//
//	}
//
//	void DrawLogContainer(short x, short y) {
//		View::WriteToView(x + Constants::X_CENTER_TEXT, y - 1, L"Move History");
//		View::Rect rect = { y, x, x + Constants::CELL_LOG_WIDTH ,y + Constants::CELL_HEIGHT * 4 };
//		View::DrawRect(rect);
//		View::WriteToView(x + 2, y + 1, L"Move 51: Player X...");
//
//	}
//
//	void DrawInstructions(short x, short y) {
//		char c = 'A';
//		View::WriteToView(x + Constants::X_CENTER_TEXT, y - 1, L"Shortcuts");
//		for (short i = 0; i < 3; ++i) {
//			for (short j = 0; j < 2; ++j) {
//				std::wstring s = L"A: Lorem ispum";
//				s[0] = c++;
//				View::WriteToView(x + Constants::CELL_WIDTH * 5 * j, y + Constants::CELL_HEIGHT * i + 1, s);
//
//			}
//		}
//		
//	}
//
//	void DrawGameBoardHorizontalLabels(short x, short y) {
//		char c = 'A';
//		for (int i = 0; i < Constants::BOARD_SIZE; ++i) {
//			std::wstring s = L"1";
//			s[0] = c++;
//			View::WriteToView(x + Constants::CELL_GAME_WIDTH * i + 2, y - 1, s);
//		}
//	}
//
//	void DrawGameBoardVerticalLabels(short x, short y) {
//		char c = '1';
//		for (int i = 0; i < Constants::BOARD_SIZE; ++i) {
//			std::wstring s = L"1";
//			
//			if (i == 9) c = '0';
//			if (i >= 9) {
//				s = L"10";
//				s[1] = c++;
//				View::WriteToView(x - 3, y + Constants::CELL_HEIGHT * i + 1, s);
//
//			}
//			else {
//				s[0] = c++;
//				View::WriteToView(x - 2, y + Constants::CELL_HEIGHT * i + 1, s);
//			}
//		}
//	}
//
//	void DrawToGameCell(short x, short y, std::wstring value) {
//		return;
//	}
//
//	void DrawToTimeContainer(short id, std::wstring value) {
//		return;
//	}
//	void DrawToPlayerContainer(short id, std::wstring value) {
//		return;
//	}
//	void DrawToWinCountContainer(short id, std::wstring value) {
//		return;
//	}
//	void DrawToPlayerInfoContainer(short id, std::wstring value) {
//		return;
//	}
//
//	void DrawToLogContainer(std::wstring value) {
//		return;
//	}
//
//
//	void DrawBoard(short x, short y) {
//		short xPivot = x, yPivot = y;
//		DrawGameBoard(xPivot, yPivot + 1);
//		xPivot = x + Constants::BOARD_SIZE * Constants::CELL_GAME_WIDTH + Constants::BOARD_GAME_MARGIN;
//		yPivot = y + 1;
//		DrawGameStatusContainer(xPivot, yPivot);
//		yPivot += Constants::CELL_HEIGHT * 2;
//		DrawPlayerInfoContainer(xPivot, yPivot);
//		yPivot += Constants::CELL_HEIGHT * 3;
//		DrawLogContainer(xPivot, yPivot);
//		yPivot += Constants::CELL_HEIGHT * 5;
//		DrawInstructions(xPivot, yPivot);
//	}
//}
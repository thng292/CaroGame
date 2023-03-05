#include "GameView.h"
#include "View.h"
#include "InputHandle.h"
#include "GameScreen.h"

void GameView::GameModeVersusView(NavigationHost& NavHost)
{
	short selectedOption = 0;
	const short MAX_OPTIONS = 2;

	while (1) {
		View::DrawMenuCenter(L"Choose game mode",
			{
			{L"PvP", L'1'},
			{L"PvE", L'2'},
			},
			selectedOption);
		auto tmp = InputHandle::Get();
		if (tmp == L"w" || tmp == L"W") {
			selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
		}
		if (tmp == L"s" || tmp == L"S") {
			selectedOption = (selectedOption + 1) % MAX_OPTIONS;
		}
		if (tmp == L"1") {
			return NavHost.Navigate("AIDifficultyView");
		}
		if (tmp == L"2") {
			return NavHost.Navigate("AIDifficultyView");
		}
		if (tmp == L"e" || tmp == L"E") {
			return NavHost.Back();
		}
		if (tmp == L"\r") {
			switch (selectedOption)
			{
			case 0:
				return NavHost.Navigate("AIDifficultyView");
			case 1:
				return NavHost.Navigate("AIDifficultyView");
			}
		}
	}

}

void GameView::PlayerNameView(NavigationHost& NavHost)
{
	return;
}

void GameView::GameModeTypeView(NavigationHost& NavHost)
{
	short selectedOption = 0;
	const short MAX_OPTIONS = 3;
	while (1) {
		View::DrawMenuCenter(L"Choose game type", {
			{L"Normal", L'1'},
			{L"Rush", L'2'}
			}, selectedOption);
		auto tmp = InputHandle::Get();
		if (tmp == L"w" || tmp == L"W") {
			selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
		}
		if (tmp == L"s" || tmp == L"S") {
			selectedOption = (selectedOption + 1) % MAX_OPTIONS;
		}
		if (tmp == L"1") {
			return NavHost.Navigate("GameScreenView");
		}
		if (tmp == L"2") {
			return NavHost.Navigate("GameScreenView");
		}
		if (tmp == L"e" || tmp == L"E") {
			return NavHost.Back();
		}

		if (tmp == L"\r") {
			switch (selectedOption)
			{
			case 0:
				return NavHost.Navigate("GameScreenView");
			case 1:
				return NavHost.Navigate("GameScreenView");
			}
		}
	}
}

void GameView::GameScreenView(NavigationHost& NavHost)
{
	GameScreen gameScreen(7, 2);
	gameScreen.DrawGameScreen();
	short row = 0, col = 0;
	std::wstring player = L"O";
	View::Goto(gameScreen.boardContainer.xCoord + 2, gameScreen.boardContainer.yCoord + 1);

	while (1) {
		auto tmp = InputHandle::Get();
		if (tmp == L"w" || tmp == L"W") {
			if (row - 1 >= 0) {
				row--;
				View::Goto(gameScreen.boardContainer.xCoord + BoardContainer::CELL_WIDTH * col + 2,
					gameScreen.boardContainer.yCoord + BoardContainer::CELL_HEIGHT * row + 1);
			}
		}
		if (tmp == L"a" || tmp == L"A") {
			if (col - 1 >= 0) {
				col--;
				View::Goto(gameScreen.boardContainer.xCoord + BoardContainer::CELL_WIDTH * col + 2,
					gameScreen.boardContainer.yCoord + BoardContainer::CELL_HEIGHT * row + 1);
			}
		}
		if (tmp == L"s" || tmp == L"S") {
			if (row + 1 < Constants::BOARD_SIZE) {
				row++;
				View::Goto(gameScreen.boardContainer.xCoord + BoardContainer::CELL_WIDTH * col + 2,
					gameScreen.boardContainer.yCoord + BoardContainer::CELL_HEIGHT * row + 1);
			}
		}
		if (tmp == L"d" || tmp == L"D") {
			if (col + 1 < Constants::BOARD_SIZE) {
				col++;
				View::Goto(gameScreen.boardContainer.xCoord + BoardContainer::CELL_WIDTH * col + 2,
					gameScreen.boardContainer.yCoord + BoardContainer::CELL_HEIGHT * row + 1);
			}
		}

		if (tmp == L"\r") {
			gameScreen.boardContainer.DrawToBoardContainerCell(row, col, player);
			if (player == L"O") player = L"X";
			else player = L"O";
		}
		if (tmp == L"e" || tmp == L"E") {
			return NavHost.Back();
		}
	}

	
}

void GameView::AIDifficultyView(NavigationHost& NavHost)
{
	short selectedOption = 0;
	const short MAX_OPTIONS = 3;
	while (1) {
		View::DrawMenuCenter(L"Choose difficulty", {
			{L"Easy", L'1'},
			{L"Normal", L'2'},
			{L"Hard", L'3'},
			}, selectedOption);
		auto tmp = InputHandle::Get();
		if (tmp == L"w" || tmp == L"W") {
			selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
		}
		if (tmp == L"s" || tmp == L"S") {
			selectedOption = (selectedOption + 1) % MAX_OPTIONS;
		}
		if (tmp == L"1") {
			return NavHost.Navigate("GameModeTypeView");
		}
		if (tmp == L"2") {
			return NavHost.Navigate("GameModeTypeView");
		}
		if (tmp == L"3") {
			return NavHost.Navigate("GameModeTypeView");
		}
		if (tmp == L"e" || tmp == L"E") {
			return NavHost.Back();
		}

		if (tmp == L"\r") {
			switch (selectedOption)
			{
			case 0:
				return NavHost.Navigate("GameModeTypeView");
			case 1:
				return NavHost.Navigate("GameModeTypeView");

			case 2:
				return NavHost.Navigate("GameModeTypeView");
			}
		}
	}
}

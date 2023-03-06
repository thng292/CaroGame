#include "GameView.h"
#include "View.h"
#include "InputHandle.h"
#include "GameScreen.h"
#include "Constants.h"

void GameView::GameModeVersusView(NavigationHost& NavHost)
{
	short selectedOption = 0;
	const short MAX_OPTIONS = 2;

	while (1) {
		View::DrawMenuCenter(L"Choose game mode",
			{
			{L"PvP", L'P'},
			{L"PvE", L'E'},
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
			return NavHost.Navigate("PlayerNameView");
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
				return NavHost.Navigate("PlayerNameView");
			case 1:
				return NavHost.Navigate("AIDifficultyView");
			}
		}
	}

}

void GameView::PlayerNameView(NavigationHost& NavHost)
{
	View::WriteToView(10, 10, L"Player Name View, press Enter to continue");
	auto tmp = InputHandle::Get();
	if (tmp == L"\r") {
		return NavHost.Navigate("GameScreenView");
	}
}

void GameView::GameModeTypeView(NavigationHost& NavHost)
{
	short selectedOption = 0;
	const short MAX_OPTIONS = 2;
	while (1) {
		View::DrawMenuCenter(L"Choose game type", {
			{L"Normal", L'N'},
			{L"Rush", L'R'}
			}, selectedOption);
		auto tmp = InputHandle::Get();
		if (tmp == L"w" || tmp == L"W") {
			selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
		}
		if (tmp == L"s" || tmp == L"S") {
			selectedOption = (selectedOption + 1) % MAX_OPTIONS;
		}
		if (tmp == L"1") {
			return NavHost.Navigate("GameModeVersusView");
		}
		if (tmp == L"2") {
			return NavHost.Navigate("GameModeVersusView");
		}
		if (tmp == L"e" || tmp == L"E") {
			return NavHost.Back();
		}

		if (tmp == L"\r") {
			switch (selectedOption)
			{
			case 0:
				return NavHost.Navigate("GameModeVersusView");
			case 1:
				return NavHost.Navigate("GameModeVersusView");
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
	View::Goto(gameScreen.boardContainer.xCoord + BoardContainer::X_OFFSET, gameScreen.boardContainer.yCoord + BoardContainer::Y_OFFSET);

	while (1) {
		auto tmp = InputHandle::Get();
		if (tmp == L"w" || tmp == L"W") {
			if (row - 1 >= 0) {
				row--;
				View::Goto(gameScreen.boardContainer.xCoord + BoardContainer::CELL_WIDTH * col + BoardContainer::X_OFFSET,
					gameScreen.boardContainer.yCoord + BoardContainer::CELL_HEIGHT * row + BoardContainer::Y_OFFSET);
			}
		}
		if (tmp == L"a" || tmp == L"A") {
			if (col - 1 >= 0) {
				col--;
				View::Goto(gameScreen.boardContainer.xCoord + BoardContainer::CELL_WIDTH * col + BoardContainer::X_OFFSET,
					gameScreen.boardContainer.yCoord + BoardContainer::CELL_HEIGHT * row + BoardContainer::Y_OFFSET);
			}
		}
		if (tmp == L"s" || tmp == L"S") {
			if (row + 1 < Constants::BOARD_SIZE) {
				row++;
				View::Goto(gameScreen.boardContainer.xCoord + BoardContainer::CELL_WIDTH * col + BoardContainer::X_OFFSET,
					gameScreen.boardContainer.yCoord + BoardContainer::CELL_HEIGHT * row + BoardContainer::Y_OFFSET);
			}
		}
		if (tmp == L"d" || tmp == L"D") {
			if (col + 1 < Constants::BOARD_SIZE) {
				col++;
				View::Goto(gameScreen.boardContainer.xCoord + BoardContainer::CELL_WIDTH * col + BoardContainer::X_OFFSET,
					gameScreen.boardContainer.yCoord + BoardContainer::CELL_HEIGHT * row + BoardContainer::Y_OFFSET);
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
			{L"Easy", L'E'},
			{L"Normal", L'N'},
			{L"Hard", L'H'},
			}, selectedOption);
		auto tmp = InputHandle::Get();
		if (tmp == L"w" || tmp == L"W") {
			selectedOption = (selectedOption - 1 + MAX_OPTIONS) % MAX_OPTIONS;
		}
		if (tmp == L"s" || tmp == L"S") {
			selectedOption = (selectedOption + 1) % MAX_OPTIONS;
		}
		if (tmp == L"1") {
			return NavHost.Navigate("PlayerNameView");
		}
		if (tmp == L"2") {
			return NavHost.Navigate("PlayerNameView");
		}
		if (tmp == L"3") {
			return NavHost.Navigate("PlayerNameView");
		}
		if (tmp == L"e" || tmp == L"E") {
			return NavHost.Back();
		}

		if (tmp == L"\r") {
			switch (selectedOption)
			{
			case 0:
				return NavHost.Navigate("PlayerNameView");
			case 1:
				return NavHost.Navigate("PlayerNameView");

			case 2:
				return NavHost.Navigate("PlayerNameView");
			}
		}
	}
}

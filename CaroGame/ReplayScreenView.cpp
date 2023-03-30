#include "ReplayScreenView.h"

void ReplayScreenView::ReplayScreenView(NavigationHost& NavHost)
{
    GameState curGameState =
        std::any_cast<GameState>(NavHost.GetFromContext(Constants::CURRENT_GAME)
        );

    GameAction::Board gameBoard(
        Constants::BOARD_SIZE, std::vector<short>(Constants::BOARD_SIZE, 0)
    );

    GameScreen replayScreen(7, 2);
    replayScreen.DrawGameScreen();
    replayScreen.DrawToElements(curGameState, true);

    short index = -1;
    bool isPlayerOne = curGameState.playerOneFirst;
    std::vector<std::pair<short, short>> tempMoveList;
    short moveListSize = curGameState.moveList.size();
    GameAction::Point latestMove;
    while (1) {
        auto tmp = InputHandle::Get();
        bool moveBack = false, validKey = false;

        if (Utils::keyMeanLeft(tmp) && index > 0) {
            moveBack = true;
            validKey = true;
        }

        if (Utils::keyMeanRight(tmp) && (index < moveListSize - 1)) {
            validKey = true;
        };

        if (validKey) {
            GameAction::Point move;
            if (!moveBack) {
                index++;
                move = {
                    curGameState.moveList[index].first,
                    curGameState.moveList[index].second};
                tempMoveList.push_back({move.row, move.col});
                
            } else {
                index--;
                move = {
                    curGameState.moveList[index].first,
                    curGameState.moveList[index].second};
         
                GameScreenAction::DeleteMoveFromScreen(
                    replayScreen, latestMove
                );
                tempMoveList.pop_back();
            }

            Constants::Player player =
                (isPlayerOne) ? Constants::PLAYER_ONE : Constants::PLAYER_TWO;

            UpdateScreen(
                replayScreen, move, player, tempMoveList, curGameState
            );
            isPlayerOne = !isPlayerOne;
            latestMove = move;

        }
    }

    auto c = _getch();
    return NavHost.NavigateExit();
}

void ReplayScreenView::UpdateScreen(
    GameScreen gameScreen,
    const GameAction::Point& move,
    const Constants::Player& player,
    const std::vector<std::pair<short, short>>& moveList,
    const GameState& gameState
)
{
    View::Color color =
        (player.symbol == L"X") ? View::Color::RED : View::Color::BLUE;
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, player.symbol, color
    );
    gameScreen.logContainer.DrawToLogContainer(
        moveList,
        gameState.playerNameOne,
        gameState.playerNameTwo,
        gameState.playerOneFirst
    );
}

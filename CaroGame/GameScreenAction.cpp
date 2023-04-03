#include "GameScreenAction.h"

void GameScreenAction::UpdateGame(
    GameScreen gameScreen,
    GameAction::Board& board,
    short& moveCount,
    const GameAction::Point& move,
    const Constants::Player& player,
    GameState& gameState,
    bool loadFromSave
)
{
    if (move.row != -1) {
        View::Color color = (player.symbol == Constants::PLAYER_ONE.symbol)
                                ? (View::Color)Constants::PLAYER_ONE_COLOR
                                : (View::Color)Constants::PLAYER_TWO_COLOR;
        GameAction::MakeMove(board, moveCount, move, player.value);
        gameScreen.boardContainer.DrawToBoardContainerCell(
            move.row, move.col, player.symbol, color
        );
    }

    if (!loadFromSave) {
        if (move.row != -1) gameState.moveList.push_back({move.row, move.col});
        gameScreen.logContainer.DrawToLogContainer(
            gameState.moveList,
            gameState.playerNameOne,
            gameState.playerNameTwo,
            gameState.playerOneFirst
        );
    }
}

void GameScreenAction::UndoMove(
    GameScreen& gameScreen,
    GameAction::Board& gameBoard,
    short& moveCount,
    GameState& curGameState,
    GameAction::Point& curMove,
    GameAction::Point& prevMove,
    Constants::Player& curPlayer,
    Constants::Player& prevPlayer,
    bool& isPlayerOneTurn
)
{
    GameAction::UndoMove(gameBoard, moveCount, curMove);
    GameScreenAction::DeleteMoveFromScreen(gameScreen, curMove);
    curGameState.moveList.pop_back();
    if (curGameState.moveList.size() != 0) {
        curMove = {
            curGameState.moveList.back().first,
            curGameState.moveList.back().second};
        prevMove = curMove;
        if (curGameState.moveList.size() != 0) curGameState.moveList.pop_back();

    } else {
        curMove = {-1, -1};
        prevMove = {-1, -1};
    }

    curPlayer =
        (isPlayerOneTurn) ? Constants::PLAYER_ONE : Constants::PLAYER_TWO;
    prevPlayer = curPlayer;

    GameScreenAction::UpdateGame(
        gameScreen, gameBoard, moveCount, curMove, curPlayer, curGameState
    );

    GameScreenAction::HighlightMove(gameScreen, curMove, curPlayer.symbol);

    isPlayerOneTurn = !isPlayerOneTurn;
}

void GameScreenAction::HightLightWin(
    const GameAction::Point& winMoveOne,
    const GameAction::Point& winMoveTwo,
    const std::wstring& playerValue,
    GameScreen& gameScreen,
    bool unhighlight
)
{
    GameAction::Point leftPoint, rightPoint;
    if (winMoveOne.col < winMoveTwo.col) {
        leftPoint = winMoveOne;
        rightPoint = winMoveTwo;
    } else {
        leftPoint = winMoveTwo;
        rightPoint = winMoveOne;
    }

    short rowAddition = 0,
          colAddition = (leftPoint.col == rightPoint.col) ? 0 : 1;

    if (leftPoint.row < rightPoint.row) {
        rowAddition = 1;
    } else if (leftPoint.row > rightPoint.row) {
        rowAddition = -1;
    }

    short cnt = 0;
    GameAction::Point point = leftPoint;

    View::Color color;
    if (unhighlight) {
        if (playerValue == Constants::PLAYER_ONE.symbol)
            color = (View::Color)Constants::PLAYER_ONE_COLOR;
        else
            color = (View::Color)Constants::PLAYER_TWO_COLOR;
    } else
        color = (View::Color)Constants::WIN_HIGHLIGHT;

    while (cnt < 5) {
        gameScreen.boardContainer.DrawToBoardContainerCell(
            point.row, point.col, playerValue, color
        );
        point.row += rowAddition;
        point.col += colAddition;
        cnt++;
    }
}

void GameScreenAction::HighlightMove(
    GameScreen& gameScreen,
    const GameAction::Point& move,
    const std::wstring value
)
{
    if (move.row == -1) return;
    View::Color color = (value == Constants::PLAYER_ONE.symbol)
                            ? (View::Color)Constants::PLAYER_ONE_HIGHLIGHT
                            : (View::Color)Constants::PLAYER_TWO_HIGHLIGHT;
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, value, color
    );
}

void GameScreenAction::UnhightlightMove(
    GameScreen& gameScreen,
    const GameAction::Point& move,
    const std::wstring value
)
{
    if (move.row == -1) return;
    View::Color color = (value == Constants::PLAYER_ONE.symbol)
                            ? (View::Color)Constants::PLAYER_ONE_COLOR
                            : (View::Color)Constants::PLAYER_TWO_COLOR;
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, value, color
    );
}

GameAction::Point GameScreenAction::HandleState(
    const GameAction::Board& board,
    const short& moveCount,
    const GameAction::Point& move,
    const Constants::Player& player,
    const bool& isPlayerOneTurn,
    GameState& curGameState,
    bool& endGame,
    GameScreen& gameScreen
)
{
    GameAction::Point winPoint;

    short state = Logic::GetGameState(
        board, moveCount, move, player.value, winPoint, true
    );
    switch (state) {
        case Logic::WIN_VALUE:
            if (isPlayerOneTurn)
                curGameState.playerScoreOne++;
            else
                curGameState.playerScoreTwo++;
            HightLightWin(move, winPoint, player.symbol, gameScreen);
            endGame = 1;
            break;
        case Logic::DRAW_VALUE:
            endGame = 1;
            break;
    }
    return winPoint;
}

void GameScreenAction::LoadGameToView(
    GameScreen& gameScreen,
    GameAction::Board& board,
    short& moveCount,
    GameState gameState,
    AI& ai
)
{
    bool isPlayerOne = gameState.playerOneFirst;

    const short moveListSize = gameState.moveList.size();
    Constants::Player player;
    GameAction::Point move;

    for (size_t i = 0; i < moveListSize; ++i) {
        player = (isPlayerOne) ? Constants::PLAYER_ONE : Constants::PLAYER_TWO;
        move = {gameState.moveList[i].first, gameState.moveList[i].second};

        ai.UpdatePrivateValues(move);
        board[move.row][move.col] = player.value;
        UpdateGame(gameScreen, board, moveCount, move, player, gameState, true);
        if (i == moveListSize - 1)
            HighlightMove(gameScreen, move, player.symbol);
        isPlayerOne = !isPlayerOne;
    }
}

void GameScreenAction::DeleteMoveFromScreen(
    GameScreen& gameScreen, const GameAction::Point& move
)
{
    if (move.row == -1) return;
    gameScreen.boardContainer.DrawToBoardContainerCell(
        move.row, move.col, L" "
    );
}

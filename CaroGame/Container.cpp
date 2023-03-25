#include "Container.h"

void Container::DrawContainer()
{
    View::Rect rect = {yCoord, xCoord, xCoord + cellWidth, yCoord + cellHeight};
    View::DrawRect(rect);
}

void Container::DrawToContainer(std::wstring value)
{
    View::WriteToView(xCoord + xOffset, yCoord + yOffset, value);
}

void Container::DrawToLogContainer(
    const std::vector<std::pair<short, short>> &valueList,
    const std::wstring& playerNameOne,
    const std::wstring& playerNameTwo,
    bool playerOneFirst
)
{
    short valueListSize = valueList.size();
    short numOfValueDisplay = (valueListSize >= 6) ? 6 : valueListSize;
    size_t startIndex = valueListSize - numOfValueDisplay;

    std::wstring playerName, playerSymbol;

    DWORD tmp = 0;
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    bool isPlayerOneTurn = (startIndex % 2 == 0 && playerOneFirst) ||
                           (startIndex % 2 != 0 && !playerOneFirst);

    for (size_t i = 0; i < numOfValueDisplay; ++i) {
        if (isPlayerOneTurn) {
            playerName = playerNameOne;
            playerSymbol = Constants::PLAYER_ONE.symbol;
        } else {
            playerName = playerNameTwo;
            playerSymbol = Constants::PLAYER_TWO.symbol;
        }

        std::wstring value = std::format(
            L"Move {}: Player {} ({}) played {}{}",
            startIndex + 1,
            playerName,
            playerSymbol,
            (wchar_t)(L'A' + valueList[startIndex].second),
            valueList[startIndex].first + 1
        );

        FillConsoleOutputCharacter(
            StdOut,
            L' ',
            cellWidth - xOffset,
            {xCoord + xOffset, yCoord + yOffset + (short)i},
            &tmp
        );
        View::WriteToView(xCoord + xOffset, yCoord + yOffset + i, value);
        startIndex++;
        isPlayerOneTurn = !isPlayerOneTurn;
    }
}


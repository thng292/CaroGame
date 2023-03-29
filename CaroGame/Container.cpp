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


    short absDontWork = (playerNameOne.size() - playerNameTwo.size());
    absDontWork = (absDontWork < 0) ? -absDontWork : absDontWork;
    std::wstring temp(absDontWork, L' ');
  

    View::Color color;
    for (short i = 0; i < numOfValueDisplay; ++i) {
        std::wstring extraSpace;
        if (isPlayerOneTurn) {
            playerName = playerNameOne;
            playerSymbol = Constants::PLAYER_ONE.symbol;
            color = View::Color::RED;
            if (playerNameOne.size() < playerNameTwo.size()) {
                extraSpace = temp;
            }

        } else {
            playerName = playerNameTwo;
            playerSymbol = Constants::PLAYER_TWO.symbol;
            color = View::Color::BLUE;
            if (playerNameTwo.size() < playerNameOne.size()) {
                extraSpace = temp;
            }
        }

        std::wstring value = std::format(
            L"Move {}: Player {}{} ({}) played {}{}",
            startIndex + 1,
            playerName,
            extraSpace,
            playerSymbol,
            (wchar_t)(L'A' + valueList[startIndex].second),
            valueList[startIndex].first + 1
        );


        FillConsoleOutputCharacter(
            StdOut,
            L' ',
            cellWidth - 1,
            {xCoord + 1, yCoord + yOffset + i},
            &tmp
        );

        short temp =
            value.size() - 1 - ((valueList[startIndex].first + 1 < 10) ? 1 : 2) + 2;
        const short X_CENTER = (cellWidth - temp) / 2;
                  

        View::WriteToView(
            xCoord + X_CENTER,
            yCoord + yOffset + i,
            value,
            (wchar_t)0U,
            false,
            color
        );

        startIndex++;
        isPlayerOneTurn = !isPlayerOneTurn;
    }
}


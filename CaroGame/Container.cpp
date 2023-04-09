#include "Container.h"

void Container::DrawContainer()
{
    View::Rect rect = {yCoord, xCoord, xCoord + cellWidth, yCoord + cellHeight};
    View::DrawRect(rect);
}

void Container::DrawToContainer(std::wstring value, View::Color color)
{
    View::WriteToView(xCoord + xOffset, yCoord + yOffset, value, (wchar_t)0U, false, color);
}

void Container::DrawToLogContainer(
    const std::vector<std::pair<short, short>> &valueList,
    const std::wstring& playerNameOne,
    const std::wstring& playerNameTwo,
    bool playerOneFirst,
    short winMethod,
    bool isReplay

)
{
    short maxRow = 5;
    short maxDisplay = (winMethod != 0) ? maxRow - 1 - !isReplay : maxRow;
    short valueListSize = valueList.size();
    short numOfValueDisplay = (valueListSize >= maxDisplay) ? maxDisplay : valueListSize;
    size_t startIndex = valueListSize - numOfValueDisplay;



    std::wstring playerName, playerSymbol;
    std::wstring moveText = Language::GetString(L"MOVE_TEXT");
    std::wstring playerText = Language::GetString(L"PLAYER_TEXT");
    std::wstring playedText = Language::GetString(L"PLAYED_TEXT");
    std::wstring winText = Language::GetString(L"WIN_TEXT");
    std::wstring drawText = Language::GetString(L"DRAW_TEXT");
    std::wstring timeText = Language::GetString(L"WIN_TIME_TEXT");



    DWORD tmp = 0;
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    bool isPlayerOneTurn = (startIndex % 2 == 0 && playerOneFirst) ||
                           (startIndex % 2 != 0 && !playerOneFirst);


    short absDontWork = (playerNameOne.size() - playerNameTwo.size());
    absDontWork = (absDontWork < 0) ? -absDontWork : absDontWork;
    std::wstring temp(absDontWork, L' ');
  

    View::Color color;

    for (short i = 0; i < maxRow; ++i) {
        FillConsoleOutputCharacter(
            StdOut,
            L' ',
            cellWidth - 1,
            {xCoord + 1, yCoord + yOffset + i},
            &tmp
        );
    }

    for (short i = 0; i < numOfValueDisplay; ++i) {
        
        std::wstring extraSpace;
        if (isPlayerOneTurn) {
            playerName = playerNameOne;
            playerSymbol = Constants::PLAYER_ONE.symbol;
            color = Theme::GetColor(ThemeColor::PLAYER_ONE_COLOR);
            if (playerNameOne.size() < playerNameTwo.size()) {
                extraSpace = temp;
            }

        } else {
            playerName = playerNameTwo;
            playerSymbol = Constants::PLAYER_TWO.symbol;
            color = Theme::GetColor(ThemeColor::PLAYER_TWO_COLOR);
            if (playerNameTwo.size() < playerNameOne.size()) {
                extraSpace = temp;
            }
        }

        std::wstring value = std::format(
            L"{} {}: {} {}{} ({}) {} {}{}",
            moveText,
            startIndex + 1,
            playerText,
            playerName,
            extraSpace,
            playerSymbol,
            playedText,
            (wchar_t)(L'A' + valueList[startIndex].second),
            valueList[startIndex].first + 1
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
    if (winMethod != 0) {
        std::wstring value;

        switch (winMethod) {
            case Constants::END_GAME_WIN_TIME_ONE:
                value = std::format(
                    L"{} {} ({}) {}", playerText, playerNameOne, Constants::PLAYER_ONE.symbol,timeText
                );
                break;
            case Constants::END_GAME_WIN_TIME_TWO:
                value = std::format(
                    L"{} {} ({}) {}",
                    playerText,
                    playerNameTwo,
                    Constants::PLAYER_TWO.symbol,
                    timeText
                );
                break;
            case Constants::END_GAME_DRAW:
                value = Language::GetString(L"DRAW_TEXT");
                break;
            default:

                value = std::format(
                    L"{} {} ({}) {}", playerText, playerName, playerSymbol, winText
                );
                break;
        }

            
          
        short X_CENTER = Label::GetCenterX(xCoord, cellWidth, value.size());
        View::WriteToView(
            X_CENTER,
            yCoord + yOffset + numOfValueDisplay,
            value,
            (wchar_t)0U,
            false,
            Theme::GetColor(ThemeColor::RESULT_TEXT_COLOR)
        );
        if (!isReplay) {
            value = Language::GetString(L"SPACE_KEY_CONTINUE");

            X_CENTER = Label::GetCenterX(xCoord, cellWidth, value.size());
            View::WriteToView(
                X_CENTER,
                yCoord + yOffset + numOfValueDisplay + 1,
                value
            );
        }
        
        
    }
}


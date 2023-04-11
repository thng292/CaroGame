#include "InputBox.h"

std::pair<short, short> InputBox::CalcCenter(short width, short height)
{
    return {59 - width / 2, 14 - height / 2};
}

short InputBox::GetMaxWidth(LabelList labelList)
{
    short res = 0;
    std::for_each(labelList.begin(), labelList.end(), [&res](const auto &elem) {
        res = max(res, elem.length());
    });
    return res;
}

bool InputBox::DrawInputBox(
    LabelList labelList,
    size_t &selected,
    InputList &inputList,
    bool maxReached,
    short maxLength
)
{
    const short MARGIN = 2, PADDING = 2;
    const short HEIGHT = labelList.size() * MARGIN;
    const short MAX_LABEL_WIDTH = GetMaxWidth(labelList);
    const short WIDTH = MAX_LABEL_WIDTH * 2 + PADDING;
    const std::pair<short, short> CENTER = CalcCenter(WIDTH, HEIGHT);

    View::DrawRect(
        {CENTER.second,
         CENTER.first,
         CENTER.first + WIDTH,
         CENTER.second + HEIGHT}
    );

    for (size_t i = 0; i < labelList.size(); ++i) {
        View::WriteToView(
            CENTER.first + 2,
            CENTER.second + 1 + i * MARGIN,
            labelList[i],
            0,
            false,
            Theme::GetColor(ThemeColor::TITLE_TEXT_COLOR)

        );
        View::WriteToView(
            CENTER.first + 2 + labelList[i].size() + 1,
            CENTER.second + 1 + i * MARGIN,
            inputList[i],
            0
        );
    }

    Label::DrawLabelCenter(
        CENTER.first,
        CENTER.first + WIDTH,
        CENTER.first,
        CENTER.second + HEIGHT + 1,
        Language::GetString(L"MAX_NAME_LENGTH_NOTICE") +
            std::format(L" {}", maxLength)
    );

    auto tmp = View::Input(
        CENTER.first + 2,
        CENTER.second + 1 + selected * MARGIN,
        labelList[selected],
        inputList[selected],
        1,
        [&](std::wstring newInp) {
            if (newInp.size() > maxLength) return;
            inputList[selected] = newInp;
        },
        View::defaultToogleFocus,
        L'\0'
    );

    switch (tmp) {
        case L'\r':
            if (inputList[selected].size() != 0) selected++;
            return true;
        case L'\t':
            selected = Utils::modCycle(selected + 1, labelList.size());
            return true;
        case L'\x1b':
            return false;

    }
}

#include "InputBox.h"

#include <format>

#include "Label.h"

std::pair<short, short> InputBox::CalcCenter(short width, short height)
{
    return {59 - width / 2, 14 - height / 2};
}

short InputBox::GetMaxWidth(LabelList labelList)
{
    short res = 0;
    std::for_each(labelList.begin(), labelList.end(), [&res](const auto& elem) {
        res = max(res, elem.length());
    });
    return res;
}

void InputBox::DrawInputBox(
    LabelList labelList, size_t &selected, InputList &inputList,
    bool maxReached, short maxLength
) {
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
            0
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
        std::format(L"Username must have a maximum length of {}", maxLength)
    );

    auto tmp = View::Input(
        CENTER.first + 2,
        CENTER.second + 1 + selected * MARGIN,
        labelList[selected],
        inputList[selected],
        1,
        [&](std::wstring newInp) { 
            if (newInp.size() > 10) return;
            inputList[selected] = newInp; 
        }
    );
    
    switch (tmp) {
        case L'\r':
            if (labelList[selected].size() != 0) selected++;
            break;
        case L'\t':
            selected = Utils::modCycle(selected + 1, labelList.size());
            break;
    }



    /* View::WriteToView(
        CENTER.first + 3 + MAX_LABEL_WIDTH,
        CENTER.second + 1 + selected * MARGIN, curInput + L" \b"
    );*/

    

    // View::Goto(CENTER.first + 3 + MAX_LABEL_WIDTH, CENTER.second + 1 +
    // selected * MARGIN);
}

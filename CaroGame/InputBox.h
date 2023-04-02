#pragma once
#include <string>
#include <vector>

#include "Label.h"
#include "Language.h"
#include "View.h"

namespace InputBox {

    typedef std::vector<std::wstring> LabelList, InputList;

    std::pair<short, short> CalcCenter(short width, short height);

    short GetMaxWidth(InputBox::LabelList labelList);

    void DrawInputBox(
        LabelList labelList,
        size_t& selected,
        InputList& inputList,
        bool maxReached = false,
        short maxLength = 0
    );
}  // namespace InputBox

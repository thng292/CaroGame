#pragma once
#include <string>
#include <vector>

#include "View.h"

namespace InputBox {

    typedef std::vector<std::wstring> LabelList;

    std::pair<short, short> CalcCenter(short width, short height);

    short GetMaxWidth(InputBox::LabelList labelList);

    void DrawInputBox(
        LabelList labelList, size_t selected, std::wstring curInput,
        bool maxReached = false, short maxLength = 0
    );
}  // namespace InputBox

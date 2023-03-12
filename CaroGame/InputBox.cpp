#include <format>
#include "InputBox.h"
#include "Label.h"

std::pair<short, short> InputBox::CalcCenter(short width, short height) {
	return { 59 - width / 2, 14 - height / 2 };
}

short InputBox::GetMaxWidth(LabelList labelList) {
	short res = 0;
	for (int i = 0; i < labelList.size(); ++i) {
		res = (res < labelList[i].length()) ? labelList[i].length() : res;
	}
	return res;
}

void InputBox::DrawInputBox(LabelList labelList, size_t selected, std::wstring curInput, bool maxReached, short maxLength)
{
	const short MARGIN = 2, PADDING = 2;
	const short HEIGHT = labelList.size() * MARGIN;
	const short MAX_LABEL_WIDTH = GetMaxWidth(labelList);
	const short WIDTH = MAX_LABEL_WIDTH * 2 + PADDING;
	const std::pair<short, short> CENTER = CalcCenter(WIDTH, HEIGHT);

	View::DrawRect({ CENTER.second, CENTER.first, CENTER.first + WIDTH, CENTER.second + HEIGHT });

	for (size_t i = 0; i < labelList.size(); ++i) {
		View::WriteToView(CENTER.first + 2, CENTER.second + 1 + i * MARGIN, labelList[i], 0, i == selected);
	}

	View::WriteToView(CENTER.first + 3 + MAX_LABEL_WIDTH, CENTER.second + 1 + selected * MARGIN, curInput + L" \b");

	Label::DrawLabelCenter(
		CENTER.first,
		CENTER.first + WIDTH,
		CENTER.first,
		CENTER.second + HEIGHT + 1,
		std::format(L"Username must have a maximum length of {}", maxLength));
	
	//View::Goto(CENTER.first + 3 + MAX_LABEL_WIDTH, CENTER.second + 1 + selected * MARGIN);
}

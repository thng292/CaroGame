#include "Label.h"
#include "View.h"

void Label::DrawLabel(const short& X, const short& Y, const std::wstring& VALUE)
{
	View::WriteToView(X, Y, VALUE);
}

void Label::DrawLabelCenter(const short& X_LEFT, const short& X_RIGHT, const short& X, const short& Y, const std::wstring& VALUE)
{
	const short X_CENTER = ((X_RIGHT - X_LEFT + 1) % 2 == 0) ? (X_RIGHT - X_LEFT - VALUE.size()) / 2 : (X_RIGHT - X_LEFT - VALUE.size()) / 2 + 1;
	DrawLabel(X + X_CENTER, Y, VALUE);
}

void Label::DrawLabelGrid(
	const short& X_LEFT,
	const short& X_RIGHT,
	const short& X,
	const short& Y,
	const std::vector<std::wstring>& VALUE_LIST,
	const short& COL_NUM)
{
	const short X_SPACE = (X_RIGHT - X_LEFT) / COL_NUM, Y_SPACE = 2;
	short ind = 0;
	const short LIST_LENGTH = VALUE_LIST.size();

	short row = 0, col = 0;
	while (ind < LIST_LENGTH) {
		DrawLabel(X + X_SPACE * col, Y + Y_SPACE * row, VALUE_LIST[ind]);
		ind++; col++;
		if (col >= COL_NUM) {
			row++;
			col = 0;
		}
	}
}

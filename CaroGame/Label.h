#pragma once

#include <string>
#include <vector>

namespace Label {
	void DrawLabel(const short& X, const short& Y, const std::wstring& VALUE);
	void DrawLabelCenter(const short& X_LEFT, const short& X_RIGHT, const short& X, const short& Y, const std::wstring& VALUE);
	void DrawLabelGrid(
		const short& X_LEFT,
		const short& X_RIGHT,
		const short& X,
		const short& Y,
		const std::vector<std::wstring>& VALUE_LIST,
		const short& COL_NUM);
}
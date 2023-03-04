#include "View.h"


void View::Setup() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	DWORD currMode;
	CONSOLE_FONT_INFOEX fontex;


	// Turn off maximize, resize, horizontal and vertical scrolling
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME) & ~(WS_HSCROLL) & ~(WS_VSCROLL);
	SetWindowLong(consoleWindow, GWL_STYLE, style);


	// Turn off mouse input
	GetConsoleMode(hOut, &currMode);
	SetConsoleMode(hOut,
		currMode & ~(ENABLE_MOUSE_INPUT) & ~(ENABLE_QUICK_EDIT_MODE));


	// Set font bold
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	wcscpy_s(fontex.FaceName, L"Consolas");
	fontex.FontWeight = 800;
	fontex.dwFontSize.X = 24;
	fontex.dwFontSize.Y = 24;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);


	// Update console title
	SetConsoleTitle(TEXT("Caro Game"));


	// Change color and clear screen
	ClearScreen();

	// Set IO Unicode
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);
}

void View::WriteToView(
	short x, short y, //Draw position
	const std::wstring& str,
	wchar_t shortcut, //Character want to underline
	bool highlight,
	View::Color textColor,
	View::Color highlightColor,
	View::Color highlightTextColor,
	View::Color backgroundColor
) {
	View::Goto(x, y);
	if (highlight) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			(int(highlightColor) << 4) | int(highlightTextColor));
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			(int(backgroundColor) << 4) | int(textColor));
	}
	if (shortcut) {
		int shortcutIndex = str.find_first_of(shortcut);
		std::wcout << str.substr(0, shortcutIndex) <<
			View::Underline(str[shortcutIndex]) <<
			str.substr(shortcutIndex + 1, str.length() - 1);
	}
	else {
		std::wcout << str;
	}
}

void View::WriteToView(
	short x, short y, //Draw position
	wchar_t str,
	bool highlight,
	View::Color textColor,
	View::Color highlightColor,
	View::Color highlightTextColor,
	View::Color backgroundColor
) {
	View::Goto(x, y);
	if (highlight) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			(int(highlightColor) << 4) | int(highlightTextColor));
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			(int(backgroundColor) << 4) | int(textColor));
	}
	std::wcout << str;
}

void View::ClearScreen() {
	DWORD tmp = 0;
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	FillConsoleOutputCharacter(StdOut, L' ', 120 * 30, { 0,0 }, &tmp);
	FillConsoleOutputAttribute(StdOut, DEFAULT_SCREEN_ATTRIBUTE, 120 * 30, { 0,0 }, &tmp);
}

void View::ClearRect(Rect area) {
	DWORD tmp = 0;
	auto stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	for (auto i = area.Top; i <= area.Bottom; i++)
	{
		FillConsoleOutputCharacter(stdHandle, L' ', area.Right - area.Left + 1,
			{ area.Left,i }, &tmp);
		FillConsoleOutputAttribute(stdHandle, DEFAULT_SCREEN_ATTRIBUTE,
			area.Right - area.Left + 1, { area.Left,i }, &tmp);
	}
}

void View::DrawRect(const Rect& rect, Color textColor, Color bgColor) {
	View::ClearRect(rect);
	View::WriteToView(rect.Left, rect.Top, L'\u2554');
	View::WriteToView(rect.Left, rect.Bottom, L'\u255A');
	View::WriteToView(rect.Right, rect.Top, L'\u2557');
	View::WriteToView(rect.Right, rect.Bottom, L'\u255D');
	DWORD tmp = 0;
	auto stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	FillConsoleOutputCharacter(stdHandle, L'\u2550',
		rect.Right - rect.Left - View::BORDER_WIDTH,
		{ rect.Left + View::BORDER_WIDTH, rect.Top },
		&tmp);
	FillConsoleOutputCharacter(stdHandle, L'\u2550',
		rect.Right - rect.Left - View::BORDER_WIDTH,
		{ rect.Left + View::BORDER_WIDTH, rect.Bottom },
		&tmp);
	for (int i = rect.Top + 1; i < rect.Bottom; i++)
	{
		View::WriteToView(rect.Left, i, L'\u2551');
		View::WriteToView(rect.Right, i, L'\u2551');
	}
}

inline short CalcWidth(const std::vector<View::Option>& options, const std::wstring& title) {
	int tmp = 0;
	for (auto i : options) {
		tmp = max(i.option.length(), tmp);
	}
	return max(tmp, title.length()) + (View::BORDER_WIDTH * View::HPADDING) * 2;
}

inline short CalcHeight(
	const std::vector<View::Option>& options,
	const std::wstring& title
) {
	return options.size() + (View::BORDER_WIDTH + View::VPADDING) * 2 +
		(title.length() ? 2 : 0);
}

inline std::pair<short, short> CalcCenter(
	short width, short height
) {
	return { 59 - width / 2, 14 - height / 2 };
}

void View::DrawMenu(
	short x, short y,
	const std::wstring& title,
	const std::vector<Option>& optionsList,
	size_t selected,
	Color textColor,
	Color highlightColor,
	Color highlightTextColor
) {
	short w = CalcWidth(optionsList, title);
	short h = CalcHeight(optionsList, title);
	View::DrawRect({ y, x, x + w, y + h - 1 });
	short leftAlign = View::BORDER_WIDTH + View::HPADDING + x;
	short topAlign = View::BORDER_WIDTH + View::VPADDING + y;
	if (title.length()) {
		View::WriteToView(leftAlign, topAlign, title);
		topAlign += 2;
	}
	for (int i = 0; i < optionsList.size(); i++) {
		View::WriteToView(leftAlign, topAlign + i,
			optionsList[i].option, optionsList[i].underline,
			selected == i);
	}
}

void View::DrawMenuCenter(
	std::wstring title,
	std::vector<Option> optionsList,
	size_t selected,
	Color textColor,
	Color highlightColor,
	Color highlightTextColor
) {
	short w = CalcWidth(optionsList, title);
	short h = CalcHeight(optionsList, title);
	auto tmp = CalcCenter(w, h);
	View::DrawMenu(tmp.first, tmp.second,
		title, optionsList, selected,
		textColor, highlightColor,
		highlightTextColor);
}

std::vector<std::wstring>
WrapText(
	const std::wstring& text,
	short maxRow, short maxWidth,
	const std::wstring& overflowStr = L"..."
) {
	std::vector<std::wstring> res;
	std::wistringstream iss(text);
	std::wstring tmp, buff;
	int cnt = 0;
	while (iss && cnt < maxRow) {
		res.emplace_back();
		if (buff.length()) {
			res[cnt].append(buff);
			res[cnt].append(L" ");
			buff = L"";
		}
		while (iss) {
			iss >> tmp;
			if (res[cnt].length() + tmp.length() + 1 <= maxWidth) {
				res[cnt].append(tmp);
				res[cnt].append(L" ");
			}
			else {
				buff = tmp;
				break;
			}
		};
		cnt++;
	}
	if (iss) {
		if (res.back().length() <= maxWidth - 3) {
			res.back().append(overflowStr);
		}
		else {
			std::wstring& t = res.back();
			t.resize(maxWidth);
			t[maxWidth - 1] = t[maxWidth - 2] = t[maxWidth - 3] = L'.';
		}
	}
	return res;
}

void View::DrawTextWrapped(
	short x, short y,
	const std::wstring& text,
	short maxRow, short maxWidth,
	const std::wstring& overflowStr,
	Color textColor
) {
	auto wrappedText = WrapText(text, maxRow, maxWidth, overflowStr);
	int n = wrappedText.size();
	for (size_t i = 0; i < n; i++)
	{
		WriteToView(x, y + i, wrappedText[i], 0, false, textColor);
	}
}

void View::DrawTextCenterdVertically(short y, const std::wstring& text, Color textColor) {
	WriteToView((119 - text.size()) / 2, y, text, 0, 0, textColor);
}
#include "Navigate.h"
#include "View.h"

NavigationHost::NavigationHost(std::string Start, std::unordered_map<std::string, std::function<void(NavigationHost&)>> links) {
	_CurrentScreen = { Start, nullptr };
	_Links = links;
	while (_CurrentScreen.name != EXIT) {
		_Links[_CurrentScreen.name](*this);
	}
}

void NavigationHost::Add(std::string path, std::function<std::string(NavigationHost&)> view) {
	_Links[path] = view;
}
void NavigationHost::HistoryPop() {
	delete[] _History.top().prevScreenBuffer;
	_History.pop();
}

void NavigationHost::NavigateStack(std::string path) {
	// Save current screen
	HANDLE StdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	PCHAR_INFO buffer = new CHAR_INFO[CONSOLE_WIDTH * CONSOLE_HEIGHT];
	SMALL_RECT readRegion = { 0,0,119,29 };
	ReadConsoleOutput(StdHandle, buffer, { 120, 30 }, { 0,0 }, &readRegion);
	_History.push(_CurrentScreen);
	_CurrentScreen = { path, buffer };
}

void NavigationHost::Navigate(std::string path) {
	HistoryPopAllOverlay();
	_History.push(_CurrentScreen);
	_CurrentScreen = { path, nullptr };
	View::ClearScreen();
}

void NavigationHost::Back() {
	if (_History.empty()) {
		_CurrentScreen = { EXIT, nullptr };
		return;
	}
	View::ClearScreen();
	if (_CurrentScreen.prevScreenBuffer != nullptr) {
		SMALL_RECT tmp = { 0,0,CONSOLE_WIDTH - 1,CONSOLE_HEIGHT - 1 };
		WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), _CurrentScreen.prevScreenBuffer, { CONSOLE_WIDTH, CONSOLE_HEIGHT }, { 0,0 }, &tmp);
		delete[] _CurrentScreen.prevScreenBuffer;
	}
	_CurrentScreen = _History.top();
	_History.pop();
}

NavigationHost::~NavigationHost() {
	delete[] _CurrentScreen.prevScreenBuffer;
	while (!_History.empty())
	{
		HistoryPop();
	}
}

void NavigationHost::HistoryPopAllOverlay() {
	while (_History.top().prevScreenBuffer != nullptr) {
		HistoryPop();
	}
}
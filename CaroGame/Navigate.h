#pragma once
#include <unordered_map>
#include <conio.h>
#include <stack>
#include <functional>
#include <string>
#include <Windows.h>
#define ViewFunc std::function<void(NavigationHost&)>
#define ViewFuncMap std::unordered_map<std::string, ViewFunc>

const int CONSOLE_WIDTH = 120;
const int CONSOLE_HEIGHT = 30;
const std::string EXIT = "EXITCODE";

class NavigationHost {
private:
	struct Screen {
		std::string name;
		PCHAR_INFO prevScreenBuffer = nullptr;
	};
	Screen _CurrentScreen;
	ViewFuncMap _Links;
	std::stack<Screen> _History;
	void HistoryPop();
	void HistoryPopAllOverlay();
public:
	NavigationHost(const std::string& Start, const ViewFuncMap& links);
	void Add(const std::string& path, const ViewFunc& view);
	[[nodiscard]] void NavigateStack(const std::string& path);
	[[nodiscard]] void Navigate(const std::string& path);
	[[nodiscard]] void Back();
	[[nodiscard]] void BackToLastNotOverlay();
	[[nodiscard]] void NavigateExit();
	~NavigationHost();
};
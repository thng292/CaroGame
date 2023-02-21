#pragma once
#include <unordered_map>
#include <conio.h>
#include <stack>
#include <functional>
#include <string>
#include <Windows.h>

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
	std::unordered_map<std::string, std::function<void(NavigationHost&)>> _Links;
	std::stack<Screen> _History;
	void HistoryPop();
	void HistoryPopAllOverlay();
public:
	NavigationHost(std::string Start, std::unordered_map<std::string, std::function<void(NavigationHost&)>> links);
	void Add(std::string path, std::function<std::string(NavigationHost&)> view);
	[[nodiscard]] void NavigateStack(std::string path);
	[[nodiscard]] void Navigate(std::string path);
	[[nodiscard]] void Back();
	[[nodiscard]] void BackToLastNotOverlay();
	[[nodiscard]] void NavigateExit();
	~NavigationHost();
};
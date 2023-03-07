#pragma once
#include <unordered_map>
#include <conio.h>
#include <stack>
#include <functional>
#include <string>
#include <any>
#include <Windows.h>
#include "View.h"
#include "InputHandle.h"


#ifndef ViewFunc
	#define ViewFunc std::function<void(NavigationHost&)>
#endif
#ifndef ViewFuncMap
	#define ViewFuncMap std::unordered_map<std::string, ViewFunc>
#endif

namespace Navigate {
	const int CONSOLE_WIDTH = 120;
	const int CONSOLE_HEIGHT = 30;
	const std::string EXIT = "EXITCODE";
}

class NavigationHost {
private:
	struct Screen {
		std::string name;
		PCHAR_INFO prevScreenBuffer = nullptr;
	};
	Screen _CurrentScreen;
	std::unordered_map<std::string, std::any> Context;
	ViewFuncMap _Links;
	std::stack<Screen> _History;
	void HistoryPop();
	void HistoryPopAllOverlay();
	void Draw404(NavigationHost& NavHost);
public:
	NavigationHost(const std::string& Start, const ViewFuncMap& links);
	std::any& GetFromContext(const std::string& name);
	void SetContext(const std::string& name, const std::any& data);
	void DeleteContext(const std::string& name);
	void Add(const std::string& path, const ViewFunc& view);
	void NavigateStack(const std::string& path);
	void Navigate(const std::string& path);
	void Back();
	void BackToLastNotOverlay();
	void NavigateExit();
	~NavigationHost();
};
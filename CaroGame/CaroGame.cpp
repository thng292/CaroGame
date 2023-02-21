#include "View.h"
#include "InputHandle.h"
#include "Navigate.h"
#include <iostream>
#include <functional>
#include <string>
#include <Windows.h>

//DEMO PURPOSE ONLY
void TestView1(NavigationHost& NavHost) {
	View::DrawMenuCenter(L"This is a title!", { // Add support for shortcut
		{L"TEst", L'T'},
		{L"HelloWorld!", L'H'},
		{L"...", 0}
		}, 2);
	View::WriteToView(20, 20, L"HẾ lô quợt!", 0, true);
	auto tmp = InputHandle::Get();
	if (tmp == L"\r") {
		return NavHost.NavigateStack("TestView2");
	}
	if (tmp == L"b" || tmp == L"B") {
		return NavHost.Back();
	}
}

//DEMO PURPOSE ONLY
void TestView2(NavigationHost& NavHost) {
	View::WriteToView(20, 21, L"Test view 2", 0, true);
	auto tmp = InputHandle::Get();
	if (tmp == L"\r") {
		return NavHost.Navigate("TestView3");
	}
	if (tmp == L"b" || tmp == L"B") {
		return NavHost.Back();
	}
}

//DEMO PURPOSE ONLY
void TestView3(NavigationHost& NavHost) {
	View::WriteToView(20, 22, L"Test view 3", 0, true);
	auto tmp = InputHandle::Get();
	if (tmp == L"\r") {
		return NavHost.Navigate("TestView1");
	}
	if (tmp == L"b" || tmp == L"B") {
		return NavHost.BackToLastNotOverlay();
	}
}

//DEMO PURPOSE ONLY
int main() {
	View::Setup();							// Setting up the screen
	//View::WriteToView(0, 0, L"\u2016\uFF1DTets");

	// App start here
	NavigationHost NavHost("TestView1", {	// Initialize Navigation Host
		{"TestView1", TestView1},			// "TestView1 is the first view to be shown
		{"TestView2", TestView2},
		{"TestView3", TestView3}
		});
	//std::wcin.get();
}
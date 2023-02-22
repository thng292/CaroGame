﻿#include "View.h"
#include "InputHandle.h"
#include "Navigate.h"
#include <iostream>
#include <functional>
#include <string>
#include <Windows.h>

void ExitView(NavigationHost& NavHost) {
	static short selectedOption = 1;										// User option
	static const short maxOption = 2;										// Number of option
	while (1) {																// Main while loop
		View::DrawMenuCenter(L"Are you sure? ", {
			{L"YES", L'Y'},
			{L"NO :(", L'N'},
			}, selectedOption);
		auto tmp = InputHandle::Get();										// Get input from user
		// Input Handle
		// Normal Navigation
		if (tmp == L"w" || tmp == L"W") {
			selectedOption = (selectedOption - 1 + maxOption) % maxOption;	// Cycle effect
		}
		if (tmp == L"s" || tmp == L"S") {
			selectedOption = (selectedOption + 1) % maxOption;				// Cycle effect
		}
		// Shortcut
		if (tmp == L"Y") {
			return NavHost.NavigateExit();									// Nho return
		}
		if (tmp == L"N") {
			return NavHost.Back();											// Nho return
		}
		// Handle Select
		if (tmp == L"\r") {
			switch (selectedOption)
			{
			case 0:
				return NavHost.NavigateExit();								// Nho return
			case 1:
				return NavHost.Back();										// Nho return
			}
		}
	}
}

//DEMO PURPOSE ONLY
void TestView1(NavigationHost& NavHost) {
	static short selectedOption = 0;										// User option
	static const short maxOption = 3;										// Number of option
	while (1) {																// Main while loop
		View::DrawMenuCenter(L"This is a title!", {
			{L"TestView2", L'2'},
			{L"TestView3", L'3'},
			{L"Exit", L'E'}
			}, selectedOption);
		auto tmp = InputHandle::Get();										// Get input from user
		// Input Handle
		// Normal Navigation
		if (tmp == L"w" || tmp == L"W") {
			selectedOption = (selectedOption - 1 + maxOption) % maxOption;	// Cycle effect
		}
		if (tmp == L"s" || tmp == L"S") {
			selectedOption = (selectedOption + 1) % maxOption;				// Cycle effect
		}
		// Shortcut
		if (tmp == L"2") {
			return NavHost.Navigate("TestView2");							// Nho return
		}
		if (tmp == L"3") {
			return NavHost.Navigate("TestView3");							// Nho return
		}
		if (tmp == L"e" || tmp == L"E") {
			return NavHost.NavigateStack("ExitView");						// Nho return
		}
		// Handle Select
		if (tmp == L"\r") {
			switch (selectedOption)
			{
			case 0:
				return NavHost.Navigate("TestView2");						// Nho return
			case 1:
				return NavHost.Navigate("TestView3");						// Nho return
			case 2:
				return NavHost.NavigateStack("ExitView");					// Nho return
			}
		}
	}
}

//DEMO PURPOSE ONLY
void TestView2(NavigationHost& NavHost) {
	View::WriteToView(20, 21, L"Test view 2", 0, true);
	View::WriteToView(20, 21, L"Enter to go back", 0, true);
	auto tmp = InputHandle::Get();
	/*if (tmp == L"\r") {
		return NavHost.Navigate("TestView3");
	}*/
	if (tmp == L"\r") {
		return NavHost.Back();
	}
}

//DEMO PURPOSE ONLY
void TestView3(NavigationHost& NavHost) {
	View::WriteToView(20, 22, L"Test view 3", 0, true);
	View::WriteToView(20, 21, L"Enter to go back", 0, true);
	auto tmp = InputHandle::Get();
	if (tmp == L"\r") {
		return NavHost.Back();
	}
}

//DEMO PURPOSE ONLY
int main() {
	View::Setup();							// Setting up the screen
	// App start here
	NavigationHost NavHost("TestView1",		// Initialize Navigation Host. "TestView1 is the first view to be shown
		{	
			{"TestView1", TestView1},		// Register TestView1
			{"TestView2", TestView2},		// Register TestView2
			{"TestView3", TestView3},		// Register TestView3
			{"ExitView", ExitView}			// Register ExitView
		}
	);
}
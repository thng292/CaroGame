#pragma once
#include "View.h"

class Container {
public:
	short xOffset, yOffset;
	short xCoord, yCoord, cellWidth, cellHeight;
	void DrawContainer();
	void DrawToContainer(std::wstring value);
};
#pragma once
#include "Constants.h"
#include "View.h"

class Container {
public:
	short xCoord, yCoord;
	void DrawContainer(short cellWidth, short cellHeight);
	void DrawToContainer(short xOffset, short yOffset,std::wstring value);
};
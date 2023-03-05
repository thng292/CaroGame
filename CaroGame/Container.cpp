#include "Container.h"

//Container::Container(short x, short y)
//{
//	xCoord = x;
//	yCoord = y;
//}

void Container::DrawContainer(short cellWidth, short cellHeight)
{
	View::Rect rect = { yCoord, xCoord, xCoord + cellWidth ,yCoord + cellHeight};
	View::DrawRect(rect);
}

void Container::DrawToContainer(short xOffset, short yOffset, std::wstring value)
{
	View::WriteToView(xCoord + xOffset, yCoord + yOffset, value);

}

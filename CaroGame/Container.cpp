#include "Container.h"

void Container::DrawContainer()
{
	View::Rect rect = { yCoord, xCoord, xCoord + cellWidth ,yCoord + cellHeight };
	View::DrawRect(rect);
}

void Container::DrawToContainer(std::wstring value)
{
	View::WriteToView(xCoord + xOffset, yCoord + yOffset, value);

}

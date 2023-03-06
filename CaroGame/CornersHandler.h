#pragma once

#include "Container.h"

namespace CornersHandler {
	void FixBoardCorners(short x, short y);
	void FixStatusBarCorners(
		short x,
		short y,
		const Container& timerContainer,
		const Container& winCountContainer,
		const Container& playerContainer);
	void FixPlayerInfoCorners(
		short x,
		short y,
		const Container& playerInfoContainer);
}
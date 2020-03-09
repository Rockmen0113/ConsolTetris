#pragma once

#include "BaseApp.h"
#include "Tetromino.h"
#include "Position.h"

class CollisionDetection
{
private:
	// Reference to BaseApp, used to find chars
	BaseApp *m_App;
public:
	CollisionDetection() = delete;
	CollisionDetection(BaseApp *app);

	// Return true, if detects any symbols, that not equal to exeptSymbol, in selected position.
	bool CollisionDetected(Tetromino &tetromino, Position &nextPosition, int nextRotation, wchar_t exceptSymbol);
};
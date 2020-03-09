#include "CollisionDetection.h"

CollisionDetection::CollisionDetection(BaseApp *app)
{
	m_App = app;
}

bool CollisionDetection::CollisionDetected(Tetromino &tetromino, Position &nextPosition, int rotationIndex, wchar_t exceptSymbol)
{
	int nextX;
	int nextY;

	int currentX;
	int currentY;
	bool isSameTetromino;

	tetromino.Rotate(rotationIndex);
	for (int i = 0; i < 4; i++)
	{
		nextX = tetromino.GetLocalPosition()[i].X + nextPosition.X;
		nextY = tetromino.GetLocalPosition()[i].Y + nextPosition.Y;
		isSameTetromino = false;
		for (int z = 0; z < 4; z++)
		{
			currentX = tetromino.GetOldLocalPosition()[z].X + tetromino.GetGlobalPosition().X;
			currentY = tetromino.GetOldLocalPosition()[z].Y + tetromino.GetGlobalPosition().Y;
			if (nextX == currentX && nextY == currentY)
			{
				isSameTetromino = true;
			}
		}
		if (m_App->GetChar(nextX, nextY) != exceptSymbol && !isSameTetromino)
		{
			tetromino.AbortRotation();
			return true;
		}
	}
	tetromino.AbortRotation();
	return false;
}

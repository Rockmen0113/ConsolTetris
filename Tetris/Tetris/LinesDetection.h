#pragma once

#include <vector>
#include "BaseApp.h"
#include "Tetromino.h"
#include "GameMap.h"
#include "Position.h"

class LinesDetection
{
private:
	wchar_t m_GameFieldBackground;

	// Set GameFieldBackground to detected line, using SetChar()
	void RemoveLine(BaseApp *app, GameMap *map, vector<int> lines);
	// Moves tetrominous down, that upper then lines.
	void MoveUpperTetromious(BaseApp *app, Tetromino *tetromino, GameMap *map, vector<int> lines);
public:
	// Return vector y positions of detected lines.
	vector<int> DetectLines(BaseApp *app, Tetromino *tetromino, GameMap *map);
};
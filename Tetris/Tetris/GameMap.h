#pragma once

#include <vector>
#include "IDrawable.h"
#include "Position.h"

class GameMap : public IDrawable
{
private:
	// Unicode symbols, used to draw walls
	enum m_Walls
	{
		TopLeftCorner = 9556,		// Corners
		TopRightCorner = 9559,
		BotLeftCorner = 9562,
		BotRightCorner = 9565,

		UpAndDownLine = 9552,		// Side Lines
		LeftAndRightLine = 9553,

		LeftThreeWayLine = 9568,	// Three Way Lines
		RightThreeWayLine = 9571,
		TopThreeWayLine = 9574,
		BottomThreeWayLine = 9577
	};

	// Unicode symbol, used to draw game field background.
	wchar_t m_GameFieldShape = '.';

	// Width for statistics window.
	int m_StatisticsFieldWidth = 22;
	// Height for statistics window.
	int m_StatisticsFieldHeight = 3;

	// Width for preview field window.
	int m_FigurePreviewFieldWidth = 6;
	// Height for preview field window.
	int m_FigurePreviewFieldHeight = 20;

	// Width for game field window.
	int m_GameFieldWidth = 15;
	// Height for preview field window.
	int m_GameFieldHeight = 20;

	// Current drawing position.
	Position m_DrawPosition;
public:
	GameMap();

	// Return GameFieldWidth.
	int GetGameFieldWidth();
	// Return GameFieldHeight.
	int GetGameFieldHeight();

	// Return FigurePreviewWidth.
	int GetFigurePreviewFieldWidth();
	// Return FigurePreviewHeight.
	int GetFigurePreviewFieldHeight();

	// Return StatisticsFieldWidth.
	int GetStatisticsFieldWidth();
	// Return StatisticsFieldHeight.
	int GetStatisticsFieldHeight();

	// Return GameFieldShape.
	wchar_t GetGameFieldShape();

	// Draw map, using Position
	void Draw(BaseApp *app) override;
};
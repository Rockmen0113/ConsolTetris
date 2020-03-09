#pragma once

#include "IDrawable.h"
#include "Position.h"

class TetrominoPreview : public IDrawable
{
private:
	// X and Y positions.
	Position m_Position;

	// Width of drawing cell.
	int m_FieldWidth;
	// Height of drawing cell.
	int m_FieldHeight;

	// This variable index, used to select figure from array.
	int m_NextFigure;

	// Tetromino local positions.
	vector<Position> m_LocalPosition;
	// Tetromino 4x4.
	vector<wstring> m_FigureArray;

	// Unicode symbol, used to draw tetromino.
	wchar_t m_Shape;

public:
	TetrominoPreview() = delete;
	TetrominoPreview(Position position, int width, int height, wchar_t shape, vector<wstring> figures);

	// Return NextFigure.
	int GetNextFigure();

	// Set NextFigure. Range 0 - 6.
	void SetNextFigure(int nextFigure);

	// Drawing tetromino, using positions.
	void Draw(BaseApp *app) override;
};
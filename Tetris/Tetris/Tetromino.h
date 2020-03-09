#pragma once

#include <vector>
#include "BaseApp.h"
#include "Position.h"
#include "RandomGenerator.h"

class Tetromino
{
private:
	vector<wstring> m_FigureArray	// Tetrominos 4x4
	{
		(L"..X...X...X...X."),	// |
		(L"..X..XX...X....."),	// T
		(L".....XX..XX....."),	// []
		(L"..X..XX..X......"),	// right curved
		(L".X...XX...X....."),	// left curved
		(L".X...X...XX....."),	// <-r
		(L"..X...X..XX.....")	// r->
	};

	// Random generator, used to generate figures. 0-6 range.
	RandomGenerator m_FigureGenerator;

	// This variables are indexes, used to select figure from array. 0-6 range. 
	int m_SelectedFigure;
	int m_NextFigure;

	// This variables are rotation indexes. 0-3 range.
	int m_CurrentRotation;
	int m_OldRotation;

	// Default start position
	Position const m_TetrominoStartPosition;
	int const m_TetrominoStartRotation;

	// Stores new local positions.
	void RefreshLocalPositions();
protected:

	// Unicode symbol, used to draw tetromino.
	wchar_t m_Shape = 9608;
	
	// X and Y tetromino position.
	Position m_CurrentPosition;
	Position m_OldPosition;

	// Local X and Y tetromino position.
	std::vector<Position> m_LocalPosition;
	std::vector<Position> m_OldLocalPosition;
public:
	Tetromino();

	// Return Shape.
	wchar_t GetShape() const;
	// Return FigureArray.
	vector<wstring> GetFigureArray();
	
	// Return CurrentRotation.
	int GetRotation() const;
	// Return NextFigure.
	int GetNextFigure() const;

	// Return CurrentPosition.
	Position GetGlobalPosition() const;

	// Return LocalPosition vector.
	std::vector<Position> GetLocalPosition() const;
	std::vector<Position> GetOldLocalPosition() const;

	// + 1 to CurrentRotation and refresh local positions.
	void Rotate();
	// Set value to CurrentRotation 0 - 3 range.
	void Rotate(int rotationIndex);
	// Set CurrentRotation to OldRotation.
	void AbortRotation();
	// Return index of next element, after rotation, for 4x4 array.
	int RotationIndex(Position position, int rotation) const;

	// Add to X -1 if true, else +1.
	void Move(bool isLeftDirection);
	// + 1 to Y position
	void MoveDown();

	// Generate NextFigure. Reset all positions to default values.
	void SpawnNewTetromino(BaseApp *app);
};
#include "Tetromino.h"

Tetromino::Tetromino() : m_TetrominoStartPosition(7, 1), m_CurrentPosition(m_TetrominoStartPosition),
m_OldPosition(m_CurrentPosition), m_FigureGenerator(0, 6), m_TetrominoStartRotation(0)
{
	m_CurrentRotation = m_TetrominoStartRotation;
	m_SelectedFigure = m_FigureGenerator.GenerateNewNumber();
	m_NextFigure = m_FigureGenerator.GenerateNewNumber();
	RefreshLocalPositions();
}

wchar_t Tetromino::GetShape() const
{
	return m_Shape;
}

vector<wstring> Tetromino::GetFigureArray()
{
	return m_FigureArray;
}

int Tetromino::GetRotation() const
{
	return m_CurrentRotation;
}

int Tetromino::GetNextFigure() const
{
	return m_NextFigure;
}

Position Tetromino::GetGlobalPosition() const
{
	return m_CurrentPosition;
}

std::vector<Position> Tetromino::GetOldLocalPosition() const
{
	return m_OldLocalPosition;
}

std::vector<Position> Tetromino::GetLocalPosition() const
{
	return m_LocalPosition;
}

void Tetromino::Move(bool isLeftDirection)
{
	if (isLeftDirection)
	{
		m_CurrentPosition.X--;
	}
	else if (!isLeftDirection)
	{
		m_CurrentPosition.X++;
	}
}

void Tetromino::MoveDown()
{

	m_CurrentPosition.Y++;
}

void Tetromino::Rotate()
{
	m_CurrentRotation += 1;
	if (m_CurrentRotation == 4)
	{
		m_CurrentRotation = 0;
	}

	RefreshLocalPositions();
}

void Tetromino::Rotate(int rotationIndex)
{
	m_OldRotation = m_CurrentRotation;
	m_CurrentRotation = rotationIndex;

	RefreshLocalPositions();
}

void Tetromino::AbortRotation()
{
	if (m_OldLocalPosition.size() != 0 && m_LocalPosition.size() != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			m_LocalPosition[i] = m_OldLocalPosition[i];
		}
	}

	m_CurrentRotation = m_OldRotation;
}

void Tetromino::RefreshLocalPositions()
{
	if (m_LocalPosition.size() != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			m_OldLocalPosition[i] = m_LocalPosition[i];
		}

		m_LocalPosition.clear();
	}


	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (m_FigureArray[m_SelectedFigure][RotationIndex(Position(x, y), m_CurrentRotation)] != '.')
			{
				m_LocalPosition.push_back(Position(x, y));
			}
		}
	}
}

int Tetromino::RotationIndex(Position position, int rotation) const
{
	int cellIndex = 0;
	switch (rotation % 4)
	{
	case 0: // 0 degrees			
		cellIndex = position.Y * 4 + position.X;
		break;

	case 1: // 90 degrees			
		cellIndex = 12 + position.Y - (position.X * 4);
		break;

	case 2: // 180 degrees			
		cellIndex = 15 - (position.Y * 4) - position.X;
		break;

	case 3: // 270 degrees			
		cellIndex = 3 - position.Y + (position.X * 4);
		break;
	}

	return cellIndex;
}

void Tetromino::SpawnNewTetromino(BaseApp *app)
{
	m_CurrentRotation = m_TetrominoStartRotation;
	m_CurrentPosition = m_TetrominoStartPosition;
	m_OldPosition = m_TetrominoStartPosition;

	m_LocalPosition.clear();

	m_SelectedFigure = m_NextFigure;
	m_NextFigure = m_FigureGenerator.GenerateNewNumber();

	RefreshLocalPositions();

	m_OldLocalPosition = m_LocalPosition;
}



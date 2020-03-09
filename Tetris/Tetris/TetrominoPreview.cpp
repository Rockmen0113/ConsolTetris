#include "TetrominoPreview.h"

TetrominoPreview::TetrominoPreview(Position position, int width, int height, wchar_t shape, vector<wstring> figures)
{
	m_Position = position;
	m_FieldWidth = width;
	m_FieldHeight = height;
	m_Shape = shape;
	m_FigureArray = figures;

	m_NextFigure = 0;
}

int TetrominoPreview::GetNextFigure()
{
	return m_NextFigure;
}

void TetrominoPreview::SetNextFigure(int nextFigure)
{
	if (nextFigure >= 0 && nextFigure < 7)
	{
		m_NextFigure = nextFigure;
	}
}

void TetrominoPreview::Draw(BaseApp *app)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (m_FigureArray[m_NextFigure][y * 4 + x] != '.')
			{
				m_LocalPosition.push_back(Position(x, y));
			}
		}
	}

	for (int x = m_Position.X; x < m_Position.X + m_FieldWidth - 1; x++)
	{
		for (int y = m_Position.Y; y < m_Position.Y + m_FieldHeight - 1; y++)
		{
			app->SetChar(x, y, ' ');
		}
	}

	for (int i = 0; i < 4; i++)
	{
		app->SetChar(m_Position.X + m_LocalPosition[i].X, m_Position.Y + m_LocalPosition[i].Y, m_Shape);
	}
	m_LocalPosition.clear();
}


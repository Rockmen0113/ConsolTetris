#include "GameMap.h"

GameMap::GameMap()
{
}


int GameMap::GetGameFieldWidth()
{
	return m_GameFieldWidth;
}

int GameMap::GetGameFieldHeight()
{
	return m_GameFieldHeight;
}

int GameMap::GetFigurePreviewFieldWidth()
{
	return m_FigurePreviewFieldWidth;
}

int GameMap::GetFigurePreviewFieldHeight()
{
	return m_FigurePreviewFieldHeight;
}

int GameMap::GetStatisticsFieldWidth()
{
	return m_StatisticsFieldWidth;
}

int GameMap::GetStatisticsFieldHeight()
{
	return m_StatisticsFieldHeight;
}

wchar_t GameMap::GetGameFieldShape()
{
	return m_GameFieldShape;
}

void GameMap::Draw(BaseApp *app)
{
	wchar_t drawShape;

	//walls offset
	int offset = 3;

	int drawHeight = m_GameFieldHeight + m_StatisticsFieldHeight + offset;
	int drawWidth = m_GameFieldWidth + m_FigurePreviewFieldWidth + offset;

	for (; m_DrawPosition.Y < drawHeight; m_DrawPosition.Y++)
	{
		for (; m_DrawPosition.X < drawWidth; m_DrawPosition.X++)
		{
			if (m_DrawPosition.X <= m_GameFieldWidth && m_DrawPosition.Y <= m_GameFieldHeight)
			{
				drawShape = m_GameFieldShape;
			}
			else
			{
				drawShape = ' ';
			}

			if (m_DrawPosition.X < drawWidth && (m_DrawPosition.Y == 0 || m_DrawPosition.Y == drawHeight - 1 ||
				m_DrawPosition.Y == m_GameFieldHeight + 1))
			{
				drawShape = UpAndDownLine;
			}
			else if (m_DrawPosition.Y < drawHeight && (m_DrawPosition.X == 0 || m_DrawPosition.X == drawWidth - 1 ||
				(m_DrawPosition.X == m_GameFieldWidth + 1 && m_DrawPosition.Y < m_GameFieldHeight + 1)))
			{
				drawShape = LeftAndRightLine;
			}

			if (m_DrawPosition.Y == 0)
			{
				if (m_DrawPosition.X == 0)
				{
					drawShape = TopLeftCorner;
				}
				else if (m_DrawPosition.X == drawWidth - 1)
				{
					drawShape = TopRightCorner;
				}
				else if (m_DrawPosition.X == m_GameFieldWidth + 1)
				{
					drawShape = TopThreeWayLine;
				}
			}
			else if (m_DrawPosition.Y == drawHeight - 1)
			{
				if (m_DrawPosition.X == 0)
				{
					drawShape = BotLeftCorner;
				}
				else if (m_DrawPosition.X == drawWidth - 1)
				{
					drawShape = BotRightCorner;
				}
			}
			else if (m_DrawPosition.Y == m_GameFieldHeight + 1)
			{
				if (m_DrawPosition.X == 0)
				{
					drawShape = LeftThreeWayLine;
				}
				else if (m_DrawPosition.X == m_GameFieldWidth + 1)
				{
					drawShape = BottomThreeWayLine;
				}
				else if (m_DrawPosition.X == drawWidth - 1)
				{
					drawShape = RightThreeWayLine;
				}
			}

			app->SetChar(m_DrawPosition.X, m_DrawPosition.Y, drawShape);
		}
		m_DrawPosition.X = 0;
	}
	m_DrawPosition.Y = 0;
}
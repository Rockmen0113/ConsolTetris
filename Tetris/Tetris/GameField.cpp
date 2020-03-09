#include "GameField.h"

GameField::GameField()
{
}

void GameField::Draw(BaseApp *app)
{
	wchar_t drawShape = m_FillerShape;
	int drawHeight = m_Height + 2;
	int drawWidth = m_Width + 2;

	for (; m_DrawPosition.Y < drawHeight; m_DrawPosition.Y++)
	{
		for (; m_DrawPosition.X < drawWidth; m_DrawPosition.X++)
		{

			if (m_DrawPosition.X < drawWidth && (m_DrawPosition.Y == 0 || m_DrawPosition.Y == drawHeight - 1))
			{
				drawShape = UpAndDownLine;
			}
			else if (m_DrawPosition.Y < drawHeight && (m_DrawPosition.X == 0 || m_DrawPosition.X == drawWidth - 1))
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

			app->SetChar(m_DrawPosition.X, m_DrawPosition.Y, drawShape);
		}
		m_DrawPosition.X = 0;
	}
	m_DrawPosition.Y = 0;
}

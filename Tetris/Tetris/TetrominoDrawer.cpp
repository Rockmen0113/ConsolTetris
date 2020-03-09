#include "TetrominoDrawer.h"

void TetrominoDrawer::Draw(BaseApp *app)
{
	if (m_OldLocalPosition.size() != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			app->SetChar(m_OldPosition.X + m_OldLocalPosition[i].X, m_OldPosition.Y + m_OldLocalPosition[i].Y, '.');
		}
	}

	for (int i = 0; i < 4; i++)
	{
		app->SetChar(m_CurrentPosition.X + m_LocalPosition[i].X, m_CurrentPosition.Y + m_LocalPosition[i].Y, m_Shape);
		m_OldLocalPosition.push_back(m_LocalPosition[i]);
	}

	m_OldPosition = m_CurrentPosition;
}


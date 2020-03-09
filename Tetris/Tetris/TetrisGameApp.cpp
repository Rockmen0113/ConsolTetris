#include "TetrisGameApp.h"
#include <conio.h>

TetrisGameApp::TetrisGameApp() : BaseApp(23, 25), m_CollisionDetection(this),
m_Preview(Position(18, 2), m_Map.GetFigurePreviewFieldWidth(), m_Map.GetFigurePreviewFieldHeight(),
	m_Tetromino.GetShape(), m_Tetromino.GetFigureArray())
{
	m_Map.Draw(this);

	m_GameSpeed = 0.25;
	m_OldGameSpeed = m_GameSpeed;

	isFallingDown = false;
	isGameOver = false;

	m_Preview.SetNextFigure(m_Tetromino.GetNextFigure());
};

void TetrisGameApp::KeyPressed(int btnCode)
{
	if (!isFallingDown)
	{
		if (btnCode == 224)					// Service arrow keyCode
		{
			int tmpCode = getch();

			if (tmpCode == 75)				// Left arrow key
			{
				if (!m_CollisionDetection.CollisionDetected(m_Tetromino, m_Tetromino.GetGlobalPosition() - Position(1, 0),
					m_Tetromino.GetRotation(), m_Map.GetGameFieldShape()))
				{
					m_Tetromino.Move(true);
				}
			}
			else if (tmpCode == 77)			// Right arrow key
			{
				if (!m_CollisionDetection.CollisionDetected(m_Tetromino, m_Tetromino.GetGlobalPosition() + Position(1, 0),
					m_Tetromino.GetRotation(), m_Map.GetGameFieldShape()))
				{
					m_Tetromino.Move(false);
				}
			}
			else if (tmpCode == 80)			// Down arrow key
			{
				if (!m_CollisionDetection.CollisionDetected(m_Tetromino, m_Tetromino.GetGlobalPosition() + Position(0, 1),
					m_Tetromino.GetRotation(), m_Map.GetGameFieldShape()))
				{
					isFallingDown = true;
					m_OldGameSpeed = m_GameSpeed;
					m_GameSpeed /= 10;
				}
			}
		}
		else if (btnCode == 32)				// SpaceBar
		{
			if (!m_CollisionDetection.CollisionDetected(m_Tetromino, m_Tetromino.GetGlobalPosition() + Position(0, 0),
				m_Tetromino.GetRotation() + 1, m_Map.GetGameFieldShape()))
			{
				m_Tetromino.Rotate();
			}
		}
	}
}

void TetrisGameApp::UpdateF(float deltaTime)
{
	if (!isGameOver)
	{
		m_Score.Draw(this);
		m_Preview.Draw(this);
		m_Tetromino.Draw(this);

		if (m_Timer >= m_GameSpeed)
		{
			if (!m_CollisionDetection.CollisionDetected(m_Tetromino, m_Tetromino.GetGlobalPosition() + Position(0, 1),
				m_Tetromino.GetRotation(), m_Map.GetGameFieldShape()))
			{
				m_Tetromino.MoveDown();
			}
			else
			{
				isFallingDown = false;
				m_GameSpeed = m_OldGameSpeed;

				m_Score.SetScore(m_LinesDetection.DetectLines(this, &m_Tetromino, &m_Map).size() * 100 + m_Score.GetScore());

				m_Tetromino.SpawnNewTetromino(this);

				if (m_CollisionDetection.CollisionDetected(m_Tetromino, m_Tetromino.GetGlobalPosition() + Position(0, 1),
					m_Tetromino.GetRotation(), m_Map.GetGameFieldShape()))
				{
					m_GameOverMessage.Draw(this);
					isGameOver = true;
				}

				m_Preview.SetNextFigure(m_Tetromino.GetNextFigure());

			}
			m_Timer = 0;
		}

		m_Timer += deltaTime;
	}
}

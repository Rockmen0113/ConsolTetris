#include "Score.h"

Score::Score(): m_Position(3, 23)
{
}

int Score::GetScore()
{
	return m_Score;
}

void Score::SetScore(int score)
{
	m_Score = score;
}

Position Score::GetPosition()
{
	return m_Position;
}

void Score::SetPosition(Position position)
{
	m_Position = position;
}

void Score::Draw(BaseApp *app)
{
	wstring concatenatedScore = m_ScoreLabel + to_wstring(m_Score);

	int i = 0;
	for (auto element: concatenatedScore)
	{
		app->SetChar(m_Position.X + i, m_Position.Y, element);
		i++;
	}

}

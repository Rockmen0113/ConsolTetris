#include "GameOverMessage.h"

GameOverMessage::GameOverMessage(): m_Position(4, 10)
{
}

GameOverMessage::GameOverMessage(Position position): m_Position(position)
{
}

void GameOverMessage::Draw(BaseApp *app)
{
	int i = 0;
	for (auto element : m_GameOver)
	{
		app->SetChar(m_Position.X + i, m_Position.Y, element);
		i++;
	}
}

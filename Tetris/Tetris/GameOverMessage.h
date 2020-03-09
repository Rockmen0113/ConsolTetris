#pragma once

#include "IDrawable.h"
#include "Position.h"

class GameOverMessage : public IDrawable
{
private:
	// X and Y positions.
	Position m_Position;

	// Unicode preset
	wstring m_GameOver = L"Game Over!";
public:
	GameOverMessage();
	GameOverMessage(Position position);

	// Draw preset, unsing Position.
	void Draw(BaseApp *app) override;
};
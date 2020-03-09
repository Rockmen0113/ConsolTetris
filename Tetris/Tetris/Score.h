#pragma once
#include "BaseApp.h"
#include "IDrawable.h"
#include "Position.h"

class Score: public IDrawable
{
private:
	// Current score.
	int m_Score = 0;

	// X and Y positions.
	Position m_Position;
	// Unicode preset
	wstring const m_ScoreLabel = L"> Score: ";
public:
	Score();

	// Return Score.
	int GetScore();
	// Sets Score.
	void SetScore(int score);

	// Return Position.
	Position GetPosition();
	// Sets Position.
	void SetPosition(Position position);

	// Draw score, using Position.
	void Draw(BaseApp *app) override;
};
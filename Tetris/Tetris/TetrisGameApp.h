#pragma once

#include "BaseApp.h"
#include "GameMap.h"
#include "TetrominoDrawer.h"
#include "CollisionDetection.h"
#include "LinesDetection.h"
#include "Score.h"
#include "TetrominoPreview.h"
#include "GameOverMessage.h"

class TetrisGameApp : public BaseApp
{
private:
	GameMap m_Map;
	TetrominoDrawer m_Tetromino;
	TetrominoPreview m_Preview;
	CollisionDetection m_CollisionDetection;
	LinesDetection m_LinesDetection;
	GameOverMessage m_GameOverMessage;
	Score m_Score;

	// Timer, used to iterate in update method
	float m_Timer = 0;

	// Game speed. Lower value, faster speed
	float m_GameSpeed = 0;
	// Old game speed, to restore GameSpeed.
	float m_OldGameSpeed = 0;

	// True if tetromino falling down. It used to block keyinput and speedUp game.
	bool isFallingDown;
	// If true, block all methods in update method.
	bool isGameOver;
public:
	TetrisGameApp();

	void KeyPressed(int btnCode) override;
	void UpdateF(float deltaTime) override;
};
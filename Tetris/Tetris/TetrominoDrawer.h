#pragma once
#include "IDrawable.h"
#include "Tetromino.h"

class TetrominoDrawer :public IDrawable, public Tetromino
{
public:
	// Drawing tetromino, using tetromino positions.
	void Draw(BaseApp *app) override;
};
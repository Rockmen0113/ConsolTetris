#pragma once
#include "IField.h"

class GameField : public IField
{
private:
	int m_Width;
	int m_Height;

	Position m_DrawPosition;

	char m_FillerShape = '.';
public:
	GameField();
	void virtual Draw(BaseApp *app);
};
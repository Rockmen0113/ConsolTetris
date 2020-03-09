#pragma once
#include "IField.h"

class FigurePreviewField : public IField
{
private:
	int m_Width;
	int m_Height;
public:
	FigurePreviewField();
	void virtual Draw();
};
#pragma once
#include "IField.h"

class StatisticsField : public IField
{
private:
	int m_Width;
	int m_Height;
public:
	StatisticsField();
	void virtual Draw();
};
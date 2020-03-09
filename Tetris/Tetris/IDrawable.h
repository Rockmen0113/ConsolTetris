#pragma once
#include "BaseApp.h"

class IDrawable
{
	void virtual Draw(BaseApp *app) = 0;
};
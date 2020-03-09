#include "LinesDetection.h"

vector<int> LinesDetection::DetectLines(BaseApp *app, Tetromino *tetromino, GameMap *map)
{
	m_GameFieldBackground = map->GetGameFieldShape();

	vector<int> Lines;
	bool isFullLine;
	int y;
	for (int i = 0; i < 4; i++)
	{
		y = tetromino->GetLocalPosition()[i].Y + tetromino->GetGlobalPosition().Y;
		isFullLine = true;
		for (int x = 1; x <= map->GetGameFieldWidth(); x++)
		{
			if (app->GetChar(x, y) == m_GameFieldBackground)
			{
				isFullLine = false;
				break;
			}
		}

		for (auto element : Lines)
		{
			if (element == y)
			{
				isFullLine = false;
			}
		}

		if (isFullLine)
		{
			Lines.push_back(y);
		}
	}

	if (Lines.size() != 0)
	{
		RemoveLine(app, map, Lines);
		MoveUpperTetromious(app, tetromino, map, Lines);
	}

	return Lines;
}

void LinesDetection::RemoveLine(BaseApp *app, GameMap *map, vector<int> lines)
{
	for (auto element : lines)
	{
		for (int x = 1; x <= map->GetGameFieldWidth(); x++)
		{
			app->SetChar(x, element, m_GameFieldBackground);
		}
	}
}

void LinesDetection::MoveUpperTetromious(BaseApp *app, Tetromino *tetromino, GameMap *map, vector<int> lines)
{
	vector<Position> tetrominous;

	std::sort(lines.begin(), lines.end());

	for (int x = 1; x <= map->GetGameFieldWidth(); x++)
	{
		for (int y = 1; y <= lines.back(); y++)
		{
			if (app->GetChar(x, y) != m_GameFieldBackground)
			{
				tetrominous.push_back(Position(x, y));
			}
		}
	}

	for (auto element : tetrominous)
	{
		app->SetChar(element.X, element.Y, m_GameFieldBackground);
	}

	for (auto line : lines)
	{
		for (auto &element : tetrominous)
		{
			if (element.Y <= line)
			{
				element.Y += 1;
			}
		}
	}

	for (auto element : tetrominous)
	{
		app->SetChar(element.X, element.Y, tetromino->GetShape());
	}

}


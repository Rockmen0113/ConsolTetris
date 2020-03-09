#include "Position.h"

Position::Position() : X(0), Y(0)
{

};

Position::Position(int x, int y) : X(x), Y(y)
{

};


bool operator==(const Position &pos1, const Position &pos2)
{
	return (pos1.X == pos2.X
		&& pos1.Y == pos2.Y);
}

bool operator!=(const Position &pos1, const Position &pos2)
{
	return !(pos1 == pos2);
}

bool operator>(const Position & pos1, const Position & pos2)
{
	return (pos1.X > pos1.X && pos1.Y > pos1.Y);
}

bool operator>=(const Position & pos1, const Position & pos2)
{
	return (pos1.X >= pos1.X && pos1.Y >= pos1.Y);
}

bool operator<(const Position & pos1, const Position & pos2)
{
	return (pos1.X < pos1.X && pos1.Y < pos1.Y);
}

bool operator<=(const Position & pos1, const Position & pos2)
{
	return (pos1.X <= pos1.X && pos1.Y <= pos1.Y);
}

Position operator+(const Position & left, const Position & right)
{
	return Position(left.X + right.X, left.Y + right.Y);
}

Position operator-(const Position & left, const Position & right)
{
	return Position(left.X - right.X, left.Y - right.Y);
}

Position operator+=(Position & left, const Position & right)
{
	return Position(left.X += right.X, left.Y += right.Y);
}

Position operator-=(Position & left, const Position & right)
{
	return Position(left.X -= right.X, left.Y -= right.Y);
}



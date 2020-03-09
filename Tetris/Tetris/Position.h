#pragma once

class Position
{
public:
	int X;
	int Y;

	Position();

	Position(int X, int Y);

	friend bool operator== (const Position &pos1, const Position &pos2);
	friend bool operator!= (const Position &pos1, const Position &pos2);

	friend bool operator> (const Position &pos1, const Position &pos2);
	friend bool operator>= (const Position &pos1, const Position &pos2);

	friend bool operator< (const Position &pos1, const Position &pos2);
	friend bool operator<= (const Position &pos1, const Position &pos2);

	friend Position operator+(const Position& left, const Position& right);
	friend Position operator-(const Position& left, const Position& right);

	friend Position operator+=(Position& left, const Position& right);
	friend Position operator-=(Position& left, const Position& right);
};
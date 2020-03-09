#pragma once

#include <random>

class RandomGenerator
{
private:
	std::default_random_engine m_Generator;
	std::uniform_int_distribution<int> m_Distribution;
public:
	RandomGenerator();
	RandomGenerator(int rangeStart, int rangeEnd);

	// GenerateNumber with Distribution range.
	int GenerateNewNumber();
};
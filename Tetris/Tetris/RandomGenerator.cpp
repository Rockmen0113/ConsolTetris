#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(): m_Distribution(0, 10)
{
}

RandomGenerator::RandomGenerator(int rangeStart, int rangeEnd): m_Distribution(rangeStart, rangeEnd)
{
}

int RandomGenerator::GenerateNewNumber()
{
	return m_Distribution(m_Generator);
}

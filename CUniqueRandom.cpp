#include "CUniqueRandom.h"
#include <cstdlib>

int CUniqueRandom::getRandomNumber(int lower, int upper)
{
	int temp = (lower + (rand() % (upper - lower + 1)));

	if (checkPrevNum)
	{
		while (temp == prevNum)
		{
			temp = (lower + (rand() % (upper - lower + 1)));
		}
		prevNum = temp;
		return temp;
	}
	else
	{
		prevNum = temp;
		checkPrevNum = true;
		return temp;
	}

}
CUniqueRandom::CUniqueRandom() :prevNum(0), checkPrevNum(false)
{}
Array CUniqueRandom::getRandomSequence(int lower, int upper, int seqSize)
{
	if (seqSize == 0)
	{
		seqSize = (upper - lower + 1);

	}
	int ranN = getRandomNumber(lower, upper);
	Array temp(seqSize);
	for (int i = 0; i < seqSize; i++)
	{
		while (isMember(ranN, temp) && i < (upper - lower + 1))
		{
			ranN = getRandomNumber(lower, upper);
		}
		if (i >= (upper - lower + 1))
		{
			ranN = CRandom::getRandomNumber(lower, upper);
		}
		temp[i] = ranN;
	}
	return temp;
}
bool CUniqueRandom::isMember(int m, Array a)
{
	for (int i = 0; i < a.getCapacity(); i++)
	{
		if (a[i] == m)
		{
			return true;
		}

	}
	return false;
}
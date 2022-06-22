#include "CRandom.h"
#include <ctime>
#include <iostream>
using namespace std;
#include<cstdlib>
CRandom::CRandom()
{
	srand(time(0));
}
Array CRandom::getRandomSequence(int lower, int upper, int seqSize)
{
	if (seqSize == 0)
	{
		seqSize = (upper - lower + 1);

	}
	Array temp(seqSize);
	for (int i = 0; i < seqSize; i++)
	{
		temp[i] = getRandomNumber(lower, upper);
	}
	return temp;
}
void CRandom::shuffleArray(Array & ref)
{
	for (int i = 0; i < ref.getCapacity() - 1; i++)
	{
		swap(ref[i], ref[getRandomNumber(i, ref.getCapacity() - 1)]);
	}
}
void CRandom::swap(int &a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
	//temp = nullptr;
}
int CRandom::getRandomNumber(int lower, int upper)
{
	int temp = (lower + (rand() % (upper - lower + 1)));;
	return temp;

}

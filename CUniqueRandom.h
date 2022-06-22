#ifndef CUNIQUERANDOM_H
#define CUNIQUERANDOM_H
#include "CRandom.h"
class CUniqueRandom :public CRandom
{
	bool checkPrevNum;
	int prevNum;

public:
	CUniqueRandom();
	int getRandomNumber(int lower, int upper) override;
	Array getRandomSequence(int lower, int upper, int seqSize = 0) override;
	bool isMember(int m, Array a);
};



#endif
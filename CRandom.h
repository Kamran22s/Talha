#ifndef CRANDOM_H
#define CRANDOM_H
#include "Array.h"
class CRandom :public Array
{

public:
	CRandom();
	virtual Array getRandomSequence(int lower, int upper, int seqSize = 0);
	virtual void shuffleArray(Array & ref);
	virtual int getRandomNumber(int lower, int upper);
	void swap(int & a, int & b);
};


#endif // !CRANDOM_H

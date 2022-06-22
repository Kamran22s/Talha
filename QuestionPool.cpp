#include "QuestionPool.h"
#include "CUniqueRandom.h"

QuestionPool::QuestionPool(int cap ):capacity(cap),noOfQuestions(0)
{
	data = new Question*[cap];
}
void QuestionPool::addQuestion(const Question & q)
{
	data[noOfQuestions] = q.clone();
	noOfQuestions++;
}
void QuestionPool::generateQuiz(Quiz & ref, int questCount)
{
	CUniqueRandom temp;
	Array b(temp.getRandomSequence(1, noOfQuestions, questCount));

	Question **p=new Question*[questCount];
	for (int i = 0; i < questCount; i++)
	{
		int t = b[i];
		p[i] = data[t-1]->clone();
	}
	ref.populateQuiz(p, questCount);
}

int QuestionPool::getNumberOfQuestions()
{
	return noOfQuestions;
}
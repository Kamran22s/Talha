#ifndef QUESTIONPOOL_H
#define QUESTIONPOOL_H
#include "Quiz.h"
class QuestionPool
{
	Question * * data;
	int noOfQuestions;
	int capacity;
	
public:
	QuestionPool(int cap = 20);
	void addQuestion(const Question & q);
	void generateQuiz(Quiz &, int questCount);
	int getNumberOfQuestions();
};


#endif  
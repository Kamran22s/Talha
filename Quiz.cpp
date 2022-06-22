#include <iostream>
using namespace std;
#include "Quiz.h"

int Quiz::getObtainedMarks()
{
	for (int i = 0; i < noOfQuestions; i++)
	{
		if (data[i]->isCorrectAnswer(userAnswer[i]))
		{
			obtainedMarks += data[i]->getMarks();
		}
		
	}
	return obtainedMarks;
}

int Quiz::gertMaximumMarks()
{
	maximumMarks = 0;
	for (int i = 0; i < noOfQuestions; i++)
	{
		maximumMarks += data[i]->getMarks();
	}
	return maximumMarks;
}
void Quiz::setMaximumMarks(int m)
{
	maximumMarks = m;
}
void Quiz::populateQuiz(Question **p, int qCount)
{
	data = p;
	noOfQuestions = qCount;
}

void Quiz::setAnswerForCurrentQuestion(const String & ref)
{
	if (!userAnswer)
	{
		userAnswer = new String[noOfQuestions];
	}
	if (!isQuizFinished() )
	{
		userAnswer[currentQuestion ] = ref;
	}
	else
		return;
}
void Quiz::printQuiz()
{
	for (int i = 0; i < noOfQuestions; i++)
	{
		cout << i+1<<": ";
		data[i]->printQuestion();
		cout << endl;
	}
}
void Quiz::nextQuestion()
{
	currentQuestion++;
}
void Quiz::showCurrentQuestion()
{
	data[currentQuestion]->printQuestion();
}

bool Quiz::isQuizFinished()
{
	if (currentQuestion==noOfQuestions)
	{
		currentQuestion = 0;
		obtainedMarks = 0;
		return true;
	}
	else
		return false;

}
void Quiz::delayQuestion()
{
	int i = currentQuestion ;
	Question*p = data[currentQuestion];
	for (; i < noOfQuestions-1; i++)
	{
		data[i] = data[i + 1];
	}
	data[i] = p;
}
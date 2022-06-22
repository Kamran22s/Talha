#ifndef QUIZ_H
#define QUIZ_H
#include "Question.h"
class Quiz
{
	Question ** data;
	String * userAnswer;
	int obtainedMarks = 0;
	int maximumMarks=0;
	int noOfQuestions;
	int currentQuestion = 0;
	void markQuestion();
public:
	int getObtainedMarks();
	int gertMaximumMarks();
	void setMaximumMarks(int);
	void populateQuiz(Question **p, int qCount);
	void setAnswerForCurrentQuestion(const String &);
	void printQuiz();

	void nextQuestion();
	void showCurrentQuestion();
	bool isQuizFinished(); 
	void delayQuestion();


};


#endif // !QUIZ_H

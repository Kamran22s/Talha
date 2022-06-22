#ifndef QUESTION_H
#define QUESTION_H
#include "String.h"
class Question
{
	String question;
	int marks = 1;
public:
	void setQuestion(const String &, int m = 1);
	String getQuestion();
	int getMarks();
	void setMarks(int m);
    virtual bool isCorrectAnswer(const String &) = 0;
	virtual String getCorrectAnswer() = 0;
	virtual Question * clone() const =0;
	virtual void printQuestion() = 0;
	virtual void inputQuestion() = 0;
	
};


#endif
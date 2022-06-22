#ifndef MCQ_H
#define MCQ_H
#include "Question.h"
class MCQ:public Question
{
	String options[4];
	int correctOption;
public:
	bool isCorrectAnswer(const String &);
	void setOption(String &, int optNumber);
	void setCorrectAnswer(char opt);
	String getCorrectAnswer();
	Question * clone() const;
	void printQuestion();
	void inputQuestion();



};



#endif
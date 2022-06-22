#ifndef TRUEFALSE_H
#define TRUEFALSE_H
#include "Question.h"
class TrueFalse:public Question
{
	bool correctOption;
public:
	bool isCorrectAnswer(const String &) override;
	void setCorrectAnswer(char opt);
	String getCorrectAnswer() override;
	Question * clone() const override;
	void printQuestion() override;
	void inputQuestion() override;




};



#endif
#ifndef BLANKSFILL_H
#define BLANKSFILL_H
#include "Question.h"
class BlanksFill :public Question
{
	String correctOption;
public:
	bool isCorrectAnswer(const String &);
	void setCorrectAnswer(const String &);
	String getCorrectAnswer();
	Question * clone() const;
	void printQuestion();
	void inputQuestion();




};



#endif	
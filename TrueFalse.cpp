#include "TrueFalse.h"

bool TrueFalse::isCorrectAnswer(const String & opt)
{
	if (opt == "A" or opt == "a")
	{
		return true;
	}
	else
		return false;
}
void TrueFalse::setCorrectAnswer(char opt)
{
	if (opt=='A' or opt=='a')
	{
		correctOption = true;
	}
	else
	{
		correctOption = false;
	}
}
String TrueFalse::getCorrectAnswer()
{
	return correctOption;
}
Question * TrueFalse::clone() const
{
	return new TrueFalse(*this);
}
void TrueFalse::printQuestion()
{
	cout << getQuestion() <<"  :  ("<<getMarks()<<")   \n";
	cout << "   A.  True\n";
	cout << "   B.  FAlse\n";
}
void TrueFalse::inputQuestion()
{
	String temp;
	cout<< "enter your question\n";
	cin >> temp;
	cout << "    A. True\n    B.False\n";
	cout << "which optio is correct A or B?  ";
	String a;
	cin >> a;
	if (a == 'A')
		correctOption = true;
	else
		correctOption = false;	
	cout << "enter your question marks\n";
	String m;
	cin >> m;
	
	setQuestion(temp,(long long int)m);
}

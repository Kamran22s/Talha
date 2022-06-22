#include "BlanksFill.h"
#include <iostream>
using namespace std;
bool BlanksFill::isCorrectAnswer(const String & ref)
{
	if (ref == correctOption)
	{
		return true;
	}
	else
		return false;
}
void BlanksFill::setCorrectAnswer(const String & ref)
{
	correctOption = ref;
}
String BlanksFill::getCorrectAnswer()
{
	return correctOption;
}
Question * BlanksFill::clone() const
{
	return new BlanksFill(*this);
}
void BlanksFill::printQuestion()
{
	cout << getQuestion()<<"  ("<<getMarks()<<") \n";
}
void BlanksFill::inputQuestion()
{
	String temp1;
	cout << "enter your question\n";
	cin >> temp1; 
	cout << "Enter Answer : ";
	cin >> correctOption;
	cout << "enter your question marks\n";
	String m;
	cin >> m;
	setQuestion(temp1, (long long int)m);
}

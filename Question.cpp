#include "Question.h"

void Question::setQuestion(const String & ref, int m )
{
	question = ref;
	marks = m;
}

 /*void Question::inputQuestion() 
{
	 cin >> question;
}*/
String Question::getQuestion()
{
	return question;
}
int Question::getMarks()
{
	return marks;
}
void Question::setMarks(int m)
{
	marks = m;
}
 
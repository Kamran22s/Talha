#include "MCQ.h"
bool MCQ::isCorrectAnswer(const String & ref)
{
	if (options[correctOption] == ref)
	{
		return true;
	}
	else
		return false;
}
void MCQ::setOption(String & ref, int optNumber)
{
	options[optNumber-1] = ref;

}
void MCQ::setCorrectAnswer(char opt)
{
	correctOption = int(opt);
}
String MCQ::getCorrectAnswer()
{
	return options[correctOption];
}
Question * MCQ::clone() const
{
	return new MCQ(*this);
}
void MCQ::printQuestion()
{
	cout<<getQuestion()<<": ("<<getMarks()<<")      \n";
	cout << "    A. " << options[0]<<endl;
	cout << "    B. " << options[1] << endl;
	cout << "    C. " << options[2] << endl;
	cout << "    D. " << options[3] << endl;
	
}
void MCQ::inputQuestion()
{
	String temp;
	cout << "enter your question\n";
	
	cin >> temp;
	cout << "  Enter Option A. ";
	cin >> options[0];
	cout << "  Enter Option B. ";
	cin >> options[1];
	cout << "  Enter Option C. ";
	cin >> options[2];
	cout << "  Enter Option D. ";
	cin >> options[3];
	
	cout << "which option is correct A:B:C:D?  ";
	String a;
	cin >> a;
	if (a == 'A')
		correctOption = 0;
	else if (a == 'B')
		correctOption = 1;
	else if (a == 'C')
		correctOption = 2;
	else if (a == 'D')
		correctOption = 3;
	else
		cout << "Invalid option entered\n";
	cout << "enter your question marks\n";
	String m;
	cin >> m;
	setQuestion(temp, (long long int)m);

}

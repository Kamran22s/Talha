#include <iostream>
using namespace std;
#include "QuizApp.h"
#include "QuestionPool.h"
#include "Quiz.h"
#include "MCQ.h"
#include "TrueFalse.h"
#include "BlanksFill.h"
#include <string>
void QuizApp::startApp()
{
	
	String temp,qDBvar,qCount;
	QuestionPool qP;
	Quiz q;
	bool check;
	do
	{
		
		cout << "\n*************Quiz App*************\n";
		cout << "Enter 1 to store a question in question in question data bank\n";
		cout << "      2 to print a quiz\n";
		cout << "      3 to attempt a quiz\n";
		cout << "      0 to  exit...........:\n";
		cin >> temp;
		if ((long long int)temp == 1)
		{
			cout << "*************Questio Data Bank*************\n";
			cout << "Enter 1 to add Mcqs\n";
			cout << "      2 to add True/False\n";
			cout << "      3 to add Fill in the blanks\n";
			cout << "      4 to return to main menu/Quiz App...........:\n"; cin >> qDBvar;
			if ((long long int)qDBvar == 1)
			{
				
				cout << "*****MCQ's Storage*****\n";
				do
				{
					MCQ m;
					m.inputQuestion();
					qP.addQuestion(m);
					cout << "Pree enter to add another question or any other key to continue :\n";
					
				} while (cin.get() == '\n');
				cin.ignore();
			}
			else if ((long long int)qDBvar == 2)
			{
				TrueFalse t;
				
				cout << "*****True False Storage*****\n";
				do
				{
					t.inputQuestion();
					qP.addQuestion(t);
					cout << "Pree enter to add another question or any other key to continue :\n";
		
				} while (cin.get() == '\n');
				cin.ignore();
			}
			else if ((long long int)qDBvar == 3)
			{
				BlanksFill b;

				cout << "*****BlankFills Storage*****\n";
				do
				{
					b.inputQuestion();
					qP.addQuestion(b);
					cout << "Pree enter to add another question or any other key to continue :\n";

				} while (cin.get() == '\n');
				cin.ignore();
			}
			else if ((long long int)qDBvar == 4)
			{
				continue;
			}
			else
				cout << "invalid number entered\n";

		}
		else if ((long long int)temp == 2)
		{
			
			cout << "How many questions do you want in quiz? \n";
			cin >> qCount;
			qP.generateQuiz(q, (long long int)qCount);
			q.printQuiz();

		}
		else if ((long long int)temp == 3)
		{
			cout << "How many questions do you want in quiz?   \n";
			cin >> qCount;
			cout << "\n" << (long long int)qCount;
			if ((long long int)qCount <= qP.getNumberOfQuestions())
			{
				qP.generateQuiz(q, (long long int)qCount);
		
				cout << "\n****Quiz In Progress****\n";

				for (int i = 0; i < (long long int)qCount; i++)
				{
					do
					{
						cout << i << ": ";
						q.showCurrentQuestion();
						cout << "\n Enter your answer or simply enter to delay it : \n";
						String sCheck;
						cin >> sCheck;
						if (sCheck == "\0")
						{
							q.delayQuestion();
							check = false;
						}
						else
						{
							q.setAnswerForCurrentQuestion(sCheck);
							q.nextQuestion();
							check = true;
						}
					} while (check == false);
					if (q.isQuizFinished())
					{
						cout << "\nQuiz Finished. your Marks are :" << q.getObtainedMarks() << "/" << q.gertMaximumMarks();

					}
				}
			}
			else
				cout << "\nNot Enough Questions in Question Pool ...\n";
		}
		else if ((long long int)temp == 0)
		{
			cout << "\n<<<<<<<<<exiting the application>>>>>>>>>>\n";
		}
		else
			cout << "Invalid Value Enterd\n";
	} while ((long long int)temp != 0);



}
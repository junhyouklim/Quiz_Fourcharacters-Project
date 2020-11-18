#pragma once
#include <iostream>
#include <string>
#include "Ctrl.h"
using namespace std;

class UI {
private:
	Ctrl* c;
public:
	UI(Ctrl* ctr)
	{
		c = ctr;
	}

	void solveProb()
	{
		system("cls");
		c->solveProb();
		cin.get();
	}

	void lookUpScore()
	{
		system("cls");
		c->lookUpScore();
		cin.get();
	}

	int mainUI()
	{
		int input;

		cout << "[사자성어 맞추기]" << endl;
		cout << "1. 문제 풀기" << endl;
		cout << "2. 점수 조회" << endl;
		cout << "3. 종료" << endl;
		cin >> input;
		cin.get();
		return input;
	}

	void mainRun()
	{
		int ch = 0;

		while (1)
		{
			system("cls");
			ch = mainUI();
			
			switch (ch)
			{
				case 1:	
					solveProb();
					break;
				case 2:	
					lookUpScore();
					break;
				case 3:	//종료
					exit(1);
			}
		}
	}
};
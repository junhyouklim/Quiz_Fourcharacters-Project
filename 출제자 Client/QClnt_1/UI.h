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

	void registProb()
	{
		system("cls");
		c->registProb();
		cin.get();
	}

	void deleteProb()
	{
		system("cls");
		c->deleteProb();
		cin.get();
	}

	void lookUpProb()
	{
		system("cls");
		c->lookUpProb();
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
		cout << "1. 문제 등록" << endl;
		cout << "2. 문제 삭제" << endl;
		cout << "3. 문제 조회" << endl;
		cout << "4. 점수 조회" << endl;
		cout << "5. 종료" << endl;
		cout << "입력 : ";
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
				registProb();
				break;
			case 2:
				deleteProb();
				break;
			case 3:
				lookUpProb();
				break;
			case 4:
				lookUpScore();
				break;
			case 5:	//종료
				exit(1);
			}
		}
	}
};
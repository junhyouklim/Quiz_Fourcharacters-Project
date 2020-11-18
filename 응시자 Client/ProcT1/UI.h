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

		cout << "[���ڼ��� ���߱�]" << endl;
		cout << "1. ���� Ǯ��" << endl;
		cout << "2. ���� ��ȸ" << endl;
		cout << "3. ����" << endl;
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
				case 3:	//����
					exit(1);
			}
		}
	}
};
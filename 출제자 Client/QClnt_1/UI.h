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

		cout << "[���ڼ��� ���߱�]" << endl;
		cout << "1. ���� ���" << endl;
		cout << "2. ���� ����" << endl;
		cout << "3. ���� ��ȸ" << endl;
		cout << "4. ���� ��ȸ" << endl;
		cout << "5. ����" << endl;
		cout << "�Է� : ";
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
			case 5:	//����
				exit(1);
			}
		}
	}
};
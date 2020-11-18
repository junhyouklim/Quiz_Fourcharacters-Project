#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "TotalData.h"
#include "PartialData.h"
#include "ClntTCP.h"
using namespace std;

class Ctrl {
private:
	TotalData tData;
	PartialData pData;
	ClntTCP ctcp;
public:
	Ctrl(int argc, char** argv) : ctcp(argc, argv) {}

	void solveProb()		//////////1.����Ǯ��
	{
		loadData(1);		//pData�� sig ���� + pData ���� + tData ��ȯ

		Question Que[10];		//���� 10��
		int num;						//���� �߻� ����
		char input[100];		//�����ڰ� �� �Է��� ���ڿ�
		int score = 0;		//������ ����

		srand(time(NULL));
		for (int i = 0; i < 10; i++)	//������ �̾� ���� 10�� �̾Ƽ� ���
		{
			num = rand() % 50;		//0~49
			Que[i] = tData.qData[num];		//TotalData �Űܴ��(�����Ѽչ���)

			for (int j = 0; j < i; j++)		//�ߺ����� Ȯ��
			{
				if ((Que[j] == tData.qData[num]) == -1)		//�ߺ� �ÿ� for�� i ����(Question.h �� �Լ� ����)					
				{
					i--;
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			system("cls");
			//strcpy(input, printProb(Que[i], i));
			score += Scoring(Que[i], i, printProb(Que[i], i));	//�������+�� ä��
		}

		setData(score);		//����, �����̸� ���
		loadData(2);		//pData�� sig ���� + pData ���� + tData ��ȯ
	}

	void loadData(int sig)
	{
		pData.setSig(sig);		//sig ����
		tData = ctcp.LoadData(pData);		//pData ���� �� tData ��ȯ
	}

	char* printProb(Question Q, int num)		//����, ���� ��ȣ 
	{
		char input[100];

		cout << "[���� " << num + 1 << "��]" << endl;
		cout << Q.getContent() << endl;		//���� ���
		cout << "�� �Է�: ";
		cin >> input;
		cin.ignore();

		return input;
	}

	int Scoring(Question Q, int num, char *input)
	{
		int score = 0;
		
		cout << input << endl;
		cout << Q.getAnswer() << endl;
		getchar();
	
		if (strcmp(input, Q.getAnswer()) == 0)		//������ ��� == ����
		{
			score += 10;		//+10�� 
		}
		
		return score;		//ä����� ��ȯ
	}

	void setData(int score)
	{
		char name[100];

		cout << "������ �̸� �Է�: ";
		cin >> name;

		cout << "����: " << score << endl;
		cin.get();

		pData.setData(name, score);
	}
	
	void lookUpScore()		//2. ���� ��ȸ
	{
		loadData(1);		//pData�� sig ���� + pData ���� + tData ��ȯ
		showRank();
	}

	void showRank()
	{
		cout.setf(ios::left);		//���� ����
		cout << setw(20) << "�̸�" << setw(5) << "����" << endl;
		tData.prinkRank();
	}
};

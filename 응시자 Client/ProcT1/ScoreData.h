#pragma warning(disable:4996)	/////strcpy ������ ���� warning �ذ��
#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>		//���� ����

using namespace std;

#ifndef SCORE
#define SCORE
class ScoreData 
{
public:
	int score;
	char userName[100];

public:
	ScoreData() { }
	ScoreData(char* un, int s)
	{
		strcpy(userName, un);
		score = s;
	}
	ScoreData(const ScoreData& s)
	{
		strcpy(userName, s.userName);
		score = s.score;
	}
	const ScoreData& operator=(const ScoreData& s)
	{
		strcpy(userName, s.userName);
		score = s.score;
		return *this;
	}

	char* getUserName()
	{
		return userName;
	}

	int getScore()
	{
		return score;
	}

	void printData()		//������
	{
		cout.setf(ios::left);		//���� ����
		cout << setw(20) << userName << setw(5) << score << endl;
		//cout << userName << " " << score << endl;
	}
	//////////////////
	void setData(char *name, int scr)
	{
		strcpy(userName, name);
		score = scr;
	}
};

#endif


#include<iostream>
#include<string>
#include<string.h>

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

	void printData()
	{
		cout << userName << " " << score << endl;
	}

	void insertScore(int scr)
	{
		score = scr;
	}

	void writeName(char* name)
	{
		strcpy(userName, name);
	}

	int getScore()
	{
		return score;
	}

	string getName()
	{
		string name(userName);
		return name;
	}
};

#endif


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

	char* getUserName()
	{
		return userName;
	}

	int getScore()
	{
		return score;
	}

	void printData()
	{
		cout << userName << " " << score << endl;
	}
};

#endif
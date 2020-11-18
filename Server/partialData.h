#include<iostream>
#include<string>
#include"scoreData.h"
#include"question.h"

using namespace std;

#ifndef PARTIAL
#define PARTIAL

class PartialData
{
public:
	int sig;
	Question aQData;
	ScoreData aSData;

public:
	PartialData() { }
	PartialData(Question aQ, ScoreData aS)
	{
		aQData = aQ;
		aSData = aS;
	}
	PartialData(int s, Question aQ, ScoreData aS)
	{
		sig = s;
		aQData = aQ;
		aSData = aS;
	}

	int getSig()
	{
		return sig;
	}

	Question getAQData()
	{
		return aQData;
	}

	ScoreData getASData()
	{
		return aSData;
	}

	void setSig(int s)
	{
		sig = s;
	}

	void setAQData(Question aQ)
	{
		aQData = aQ;
	}

	void setASData(ScoreData aS)
	{
		aSData = aS;
	}
};

#endif 
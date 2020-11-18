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
	void editSig(int _sig)
	{
		sig = _sig;
	}
	/////////////////////////////////
	void registProb()
	{
		string content, answer;

		cout << "문항 작성: ";
		getline(cin, content);
		//cin >> content;
		
		
		cout << "답안 작성: ";
		getline(cin, answer);
		//cin >> answer;

		aQData.registProb(content, answer);
	}

	void editSerial()
	{
		int input = 0;

		cout << "삭제할 문항 번호 입력: ";
		cin >> input;
		cin.ignore();

		aQData.editSerial(input);
	}
};

#endif 
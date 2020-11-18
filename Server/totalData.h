

#include<iostream>
#include<string>
#include<string.h>
#include"scoreData.h"
#include"question.h"
#define MAX_Q 50
#define MAX_S 50
using namespace std;

#ifndef TOTAL
#define TOTAL

class TotalData
{
public:	
    int qNum;
	int sNum;
	Question qData[100];
	ScoreData sData[100];
	int result;
			
public:
	TotalData()
	{
		qNum = 0;
		sNum = 0;
		result = 0;
	}
	TotalData(Question* q, ScoreData* s, int qN, int sN, int rlt)
	{
		CopyArr(qData, q, qN);
		CopyArr(sData, s, sN);
		qNum = qN;
		sNum = sN;
		result = rlt;
	}

	TotalData(const TotalData& t)
	{
/* 		CopyArr(qData, t.qData, t.qNum);
		CopyArr(qData, t.qData, t.qNum); */
		
		for(int i = 0; i<t.qNum; i++)
			qData[i] = t.qData[i];
		for(int i = 0; i<t.sNum; i++)
			sData[i] = t.sData[i];
		qNum = t.qNum;
		sNum = t.sNum;
		result = t.result;
	}

	const TotalData& operator=(const TotalData& t)
	{
		/*
		CopyArr(qData, t.qData, t.qNum);
		CopyArr(qData, t.qData, t.qNum);
		*/
		for(int i = 0; i<t.qNum; i++)
			qData[i] = t.qData[i];
		for(int i = 0; i<t.sNum; i++)
			sData[i] = t.sData[i];
		qNum = t.qNum;
		sNum = t.sNum;
		result = t.result;

		return *this;
	}

	template<typename T>
	void CopyArr(T target, T source, int num)
	{
		int i = 0;
		for (i = 0; i < num; i++)
			target[i] = source[i];
	}

	void AddQData(Question qD)
	{
		this->qData[qNum] = qD;
		this->qNum++;
	}

	void AddSData(ScoreData sD)
	{
		this->sData[sNum] = sD;
		this->sNum++;
	}

	Question* getQData()
	{
		return qData;
	}

	ScoreData* getSData()
	{
		return sData;
	}

	int getQNum()
	{
		return qNum;
	}

	int getSNum()
	{
		return sNum;
	}

	int getResult()
	{
		return result;
	}

	void setResult(int r)
	{
		result = r;
	}

	void printData()
	{
		cout << qNum << " " << sNum << endl;
		for(int i=0; i<qNum; i++)
			qData[i].printData();
		for(int i=0; i<sNum; i++)
			sData[i].printData();			
	}

};

#endif 

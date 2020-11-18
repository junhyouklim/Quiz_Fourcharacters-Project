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

	void solveProb()		//////////1.문제풀기
	{
		loadData(1);		//pData내 sig 설정 + pData 전송 + tData 반환

		Question Que[10];		//문항 10개
		int num;						//난수 발생 변수
		char input[100];		//응시자가 답 입력할 문자열
		int score = 0;		//응시자 점수

		srand(time(NULL));
		for (int i = 0; i < 10; i++)	//난수를 뽑아 문제 10항 뽑아서 담기
		{
			num = rand() % 50;		//0~49
			Que[i] = tData.qData[num];		//TotalData 옮겨담기(원본훼손방지)

			for (int j = 0; j < i; j++)		//중복여부 확인
			{
				if ((Que[j] == tData.qData[num]) == -1)		//중복 시에 for문 i 감소(Question.h 내 함수 참조)					
				{
					i--;
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			system("cls");
			//strcpy(input, printProb(Que[i], i));
			score += Scoring(Que[i], i, printProb(Que[i], i));	//문제출력+답 채점
		}

		setData(score);		//점수, 유저이름 등록
		loadData(2);		//pData내 sig 설정 + pData 전송 + tData 반환
	}

	void loadData(int sig)
	{
		pData.setSig(sig);		//sig 설정
		tData = ctcp.LoadData(pData);		//pData 전송 및 tData 반환
	}

	char* printProb(Question Q, int num)		//문제, 문제 번호 
	{
		char input[100];

		cout << "[문제 " << num + 1 << "번]" << endl;
		cout << Q.getContent() << endl;		//문제 출력
		cout << "답 입력: ";
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
	
		if (strcmp(input, Q.getAnswer()) == 0)		//응시자 답안 == 정답
		{
			score += 10;		//+10점 
		}
		
		return score;		//채점결과 반환
	}

	void setData(int score)
	{
		char name[100];

		cout << "응시자 이름 입력: ";
		cin >> name;

		cout << "점수: " << score << endl;
		cin.get();

		pData.setData(name, score);
	}
	
	void lookUpScore()		//2. 점수 조회
	{
		loadData(1);		//pData내 sig 설정 + pData 전송 + tData 반환
		showRank();
	}

	void showRank()
	{
		cout.setf(ios::left);		//왼쪽 정렬
		cout << setw(20) << "이름" << setw(5) << "점수" << endl;
		tData.prinkRank();
	}
};

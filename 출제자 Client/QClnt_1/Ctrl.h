#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TotalData.h"
#include "PartialData.h"
#include "ClntTCP.h"
using namespace std;

enum { UPDATE = 1, INST_S = 2, INST_Q = 3, DEL_Q = 4 };

class Ctrl {
private:
	TotalData tData;
	PartialData pData;
	ClntTCP* ctcp;
public:
	Ctrl(ClntTCP* tcp) { ctcp = tcp; }

	void registProb()/////////
	{
		writeProb();
		loadData(INST_Q);	//등록 sig
	}

	void writeProb()
	{
		pData.registProb();
	}

	void deleteProb()////////
	{
		loadData(UPDATE);	//업데이트 sig
		tData.showProb();
		pData.editSerial();
		loadData(DEL_Q);	//삭제 sig
	}

	void lookUpProb()//////////
	{
		loadData(UPDATE);	//업데이트 sig
		tData.showProb();
	}

	void lookUpScore()///////////
	{
		loadData(UPDATE);	//업데이트 sig
		tData.showRank();
	}

	void loadData(int sig)
	{
		pData.editSig(sig);
		tData = ctcp->LoadData(pData);
	}
};
#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <WinSock2.h>
#include "TotalData.h"
#include "PartialData.h"
using namespace std;

class ClntTCP
{
private:
	WSADATA wsadata;
	SOCKET sock;
	SOCKADDR_IN ServAddr;
public:
	ClntTCP(int argc, char** argv)
	{
		if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
			ErrorHandling("WSAStartup Error");

		sock = socket(PF_INET, SOCK_STREAM, 0);
		if (sock == INVALID_SOCKET)
			ErrorHandling("Socket Error");

		memset(&ServAddr, 0, sizeof(ServAddr));
		ServAddr.sin_family = AF_INET;
		ServAddr.sin_addr.s_addr = inet_addr(argv[1]);
		ServAddr.sin_port = htons(atoi(argv[2]));

		//생성된 소켓을 이용하여 서버에 연결 요청
		if (connect(sock, (SOCKADDR*)&ServAddr, sizeof(ServAddr)) == SOCKET_ERROR)
			ErrorHandling("connect Error");
	}
	TotalData LoadData(PartialData pdata)
	{
		TotalData ttemp;
		send(sock, (const char*)&pdata, sizeof(PartialData), 0);
		//recv(sock, (char*)&ttemp, sizeof(TotalData), 0);

		cout << pdata.sig << endl;

		recv(sock, (char*)&ttemp.qNum, sizeof(ttemp.qNum), 0);
		Sleep(5);
		recv(sock, (char*)&ttemp.sNum, sizeof(ttemp.sNum), 0);
		Sleep(5);

		cout << ttemp.qNum << " " << ttemp.sNum << endl;

		Sleep(1000);

		for (int i = 0; i < ttemp.qNum; i++)
		{
			recv(sock, (char*)&ttemp.qData[i], sizeof(ttemp.qData[i]), 0);
			Sleep(5);
		}
		for (int i = 0; i < ttemp.sNum; i++)
		{
			recv(sock, (char*)&ttemp.sData[i], sizeof(ttemp.sData[i]), 0);
			Sleep(5);
		}
		return ttemp;
	}
	void ErrorHandling(const char* message)
	{
		cerr << message << endl;
		exit(1);
	}
	~ClntTCP()
	{
		closesocket(sock);
		WSACleanup();
	}

};
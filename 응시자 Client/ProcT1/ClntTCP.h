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
		ServAddr.sin_addr.s_addr = inet_addr("10.10.20.215");
		ServAddr.sin_port = htons(atoi("2001"));

		//생성된 소켓을 이용하여 서버에 연결 요청
		if (connect(sock, (SOCKADDR*)&ServAddr, sizeof(ServAddr)) == SOCKET_ERROR)
			ErrorHandling("connect Error");
	}
	TotalData LoadData(PartialData pdata)
	{
		TotalData t;
		send(sock, (const char*)&pdata, sizeof(PartialData), 0);
		recv(sock, (char*)&t.qNum, sizeof(t.qNum), 0);
		Sleep(10);
		recv(sock, (char*)&t.sNum, sizeof(t.sNum), 0);
		Sleep(10);
		for (int i = 0; i < t.qNum; i++)
		{
			recv(sock, (char*)&t.qData[i], sizeof(t.qData[i]), 0);
			Sleep(10);
		}
		for (int i = 0; i < t.sNum; i++)
		{
			recv(sock, (char*)&t.sData[i], sizeof(t.sData[i]), 0);
			Sleep(10);
		}
		return t;
	}
	void ErrorHandling(const char* message)
	{
		cerr << message << endl;
		exit(1);
	}
	void Close()
	{
		closesocket(sock);
		WSACleanup();
	}
	~ClntTCP()
	{
		closesocket(sock);
		WSACleanup();
	}
};


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>

#include <netinet/in.h>
#include <pthread.h>

#include<iostream>

#include"partialData.h"
#include"totalData.h"
#include"ctrlDB.h"

using namespace std;

#ifndef SERVTCP
#define SERVTCP

#define MAX_CLNT 100
enum {UPDATE = 1, INST_S = 2, INST_Q = 3, DEL_Q = 4};    

    int clnt_socks[MAX_CLNT];
    int socks_clnt;

    CtrlDB db;

	pthread_mutex_t mutx;

class ServTCP
{	
private:
    int serv_sock;    
	struct sockaddr_in serv_addr;   

public:
	ServTCP(int argc, char** argv)
	{
		socks_clnt = 0;

        serv_sock = socket(PF_INET, SOCK_STREAM, 0);
        if(serv_sock == -1) {
            error_handling("socket() error\n");
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        serv_addr.sin_port = htons(atoi(argv[1]));

        if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
            error_handling("bind() error\n");
        }

        if(listen(serv_sock, 5) == -1) {
            error_handling("listen() error\n");
        }
	}
	
	void run()
	{
		int clnt_sock;
		struct sockaddr_in clnt_addr;
		socklen_t clnt_addr_size;
		pthread_t t_id;		
		
		pthread_mutex_init(&mutx, NULL);

		clnt_addr_size = sizeof(clnt_addr);

        while(1) {
            clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
            if(clnt_sock == -1) {
                error_handling("accept() error\n");
            }

			pthread_mutex_lock(&mutx);
			clnt_socks[socks_clnt++] = clnt_sock;
			pthread_mutex_unlock(&mutx);

			pthread_create(&t_id, NULL, ClntHandler, (void*)&clnt_sock);
			pthread_detach(t_id);
			     
        }


        close(clnt_sock);
        close(serv_sock);

	}
	
	static void* ClntHandler(void* arg)
	{
		int clnt_sock = *((int*)arg);
		int str_len = 0, i;
		PartialData aPart;
		TotalData aTotal;		
		
		while ((str_len = recv(clnt_sock, (char*)&aPart, sizeof(aPart), 0)) != 0)
		{
			
			if (aPart.getSig() == UPDATE)
			{
				aTotal = db.LoadAllData();
			}

			else if (aPart.getSig() == INST_S)
			{
				aTotal = db.insertScoreData(aPart.getASData());
			}

			else if (aPart.getSig() == INST_Q)
			{
				aTotal = db.insertQuestion(aPart.getAQData());
			}

			else if (aPart.getSig() == DEL_Q)
			{
				aTotal = db.deleteQuestion(aPart.getAQData());
			}
			else
				break;

			//send(clnt_sock, (const char*)&aTotal, sizeof(aTotal), 0);

			write(clnt_sock, &aTotal.qNum, sizeof(aTotal.qNum));
            write(clnt_sock, &aTotal.sNum, sizeof(aTotal.sNum));            
	
            for(int i = 0; i<aTotal.qNum; i++)
            {
                write(clnt_sock, &aTotal.qData[i], sizeof(aTotal.qData[i]));
            }

            for(int i = 0; i<aTotal.sNum; i++)
            {
                write(clnt_sock, &aTotal.sData[i], sizeof(aTotal.sData[i]));
            } 
		}


		pthread_mutex_lock(&mutx);

		for (i = 0; i < socks_clnt; i++) {
			if (clnt_sock == clnt_socks[i]) {
				while (i++ < socks_clnt - 1)
					clnt_socks[i] = clnt_socks[i + 1];
				break;
			}
		}
		socks_clnt--;

		pthread_mutex_unlock(&mutx);

		close(clnt_sock);

		return 0;

	}
	
	void error_handling(const char* message)
	{
		fputs(message, stderr);
		fputc('\n', stderr);
		exit(1);
	}
	
};

#endif

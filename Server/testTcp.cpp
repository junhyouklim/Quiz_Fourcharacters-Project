#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>

#include<iostream>
#include<string>
#include"partialData.h"
#include"totalData.h" 

using namespace std;
/*
class MyClass
{
private:
	int num;
	char str[100];
    char str2[100];
public:

	MyClass() { }
	MyClass(int num, char *s, char* s2)
	{
		this->num = num;
		strcpy(str, s);
        strcpy(str2, s2);
	}


	void printData()
	{
		cout << num << " " << str << endl;
	}
};

class Question
{
public:
	int serial;
	char content[100];
	char answer[100];

public:
	Question() {  }
	Question(char* con, char* ans)
	{
		serial = 0;
		strcpy(content, con);
		strcpy(answer, ans);
	}
	Question(int s, char* con, char* ans)
	{
		serial = s;
		strcpy(content, con);
		strcpy(answer, ans);
	}
	Question(const Question& q)
	{
		serial = q.serial;
		strcpy(content, q.content);
		strcpy(answer, q.answer);
	}

	Question& operator=(const Question& q)
	{
		serial = q.serial;
		strcpy(content, q.content);
		strcpy(answer, q.answer);
	}


	int getSerial()
	{
		return serial;
	}

	char* getContent()
	{
		return content;
	}

	char* getAnswer()
	{
		return answer;
	}

	void setSerial(int s)
	{
		serial = s;
	}

	void printData()
	{
		cout << serial << " " << content << " " << answer << endl;
	}

};

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
	ScoreData& operator=(const ScoreData& s)
	{
		strcpy(userName, s.userName);
		score = s.score;
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

class TotalData
{
public:
	
	Question qData[100];
    int qNum;
	int sNum;
	int result;
	ScoreData sData[100];

	
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

	TotalData(TotalData& t)
	{
		CopyArr(qData, t.qData, t.qNum);
		CopyArr(qData, t.qData, t.qNum);
		qNum = t.qNum;
		sNum = t.sNum;
		result = t.result;
	}

	TotalData& operator=(TotalData& t)
	{
		CopyArr(qData, t.qData, t.qNum);
		CopyArr(qData, t.qData, t.qNum);
		qNum = t.qNum;
		sNum = t.sNum;
		result = t.result;
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

};
*/
void error_handling(char* message);

int main(int argc, char** argv) {
    int serv_sock;
    int clnt_sock;
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    //int clnt_addr_size = 0;
    socklen_t clnt_addr_size = 0;

    char message[30] = "Hello World!\n";

    if(argc != 2) {
        printf("Usage : %s <port> \n", argv[0]);
        exit(1);
    }

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

    clnt_addr_size = sizeof(clnt_addr);

    
    Question data(1,"abc", "def");
    ScoreData data2("aaa", 100);

    Question arr[10];
    arr[0] = data;
    arr[0].printData();
    
    PartialData data3(data, data2);

    TotalData data4;

    Question q1("agfsd", "cvzvxczcx");
    Question q2(5, "ag12fsd", "cvzvasdsadxczcx");
    Question q3(7, "agf34sd", "가나다라");

    data4.AddQData(q1);
    data4.AddQData(q2);
    data4.AddQData(q3);

    ScoreData s1("zxcv", 34);
    ScoreData s2("zxsadcv", 94);
    ScoreData s3("zxc32432v", 74);

    data4.AddSData(s1);    
    data4.AddSData(s2);
    data4.AddSData(s3);

    cout << data4.qNum << endl;
    cout << data4.sNum << endl;

    cout << data4.qData[0].content << " " << data4.qData[0].answer << " " << data4.qData[0].serial << endl;
	cout << data4.qData[1].content << " " << data4.qData[1].answer << " " << data4.qData[1].serial << endl;
	cout << data4.qData[2].content << " " << data4.qData[2].answer << " " << data4.qData[2].serial << endl;

	cout << data4.sData[0].userName << " " << data4.sData[0].score << endl;
	cout << data4.sData[1].userName << " " << data4.sData[1].score << endl;
	cout << data4.sData[2].userName << " " << data4.sData[2].score << endl;
    

    while(1) {
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        if(clnt_sock == -1) {
            error_handling("accept() error\n");
        }
        write(clnt_sock, &data4.qNum, sizeof(data4.qNum));
        usleep(100);
        write(clnt_sock, &data4.sNum, sizeof(data4.sNum));
        usleep(100);
        
        for(int i = 0; i<data4.qNum; i++)
        {
            write(clnt_sock, &data4.qData[i], sizeof(data4.qData[i]));
        }

        for(int i = 0; i<data4.sNum; i++)
        {
            write(clnt_sock, &data4.sData[i], sizeof(data4.sData[i]));
        }       
        
        
    }

    close(clnt_sock);
    close(serv_sock);

}

void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

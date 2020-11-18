#include<string.h>
#include<string>
#include<iostream>

using namespace std;


#ifndef QUESTION
#define QUESTION

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

	const Question& operator=(const Question& q)
	{
		serial = q.serial;
		strcpy(content, q.content);
		strcpy(answer, q.answer);
		return *this;
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

#endif
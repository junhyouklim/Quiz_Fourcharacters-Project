#ifndef CTRLDB
#define CTRLDB
//#include<mysql.h>
#include"/usr/include/mysql/server/mysql.h"
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include"totalData.h"
#include"partialData.h"

using namespace std;

class CtrlDB
{
private:
	MYSQL* con;
	
public:
	CtrlDB()
	{
		con = mysql_init(NULL);
		if (con == NULL)
		{
			fprintf(stderr, "%s\n", mysql_error(con));
			exit(1);
		}

		if (mysql_real_connect(con, "10.10.20.215", "root", "1234", "MYSQL_TCP", 3306, NULL, 0) == NULL)
		{
			cout << "실패" << endl;
			exit(1);
		}
		else
		{
			cout << "성공" << endl;
		}

 		mysql_query(con, "set session character_set_connection=euckr;");
		mysql_query(con, "set session character_set_results=euckr;");
		mysql_query(con, "set session character_set_client=euckr;");
	}

	TotalData LoadAllData()
	{
		mysql_set_character_set(con, "euckr");
		TotalData aTotData;

		mysql_query(con, "SELECT * FROM question_tbl");
		MYSQL_RES* result = mysql_store_result(con);

		MYSQL_ROW row;

		while ((row = mysql_fetch_row(result)))
		{
			Question qData(atoi(row[0]), row[1], row[2]);
			aTotData.AddQData(qData);
		}

		mysql_query(con, "SELECT * FROM score_tbl");
		result = mysql_store_result(con);

		while ((row = mysql_fetch_row(result)))
		{
			ScoreData sData(row[0], atoi(row[1]));
			aTotData.AddSData(sData);	
		}

		aTotData.setResult(true);

		mysql_free_result(result);

		return aTotData;
	}
	
	TotalData insertQuestion(Question inputData)
	{
		
		char query[100];
		sprintf(query, "insert into question_tbl (content, answer) values( '%s', '%s')", inputData.getContent(), inputData.getAnswer());

		handleSQL_IDU(query);
		
		return LoadAllData();
	}

	TotalData insertScoreData(ScoreData inputData)
	{
		
		char query[100];
		sprintf(query, "insert into score_tbl (username, score) values( '%s', %d)", inputData.getUserName(), inputData.getScore());

		handleSQL_IDU(query);

		return LoadAllData();
	}

	TotalData deleteQuestion(Question delData)
	{
		
		char query[100];
		sprintf(query, "delete from question_tbl where num_question = %d", delData.getSerial());

		handleSQL_IDU(query);

		return LoadAllData();
	}
	
	void handleSQL_IDU(char* query)
	{
		if (mysql_query(con, query))
		{
			cout << "실패" << endl;
		}
		else
		{
			cout << "처리 완료 \n" << endl;
		}
	}
	
};



#endif
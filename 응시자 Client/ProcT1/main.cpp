#include <iostream>
#include "UI.h"

int main(int argc, char** argv)
{
	/*if (argc != 3)
	{
		cerr << "ERROR OCCUR" << endl;
		exit(1);
	}*/
	Ctrl ctr(argc, argv);			//Ctrl 생성자 함수에서 서버와 연결
	UI UI(&ctr);
	UI.mainRun();
}
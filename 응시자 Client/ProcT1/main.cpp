#include <iostream>
#include "UI.h"

int main(int argc, char** argv)
{
	/*if (argc != 3)
	{
		cerr << "ERROR OCCUR" << endl;
		exit(1);
	}*/
	Ctrl ctr(argc, argv);			//Ctrl ������ �Լ����� ������ ����
	UI UI(&ctr);
	UI.mainRun();
}
#define _CRT_SECURE_NO_WARNINGS
#include "UI.h"

int main(int argc, char** argv)
{
	
	if (argc != 3)
	{
		cerr << "ERROR OCCUR" << endl;
		exit(1);
	}
	

	ClntTCP tcpConn(argc, argv);
	Ctrl control(&tcpConn);
	UI ui(&control);

	ui.mainRun();
}
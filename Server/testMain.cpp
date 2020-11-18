
#include<iostream>
#include<string>
#include<string.h>
#include"partialData.h"
#include"totalData.h"
#include"ctrlDB.h"
#include"servTCP.h"

using namespace std;

int main(int argc, char** argv)
{
    
    ServTCP serv(argc, argv);

    serv.run();
    
}
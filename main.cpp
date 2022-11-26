#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "commandline5.h"

using namespace std;

int main(int argc, char *argv[])
{
    //data Size
    int size[6] = {10000, 30000, 50000, 100000, 300000, 500000};

    if(argc == 5)
    {
        if(!strcmp(argv[1],"-a"))
        {
            if(atoi(argv[3]) == 0)
            {
                if(strstr(argv[3],".txt"))
                {
                    cout << "Run cmd 1";
                    commandline1(argc, argv);
                }
                else
                {
                    cout << "Run cmd 3\n";
                    cout << "Print empty data";
                }
            }
            else
            {
                cout << "Run cmd 3";
            }
        }
        else
        {
            cout << "Run cmd 4";
        }
    }
    else if(argc == 6)
    {
        if(!strcmp(argv[1],"-a"))
        {
            cout << "Run cmd 2";
        }
        else
        {   
            //cmd line 5
            cout << "Run cmd 5";
            commandline5(argc, argv);
        }
    }
    else
    {
        cout << "Wrong command line";
    }

    return 0;
}




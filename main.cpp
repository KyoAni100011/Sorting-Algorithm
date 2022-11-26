#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc == 5)
    {
        if(!strcmp(argv[1],"-a"))
        {
            if(atoi(argv[3]) == 0)
            {
                if(strstr(argv[3],".txt"))
                {
                    cout << "Run cmd 1";
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
            cout << "Run cmd 5";
        }
    }
    else
    {
        cout << "Wrong command line";
    }
}




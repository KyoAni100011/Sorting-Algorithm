#include "commandline.h"

int main(int argc, char *argv[])
{
    if (argc == 5)
    {
        if (!strcmp(argv[1], "-a"))
        {
            if (atoi(argv[3]) == 0)
            {
                if (strstr(argv[3], ".txt"))
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
                commandline3(argc, argv);
            }
        }
        else
        {
            cout << "Run cmd 4";
            commandline4(argc, argv);
        }
    }
    else if (argc == 6)
    {
        if (!strcmp(argv[1], "-a"))
        {
            cout << "Run cmd 2";
            commandline2(argc, argv);
        }
        else
        {
            // cmd line 5
            cout << "Run cmd 5";
            commandline5(argc, argv);
        }
    }
    else
    {
        cout << "Wrong command";
    }

    return 0;
}

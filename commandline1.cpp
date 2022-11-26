#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "sortCompare.h"

using namespace std;

void createFile(string file_name)
{
    srand((unsigned int)time(NULL));

    ofstream file(file_name, ios::out);
    file << "10000\n";

    for (int i = 0; i < 10000; i++)
	{
		file << rand()%10 << " ";
	}

    file.close();
}

void readFile(int *&a, int &n, string file_name)
{
    ifstream file(file_name, ios::in);
    int num, i = 0;
    file >> n;

    a = new int[n];
    
    while(file >> num)
    {
        a[i] = num;
        i++;
    }
}

void createTempArray(int *&b, int *a, int n)
{
    b = new int[n];
    for(int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

void commandline1 (int argc, char* argv[])
{
    int *a = NULL, *b = NULL, n;
    long long int comparision = 0;
    string file_name = "input.txt";
    createFile(file_name);
    readFile(a,n,file_name);

    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << argv[2] << "\n";
    cout << "Input file: " << argv[3] << "\n";
    cout << "Input size: " << n << "\n";
    cout << "-----------------------------------------\n";

    if(!strcmp(argv[4],"-time"))
    {
        clock_t start = clock();
        activateSort(argv[2],a,n);
        clock_t end = clock();
        cout << "Running time: " << double(end - start) << "ms\n";
    }
    else if(!strcmp(argv[4],"-comp"))
    {
        activateSortCount(argv[2],a,n,comparision);
        cout << "Comparision: " << comparision;
    }
    else
    {
        createTempArray(b,a,n);
        clock_t start = clock();
        activateSort(argv[2],a,n);
        clock_t end = clock();
        activateSortCount(argv[2],b,n,comparision);
        cout << "Running time: " << double(end - start) << "ms\n";
        cout << "Comparision: " << comparision;
    }
}
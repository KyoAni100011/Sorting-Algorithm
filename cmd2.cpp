#include <iostream>
#include "data_generate.h"
#include "merge_sort.h"
#include "bubble_sort.h"
#include "shaker_sort.h"
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstring>


using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 6)
    {
        int data_size;
        if (strcmp(argv[1], "-a") == 0)
        {
            cout << "Run cmd2";
            // input size
            if (atoi(argv[3]) <= 1000000 && atoi(argv[3]) > 0)
                data_size = atoi(argv[3]);
            else
            {
                cout << "syntax error" << endl;
                return 0;
            }
        }

        int *a = new int[data_size];

        // type
        /*
            • -rand: randomized data 0
            • -sorted: sorted data 1
            • -rev: reverse sorted data 2
            • -nsorted: nearly sorted data 3
        */
        string data_type;
        if (strcmp(argv[4], "-rand") == 0)
        {
            GenerateData(a, data_size, 0);
            data_type = "Randomized Data ";
        }
        else if (strcmp(argv[4], " -sorted") == 0)
        {
            GenerateData(a, data_size, 1);
            data_type = "Sorted Data ";
        }
        else if (strcmp(argv[4], "-rev") == 0)
        {
            GenerateData(a, data_size, 2);
            data_type = "Reverse Sorted Data ";
        }
        else if (strcmp(argv[4], "-nsorted") == 0)
        {
            GenerateData(a, data_size, 3);
            data_type = "Nearly Sorted Data ";
        }
        else
        {
            cout << "syntax error" << endl;
            return 0;
        }

        // initialized count_compares
        long long int count_compares = 0;

        clock_t start = clock();

        if (strcmp(argv[2], "merge-sort") == 0)
            mergeSort(a, 0, data_size - 1, count_compares);
        if (strcmp(argv[2], "bubble-sort") == 0)
            bubbleSort(a, data_size, count_compares);
        if (strcmp(argv[2], "shaker-sort") == 0)
            shakerSort(a, data_size, count_compares);

        clock_t end = clock();

        delete[] a;

        if (strcmp(argv[5], "-time") == 0)
            cout << "Running time: " << end - start << endl;

        else if (strcmp(argv[5], "-comp") == 0)
        {
            cout << "Comparisons: " << count_compares << endl;
        }
        else if (strcmp(argv[5], "-both") == 0)
        {
            cout << "Running time: " << end - start << endl;
            cout << "Comparisons: " << count_compares << endl;
        }
        else
        {
            cout << "syntax error" << endl;
            return 0;
        }
    }

    else if (strcmp(argv[1], "-c") == 0)
    {
        cout << "Run cmd5";
    }

    return 0;
}


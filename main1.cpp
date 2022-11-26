#include "merge_sort.h"
#include "bubble_sort.h"
#include "shaker_sort.h"
#include "data_generate.h"
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

void tempArray (int *a, int *b, int n){
    for (int i = 0; i < n; i++){
        b[i] = a[i];
    }
}

void output (int *a, int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main (int argc, char *argv[]){
    //data Size
    int size[6] = {10000, 30000, 50000, 100000, 300000, 500000};

    //size
    int data_size, flag = 0; 
    
    for (int i = 0; i < sizeof(size); i++){
        if (atoi(argv[4]) == size[i]) {
            data_size = size[i];
            flag = 1;
        }
    } 

    if (!flag) return 0;

    //initialized array
    int *a = new int [data_size];
    int *array1 = new int [data_size];
    int *array2 = new int [data_size];

    //type
    /* 
        • -rand: randomized data 0
        • -sorted: sorted data 1
        • -rev: reverse sorted data 2
        • -nsorted: nearly sorted data 3
    */
    string data_type; 
    if (strcmp(argv[5], "-rand") == 0) {
        GenerateData (a, data_size, 0);
        data_type = "Randomized Data ";
    }
    else if (strcmp(argv[5], " -sorted") == 0) {
        GenerateData (a, data_size, 1);
        data_type = "Sorted Data ";
    }
    else if (strcmp(argv[5], "-rev") == 0) {
        GenerateData (a, data_size, 2);
        data_type = "Reverse Sorted Data ";
    }
    else if (strcmp(argv[5], "-nsorted") == 0) {
        GenerateData (a, data_size, 3);
        data_type = "Nearly Sorted Data ";
    }

    cout << '\n' << "Algorithm: " << argv[2] << " | " << argv[3];
    cout << '\n' << "Input size: " << data_size;
    cout << '\n' << "Input order: " << data_type;
    cout << "\n--------------------------------\n";

    if (argc == 6){
        //cmd line 5
        if (strcmp(argv[1],"-c") == 0){

            //initialized count_compares
            long long int count_compares1 = 0, count_compares2 = 0;
            
            //Algorithm1
            tempArray (a, array1, data_size);

            clock_t start1 = clock();

            if (strcmp(argv[2], "merge-sort") == 0) mergeSort(array1, 0, data_size - 1, count_compares1);
            if (strcmp(argv[2], "bubble-sort") == 0) bubbleSort (array1, data_size, count_compares1);
            if (strcmp(argv[2], "shaker-sort") == 0) shakerSort(array1, data_size, count_compares1);
            
            clock_t end1 = clock();

            delete [] array1;

            //Algorithm2
            tempArray (a, array2, data_size);

            clock_t start2 = clock();

            if (strcmp(argv[3], "merge-sort") == 0) mergeSort(array2, 0, data_size - 1, count_compares2);
            if (strcmp(argv[3], "bubble-sort") == 0) bubbleSort (array2, data_size, count_compares2);
            if (strcmp(argv[3], "shaker-sort") == 0) shakerSort(array2, data_size, count_compares2);
           
            clock_t end2 = clock();

            delete [] array2;

            cout << "Running time: " << end1 - start1 << " | " << end2 - start2 << '\n';
            cout << "Comparisons: " << count_compares1 << " | " << count_compares2 << '\n';
        }
        //cmd 2
        
    }

    return 0;
}

#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "data_generate.h"
#include "sort.h"
#include "sortCompare.h"

using namespace std;

string dataOrder (int *a, int data_size, string data_type){
    if (data_type == "-rand"){
        GenerateData(a, data_size,0);
        return "Randomized Data ";
    }
    else if (data_type == "-sorted") {
        GenerateData (a, data_size, 1);
        return "Sorted Data ";
    }
    else if (data_type == "-rev") {
        GenerateData (a, data_size, 2);
        return "Reverse Sorted Data ";
    }
    else if (data_type == "-nsorted") {
        GenerateData (a, data_size, 3);
        return "Nearly Sorted Data ";
    }

    return 0;
}

void createTempArray (int *a, int *b, int n){
    for (int i = 0; i < n; i++){
        b[i] = a[i];
    }
}

void inputFile (string data_type, int *a, int size, string file_name){
    ofstream f(file_name , ios::out);

    f << data_type << '\n';

    for (int i = 0; i < size; i++){
        if (a[i] % 10 == 0) f << '\n';
        f << a[i] << " ";
    }

    f.close();
}

void commandline5 (int argc, char* argv[]){
    int data_size = atoi(argv[4]);
    int *a = new int [data_size];
    int *array1 = new int [data_size];
    int *array2 = new int [data_size];

    string data_type = dataOrder (a,data_size,argv[5]);

    cout << '\n' << "Algorithm: " << argv[2] << " | " << argv[3];
    cout << '\n' << "Input size: " << data_size;
    cout << '\n' << "Input order: " << data_type;
    cout << "\n--------------------------------\n";

    //initialized count_compares
    long long int count_compares1 = 0, count_compares2 = 0;
            
    //Algorithm1
    cout << "FUCK1" << endl;
    createTempArray (a, array1, data_size);
    cout << "FUCK2" << endl;
    inputFile(data_type, a, data_size, "input.txt");

    clock_t start1 = clock();

    activateSortCount(argv[2],array1,data_size,count_compares1);
    cout << "FUCK3";
    clock_t end1 = clock();

    delete [] array1;

    // //Algorithm2
    createTempArray (a, array2, data_size);

    clock_t start2 = clock();

    activateSortCount(argv[3],a,data_size,count_compares2);
           
    clock_t end2 = clock();

    delete [] array2;

    cout << "Running time: " << end1 - start1 << " | " << end2 - start2 << '\n';
    cout << "Comparisons: " << count_compares1 << " | " << count_compares2 << '\n';
}


void commandline4 (int argc, char* argv[]){
    ifstream fileIn;
    fileIn.open(argv[4] , ios:: in);
    int data_size = 0;
    while(!fileIn.eof()){
        data_size++;
    }
    int *a = new int [data_size];
    int *array = new int [data_size];
    for(int i = 0; i < data_size;i++){
        fileIn >> array[i];
    }

    string data_type = dataOrder (a,data_size,argv[5]);

    cout << '\n' << "Algorithm: " << argv[2] << " | " << argv[3];
    cout << '\n' << "Input file: " << argv[4];
    cout << '\n' << "Input order: " << data_size;
    cout << "\n--------------------------------\n";

    //initialized count_compares
    long long int count_compares1 = 0, count_compares2 = 0;
            
    //Algorithm1

    clock_t start1 = clock();

    activateSortCount(argv[2],array,data_size,count_compares1);
            
    clock_t end1 = clock();

    delete [] array;

    // //Algorithm2

    clock_t start2 = clock();

    activateSortCount(argv[3],array,data_size,count_compares2);
           
    clock_t end2 = clock();

    delete [] array;

    cout << "Running time: " << end1 - start1 << " | " << end2 - start2 << '\n';
    cout << "Comparisons: " << count_compares1 << " | " << count_compares2 << '\n';
    fileIn.close();
}
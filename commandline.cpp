#include "commandline.h"

string dataOrder(int *a, int data_size, string data_type)
{
    if (data_type == "-rand")
    {
        GenerateData(a, data_size, 0);
        return "Randomized Data ";
    }
    else if (data_type == "-sorted")
    {
        GenerateData(a, data_size, 1);
        return "Sorted Data ";
    }
    else if (data_type == "-rev")
    {
        GenerateData(a, data_size, 2);
        return "Reverse Sorted Data ";
    }
    else if (data_type == "-nsorted")
    {
        GenerateData(a, data_size, 3);
        return "Nearly Sorted Data ";
    }

    return 0;
}

void createTempArray(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

void writeFile(string data_type, int *a, int size, string file_name)
{
    ofstream file(file_name, ios::out);

    file << data_type << '\n';
    file << size << "\n";

    for (int i = 0; i < size; i++)
    {
        file << a[i] << " ";
    }

    file.close();
}

void readFile(int *&a, int &n, string file_name)
{
    ifstream file(file_name, ios::in);
    int num, i = 0;
    file >> n;

    a = new int[n];

    while (file >> num)
    {
        a[i] = num;
        i++;
    }

    file.close();
}

void commandline1(int argc, char *argv[])
{
    int *a = NULL, *b = NULL, n;
    long long int comparision = 0;
    readFile(a, n, argv[3]);

    b = new int[n];

    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << argv[2] << "\n";
    cout << "Input file: " << argv[3] << "\n";
    cout << "Input size: " << n << "\n";
    cout << "-----------------------------------------\n";

    if (!strcmp(argv[4], "-time"))
    {
        cout << "check";
        clock_t start = clock();
        activateSort(argv[2], a, n);
        clock_t end = clock();
        cout << "Running time: " << double(end - start) / CLOCKS_PER_SEC * 1000 << "ms\n";
    }
    else if (!strcmp(argv[4], "-comp"))
    {
        activateSortCount(argv[2], a, n, comparision);
        cout << "Comparision: " << comparision;
    }
    else
    {
        createTempArray(a, b, n);
        clock_t start = clock();
        activateSort(argv[2], a, n);
        clock_t end = clock();
        activateSortCount(argv[2], b, n, comparision);
        cout << "Running time: " << double(end - start) / CLOCKS_PER_SEC * 1000 << "ms\n";
        cout << "Comparision: " << comparision;
    }

    // for(int i = 0; i < n; i++) cout << a[i] << " ";

    writeFile("", a, n, "output.txt");
}

void commandline2(int argc, char *argv[])
{
    int data_size = atoi(argv[3]);
    int *a = new int[data_size], *b = new int[data_size];
    long long int comparision = 0;
    string data_type = dataOrder(a, data_size, argv[4]);

    writeFile(data_type, a, data_size, "input.txt");

    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << argv[2] << "\n";
    cout << "Input size: " << data_size << "\n";
    cout << "Input order: " << data_type << "\n";
    cout << "-----------------------------------------\n";

    if (!strcmp(argv[5], "-time"))
    {
        clock_t start = clock();
        activateSort(argv[2], a, data_size);
        clock_t end = clock();
        cout << "Running time: " << double(end - start) / CLOCKS_PER_SEC * 1000 << "ms\n";
    }
    else if (!strcmp(argv[5], "-comp"))
    {
        activateSortCount(argv[2], a, data_size, comparision);
        cout << "Comparision: " << comparision;
    }
    else if (!strcmp(argv[5], "-both"))
    {
        createTempArray(a, b, data_size);
        clock_t start = clock();
        activateSort(argv[2], a, data_size);
        clock_t end = clock();
        activateSortCount(argv[2], b, data_size, comparision);
        cout << "Running time: " << double(end - start) / CLOCKS_PER_SEC * 1000 << "ms\n";
        cout << "Comparision: " << comparision;
    }
    writeFile(data_type, a,data_size,"output.txt");
    delete[] a;
    delete[] b;
}

void commandline3(int argc, char *argv[])
{
    int data_size = atoi(argv[3]);
    int *array1 = new int[data_size];
    int *array2 = new int[data_size];
    int *array3 = new int[data_size];
    int *array4 = new int[data_size];

    string data_type1 = dataOrder(array1, data_size, "-rand");
    writeFile(data_type1, array1, data_size, "input_1.txt");
    string data_type2 = dataOrder(array2, data_size, "-nsorted");
    writeFile(data_type2, array2, data_size, "input_2.txt");
    string data_type3 = dataOrder(array3, data_size, "-sorted");
    writeFile(data_type3, array3, data_size, "input_3.txt");
    string data_type4 = dataOrder(array4, data_size, "-rev");
    writeFile(data_type4, array4, data_size, "input_4.txt");

    cout << "\nAlgorithm: " << argv[2] << "\n";
    cout << "Input size: " << data_size << "\n\n";

    if (!strcmp(argv[4], "-comp"))
    {
        cout << "Input order: " << data_type1;
        cout << "\n--------------------------------\n";
        long long int count_compares1 = 0;
        activateSortCount(argv[2], array1, data_size, count_compares1);
        cout << "Comparisons: " << count_compares1 << "\n\n";

        cout << "Input order: " << data_type2;
        cout << "\n--------------------------------\n";
        long long int count_compares2 = 0;
        activateSortCount(argv[2], array2, data_size, count_compares2);
        cout << "Comparisons: " << count_compares2 << "\n\n";

        cout << "Input order: " << data_type3;
        cout << "\n--------------------------------\n";
        long long int count_compares3 = 0;
        activateSortCount(argv[2], array3, data_size, count_compares3);
        cout << "Comparisons: " << count_compares3 << "\n\n";

        cout << "Input order: " << data_type4;
        cout << "\n--------------------------------\n";
        long long int count_compares4 = 0;
        activateSortCount(argv[2], array4, data_size, count_compares4);
        cout << "Comparisons: " << count_compares4 << "\n\n";
    }
    else if (!strcmp(argv[4], "-time"))
    {
        cout << "Input order: " << data_type1;
        cout << "\n--------------------------------\n";
        clock_t start1 = clock();
        activateSort(argv[2], array1, data_size);
        clock_t end1 = clock();
        cout << "Running time: " << double(end1 - start1) / CLOCKS_PER_SEC * 1000 << "\n\n";

        cout << "Input order: " << data_type2;
        cout << "\n--------------------------------\n";
        clock_t start2 = clock();
        activateSort(argv[2], array2, data_size);
        clock_t end2 = clock();
        cout << "Running time: " << double(end2 - start2) / CLOCKS_PER_SEC * 1000 << "\n\n";

        cout << "Input order: " << data_type3;
        cout << "\n--------------------------------\n";
        clock_t start3 = clock();
        activateSort(argv[2], array3, data_size);
        clock_t end3 = clock();
        cout << "Running time: " << double(end3 - start3) / CLOCKS_PER_SEC * 1000 << "\n\n";

        cout << "Input order: " << data_type4;
        cout << "\n--------------------------------\n";
        clock_t start4 = clock();
        activateSort(argv[2], array4, data_size);
        clock_t end4 = clock();
        cout << "Running time: " << double(end4 - start4) / CLOCKS_PER_SEC * 1000 << "\n\n";
    }
    else if (!strcmp(argv[4], "-both"))
    {
        int *temp = new int[data_size];

        cout << "Input order: " << data_type1;
        cout << "\n--------------------------------\n";
        clock_t start1 = clock();
        createTempArray(array1, temp, data_size);
        activateSort(argv[2], temp, data_size);
        clock_t end1 = clock();
        cout << "Running time: " << double(end1 - start1) / CLOCKS_PER_SEC * 1000 << "\n";
        long long int count_compares1 = 0;
        activateSortCount(argv[2], array1, data_size, count_compares1);
        cout << "Comparisons: " << count_compares1 << "\n\n";

        cout << "Input order: " << data_type2;
        cout << "\n--------------------------------\n";
        clock_t start2 = clock();
        createTempArray(array2, temp, data_size);
        activateSort(argv[2], temp, data_size);
        clock_t end2 = clock();
        cout << "Running time: " << double(end2 - start2) / CLOCKS_PER_SEC * 1000 << "\n";
        long long int count_compares2 = 0;
        activateSortCount(argv[2], array2, data_size, count_compares2);
        cout << "Comparisons: " << count_compares2 << "\n\n";

        cout << "Input order: " << data_type3;
        cout << "\n--------------------------------\n";
        clock_t start3 = clock();
        createTempArray(array3, temp, data_size);
        activateSort(argv[2], temp, data_size);
        clock_t end3 = clock();
        cout << "Running time: " << double(end3 - start3) / CLOCKS_PER_SEC * 1000 << "\n";
        long long int count_compares3 = 0;
        activateSortCount(argv[2], array3, data_size, count_compares3);
        cout << "Comparisons: " << count_compares3 << "\n\n";

        cout << "Input order: " << data_type4;
        cout << "\n--------------------------------\n";
        clock_t start4 = clock();
        createTempArray(array4, temp, data_size);
        activateSort(argv[2], temp, data_size);
        clock_t end4 = clock();
        cout << "Running time: " << double(end4 - start4) / CLOCKS_PER_SEC * 1000 << "\n";
        long long int count_compares4 = 0;
        activateSortCount(argv[2], array4, data_size, count_compares4);
        cout << "Comparisons: " << count_compares4 << "\n\n";

        delete[] temp;
    }

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
}

void commandline4(int argc, char *argv[])
{
    int *a = NULL, *b = NULL, data_size;
    long long int count_compares1 = 0, count_compares2 = 0;

    readFile(a, data_size, argv[4]);
    b = new int[data_size];

    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << argv[2] << " | " << argv[3] << "\n";
    cout << "Input file: " << argv[4] << "\n";
    cout << "Input size: " << data_size << "\n";
    cout << "----------------------------------------------\n";

    // Algorithm1
    createTempArray(a, b, data_size);
    clock_t start1 = clock();
    activateSort(argv[2], b, data_size);
    clock_t end1 = clock();
    createTempArray(a, b, data_size);
    activateSortCount(argv[2], b, data_size, count_compares1);
    // Algorithm2
    createTempArray(a, b, data_size);
    clock_t start2 = clock();
    activateSort(argv[3], b, data_size);
    clock_t end2 = clock();
    createTempArray(a, b, data_size);
    activateSortCount(argv[3], b, data_size, count_compares2);

    cout << "Running time: " << (double)(end1 - start1) / CLOCKS_PER_SEC * 1000 << "ms | " << (double)(end2 - start2) / CLOCKS_PER_SEC * 1000 << "ms\n";
    cout << "Comparisons: " << count_compares1 << " | " << count_compares2 << '\n';

    writeFile("", b, data_size, "output.txt");
}

void commandline5(int argc, char *argv[])
{
    int data_size = atoi(argv[4]);
    int *a = new int[data_size], *b = new int[data_size];
    long long int count_compares1 = 0, count_compares2 = 0;

    string data_type = dataOrder(a, data_size, argv[5]);

    writeFile(data_type, a, data_size, "input.txt");

    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << argv[2] << " | " << argv[3] << "\n";
    cout << "Input size: " << data_size << "\n";
    cout << "Input order: " << data_type << "\n";
    cout << "---------------------------------------------\n";

    // Algorithm1
    createTempArray(a, b, data_size);
    clock_t start1 = clock();
    activateSort(argv[2], b, data_size);
    clock_t end1 = clock();
    createTempArray(a, b, data_size);
    activateSortCount(argv[2], b, data_size, count_compares1);

    // //Algorithm2
    createTempArray(a, b, data_size);
    clock_t start2 = clock();
    activateSort(argv[3], b, data_size);
    clock_t end2 = clock();
    createTempArray(a, b, data_size);
    activateSortCount(argv[3], b, data_size, count_compares2);

    cout << "Running time: " << (double)(end1 - start1) / CLOCKS_PER_SEC * 1000 << "ms | " << (double)(end2 - start2) / CLOCKS_PER_SEC * 1000 << "ms\n";
    cout << "Comparisons: " << count_compares1 << " | " << count_compares2 << '\n';

    delete[] a;
    delete[] b;
}

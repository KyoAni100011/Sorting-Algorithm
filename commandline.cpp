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

void createFile(string file_name)
{
    srand((unsigned int)time(NULL));

    ofstream file(file_name, ios::out);
    file << "10000\n";

    for (int i = 0; i < 10000; i++)
    {
        file << rand() % 100 << " ";
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
}

void write(int *a, int n, string file_name)
{
    ofstream file(file_name, ios::out);
    for(int i = 0; i < n; i++)
        file << a[i] << " ";
    file.close();
}

void commandline1(int argc, char *argv[])
{
    int *a = NULL, *b = NULL, n;
    long long int comparision = 0;
    createFile(argv[3]);
    readFile(a, n, argv[3]);

    b = new int[n];

    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << argv[2] << "\n";
    cout << "Input file: " << argv[3] << "\n";
    cout << "Input size: " << n << "\n";
    cout << "-----------------------------------------\n";

    if (!strcmp(argv[4], "-time"))
    {
        clock_t start = clock();
        activateSort(argv[2], a, n);
        clock_t end = clock();
        cout << "Running time: " << double(end - start) << "ms\n";
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
        cout << "Running time: " << double(end - start) << "ms\n";
        cout << "Comparision: " << comparision;
    }

    writeFile("Random data", a, n, "output.txt");
}

void commandline4(int argc, char *argv[])
{
    int *a = NULL, *b = NULL, data_size;
    long long int count_compares1 = 0, count_compares2 = 0;

    readFile(a,data_size,argv[4]);

    b = new int[data_size];

    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << argv[2] << " | " << argv[3] << "\n";
    cout << "Input file: " << argv[4] << "\n";
    cout << "Input size: " << data_size << "\n";
    cout << "----------------------------------------------\n";

    // Algorithm1
    createTempArray(a,b,data_size);
    clock_t start1 = clock();
    activateSort(argv[2],b,data_size);
    clock_t end1 = clock();
    createTempArray(a,b,data_size);
    activateSortCount(argv[2],b,data_size,count_compares1);

    // Algorithm2
    createTempArray(a,b,data_size); 
    clock_t start2 = clock();
    activateSort(argv[3], b, data_size);
    clock_t end2 = clock();
    createTempArray(a,b,data_size);
    activateSortCount(argv[3],b,data_size,count_compares2);

    cout << "Running time: " << end1 - start1 << "ms | " << end2 - start2 << "ms\n";
    cout << "Comparisons: " << count_compares1 << " | " << count_compares2 << '\n';

    writeFile("Random data", b, data_size, "output.txt");
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
    createTempArray(a,b,data_size);
    clock_t start1 = clock();
    activateSort(argv[2], b, data_size);
    clock_t end1 = clock();
    createTempArray(b,a,data_size);
    activateSortCount(argv[2],b,data_size,count_compares1);

    // //Algorithm2
    createTempArray(a,b,data_size);
    clock_t start2 = clock();
    activateSort(argv[3], b, data_size);
    clock_t end2 = clock();
    createTempArray(a,b,data_size);
    activateSortCount(argv[3],b,data_size,count_compares2);

    cout << "Running time: " << end1 - start1 << " | " << end2 - start2 << '\n';
    cout << "Comparisons: " << count_compares1 << " | " << count_compares2 << '\n';
}


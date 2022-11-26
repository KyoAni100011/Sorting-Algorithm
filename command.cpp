#include "command.h"

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
    else
    {
        cout << "Error!";
        exit(1);
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

void createFile(string file_name)
{
    srand((unsigned int)time(NULL));

    ofstream file(file_name, ios::out);
    file << "10000\n";

    for (int i = 0; i < 10000; i++)
    {
        file << rand() % 10 << " ";
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

void writeFile(int *a, int n, string file_name)
{
    ofstream file(file_name, ios::out);

    file << n << endl;

    for (int i = 0; i < n; i++)
        file << a[i] << " ";

    file.close();
}

void commandline1(int argc, char *argv[])
{
    int *a = NULL, *b = NULL, n;
    long long int comparision = 0;
    string file_name = argv[3];
    createFile(file_name);
    readFile(a, n, file_name);

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
        cout << "Running time: " << double(end - start) << "\n";
        writeFile(a, n, "output.txt");
    }
    else if (!strcmp(argv[4], "-comp"))
    {
        activateSortCount(argv[2], a, n, comparision);
        cout << "Comparision: " << comparision;
        writeFile(a, n, "output.txt");
    }
    else if (!strcmp(argv[4], "-both"))
    {
        createTempArray(b, a, n);
        clock_t start = clock();
        activateSort(argv[2], a, n);
        clock_t end = clock();
        activateSortCount(argv[2], b, n, comparision);
        cout << "Running time: " << double(end - start) << "\n";
        cout << "Comparision: " << comparision;
        writeFile(a, n, "output.txt");
    }
    else
    {
        cout << "ERROR!";
        exit(1);
    }

    delete[] a;
    delete[] b;
}

void commandline2(int argc, char *argv[])
{
    int *a = NULL, *b = NULL, data_size;
    long long int comparision = 0;
    data_size = atoi(argv[3]);

    if (data_size > 1000000)
    {
        cout << "ERROR!";
        exit(1);
    }

    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << argv[2] << "\n";
    cout << "Input size: " << argv[3] << "\n";
    cout << "Input order: " << argv[4] << "\n";
    cout << "-----------------------------------------\n";

    if (!strcmp(argv[5], "-time"))
    {
        clock_t start = clock();
        activateSort(argv[2], a, data_size);
        clock_t end = clock();
        cout << "Running time: " << double(end - start) << "\n";
        writeFile(a, data_size, "output.txt");
    }
    else if (!strcmp(argv[4], "-comp"))
    {
        activateSortCount(argv[2], a, data_size, comparision);
        cout << "Comparision: " << comparision;
        writeFile(a, data_size, "output.txt");
    }
    else if (!strcmp(argv[4], "-both"))
    {
        createTempArray(b, a, data_size);
        clock_t start = clock();
        activateSort(argv[2], a, data_size);
        clock_t end = clock();
        activateSortCount(argv[2], b, data_size, comparision);
        cout << "Running time: " << double(end - start) << "\n";
        cout << "Comparision: " << comparision;
        writeFile(a, data_size, "output.txt");
    }
    else
    {
        cout << "ERROR!";
        exit(1);
    }

    delete[] a;
    delete[] b;
}

void commandline3(int argc, char *argv[])
{
    int data_size = atoi(argv[3]);
    if (data_size > 1000000)
    {
        cout << "ERROR!";
        exit(1);
    }

    int *array1 = new int[data_size];
    int *array2 = new int[data_size];
    int *array3 = new int[data_size];
    int *array4 = new int[data_size];

    string data_type1 = dataOrder(array1, data_size, "-rand");
    writeFile(array1, data_size, "input_1.txt");
    string data_type2 = dataOrder(array2, data_size, "-nsorted");
    writeFile(array2, data_size, "input_2.txt");
    string data_type3 = dataOrder(array3, data_size, "-sorted");
    writeFile(array3, data_size, "input_3.txt");
    string data_type4 = dataOrder(array4, data_size, "-rev");
    writeFile(array4, data_size, "input_4.txt");

    cout << '\n'
         << "Algorithm: " << argv[2] << " | " << argv[3];
    cout << '\n'
         << "Input size: " << data_size;
    cout << '\n';

    cout << "Input order: " << data_type1;
    cout << "\n--------------------------------\n";

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
        cout << "Running time: " << double(end1 - start1) << "\n\n";

        cout << "Input order: " << data_type2;
        cout << "\n--------------------------------\n";
        clock_t start2 = clock();
        activateSort(argv[2], array2, data_size);
        clock_t end2 = clock();
        cout << "Running time: " << double(end2 - start2) << "\n\n";

        cout << "Input order: " << data_type3;
        cout << "\n--------------------------------\n";
        clock_t start3 = clock();
        activateSort(argv[2], array3, data_size);
        clock_t end3 = clock();
        cout << "Running time: " << double(end3 - start3) << "\n\n";

        cout << "Input order: " << data_type4;
        cout << "\n--------------------------------\n";
        clock_t start4 = clock();
        activateSort(argv[2], array4, data_size);
        clock_t end4 = clock();
        cout << "Running time: " << double(end4 - start4) << "\n\n";
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
        cout << "Running time: " << double(end1 - start1) << "\n";
        long long int count_compares1 = 0;
        activateSortCount(argv[2], array1, data_size, count_compares1);
        cout << "Comparisons: " << count_compares1 << "\n\n";

        cout << "Input order: " << data_type2;
        cout << "\n--------------------------------\n";
        clock_t start2 = clock();
        createTempArray(array2, temp, data_size);
        activateSort(argv[2], temp, data_size);
        clock_t end2 = clock();
        cout << "Running time: " << double(end2 - start2) << "\n";
        long long int count_compares2 = 0;
        activateSortCount(argv[2], array2, data_size, count_compares2);
        cout << "Comparisons: " << count_compares2 << "\n\n";

        cout << "Input order: " << data_type3;
        cout << "\n--------------------------------\n";
        clock_t start3 = clock();
        createTempArray(array3, temp, data_size);
        activateSort(argv[2], temp, data_size);
        clock_t end3 = clock();
        cout << "Running time: " << double(end3 - start3) << "\n";
        long long int count_compares3 = 0;
        activateSortCount(argv[2], array3, data_size, count_compares3);
        cout << "Comparisons: " << count_compares3 << "\n\n";

        cout << "Input order: " << data_type4;
        cout << "\n--------------------------------\n";
        clock_t start4 = clock();
        createTempArray(array4, temp, data_size);
        activateSort(argv[2], temp, data_size);
        clock_t end4 = clock();
        cout << "Running time: " << double(end4 - start4) << "\n";
        long long int count_compares4 = 0;
        activateSortCount(argv[2], array4, data_size, count_compares4);
        cout << "Comparisons: " << count_compares4 << "\n\n";

        delete[] temp;
    }
    else
    {
        cout << "ERROR!";
        exit(1);
    }

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
}

void commandline4(int argc, char *argv[])
{
    ifstream fileIn;
    fileIn.open(argv[4], ios::in);
    int data_size = 0;
    while (!fileIn.eof())
    {
        data_size++;
    }
    int *a = new int[data_size];
    int *array = new int[data_size];
    for (int i = 0; i < data_size; i++)
    {
        fileIn >> array[i];
    }

    string data_type = dataOrder(a, data_size, argv[5]);

    cout << '\n'
         << "Algorithm: " << argv[2] << " | " << argv[3];
    cout << '\n'
         << "Input file: " << argv[4];
    cout << '\n'
         << "Input order: " << data_size;
    cout << "\n--------------------------------\n";

    // initialized count_compares
    long long int count_compares1 = 0, count_compares2 = 0;

    // Algorithm1

    clock_t start1 = clock();

    activateSortCount(argv[2], array, data_size, count_compares1);

    clock_t end1 = clock();

    delete[] array;

    // //Algorithm2

    clock_t start2 = clock();

    activateSortCount(argv[3], array, data_size, count_compares2);

    clock_t end2 = clock();

    delete[] array;

    cout << "Running time: " << end1 - start1 << " | " << end2 - start2 << '\n';
    cout << "Comparisons: " << count_compares1 << " | " << count_compares2 << '\n';
    fileIn.close();
}

void commandline5(int argc, char *argv[])
{
    int data_size = atoi(argv[4]);
    int *a = new int[data_size];
    int *array1 = new int[data_size];
    int *array2 = new int[data_size];

    if (data_size > 1000000)
    {
        cout << "ERROR!";
        exit(1);
    }

    string data_type = dataOrder(a, data_size, argv[5]);

    cout << '\n'
         << "Algorithm: " << argv[2] << " | " << argv[3];
    cout << '\n'
         << "Input size: " << data_size;
    cout << '\n'
         << "Input order: " << data_type;
    cout << "\n--------------------------------\n";

    // initialized count_compares
    long long int count_compares1 = 0, count_compares2 = 0;

    // Algorithm1
    createTempArray(a, array1, data_size);

    clock_t start1 = clock();
    activateSortCount(argv[2], array1, data_size, count_compares1);
    clock_t end1 = clock();

    delete[] array1;

    // //Algorithm2
    createTempArray(a, array2, data_size);

    clock_t start2 = clock();
    activateSortCount(argv[3], a, data_size, count_compares2);
    clock_t end2 = clock();

    delete[] array2;

    cout << "Running time: " << end1 - start1 << " | " << end2 - start2 << '\n';
    cout << "Comparisons: " << count_compares1 << " | " << count_compares2 << '\n';
}
#include "test.h"

void testAll()
{
	int size[6] = {10000, 50000, 30000 ,100000};
	int type = 0;
	long long int compare;
	ofstream ofs;
	clock_t begin;
	clock_t end;
	ofs.open("result.txt", ios::out);
	while (type < 4)
	{
		switch (type)
		{
		case 0:
			ofs << "RANDOM DATA" << endl;
			break;
		case 1:
			ofs << "SORTED DATA" << endl;
			break;
		case 2:
			ofs << "REVERSE DATA" << endl;
			break;
		case 3:
			ofs << "NEARLY SORTED DATA" << endl;
			break;
		};
		for (int j = 0; j < 4; j++)
		{
			int n = size[j];
			int *a = new int[n];
			int *b = new int[n];
			GenerateData(a, n, type);
			ofs << "==============" << n << "==============" << endl
				<< endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			selectionSort(b, n);
			double timeUsed = (double)(clock() - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			selectionSortCount(b, n, compare);
			ofs << "Selection Sort: " << timeUsed << "ms" << endl;
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			insertionSort(b, n);
			end = clock();
			timeUsed = (double)(end - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			insertionSortCount(b, n, compare);
			ofs << "Insertion Sort: \n";
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			bubbleSort(b, n);
			timeUsed = ((double)clock() - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			bubbleSortCount(b, n, compare);
			ofs << "Bubble Sort: \n";
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			shakerSort(b, n);
			timeUsed = ((double)clock() - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			shakerSortCount(b, n, compare);
			ofs << "Shaker Sort: " << timeUsed << "ms" << endl;
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			shellSort(b, n);
			timeUsed = ((double)clock() - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			shellSortCount(b, n, compare);
			ofs << "Shell Sort: " << timeUsed << "ms" << endl;
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			heapSort(b, n);
			timeUsed = ((double)clock() - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			heapSortCount(b, n, compare);
			ofs << "Heap Sort: " << timeUsed << "ms" << endl;
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			mergeSort(b, 0, n - 1);
			timeUsed = ((double)clock() - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			mergeSortCount(b, 0, n - 1, compare);
			ofs << "Merge Sort: " << timeUsed << "ms" << endl;
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			quickSort(b, 0, n - 1);
			timeUsed = ((double)clock() - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			quickSortCount(b, 0, n - 1, compare);
			ofs << "Quick Sort: " << timeUsed << "ms" << endl;
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			countingSort(b, n);
			timeUsed = ((double)clock() - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			countingSortCount(b, n, compare);
			ofs << "Counting Sort: " << timeUsed << "ms" << endl;
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			radixSort(b, n);
			timeUsed = ((double)clock() - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			radixSortCount(b, n, compare);
			ofs << "Radix Sort: " << timeUsed << "ms" << endl;
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			flashSort(b, n);
			timeUsed = ((double)clock() - begin) / CLOCKS_PER_SEC * 1000;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			compare = 0;
			flashSortCount(b, n, compare);
			ofs << "Flash Sort: " << timeUsed << "ms" << endl;
			ofs << "Running time: " << timeUsed << "ms" << endl;
			ofs << "Comparision : " << compare << endl;

			ofs << endl;
			delete[] a;
			delete[] b;
		}
		type++;
	}
	ofs.close();
}
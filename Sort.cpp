#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>

#include <stdlib.h>
#include <time.h>

#include "sort.h"

using namespace std;

void testAllSort(int *b, int *a, int n)
{
    b = new int[n];
    clock_t start1;
    clock_t end1;

    // for(int i = 0; i < n; i++) b[i] = a[i];
    // clock_t start1 = clock();
    // selectionSort(b,n);
    // clock_t end1 = clock();
    // cout << "Selection Sort: " << double(end1-start1) << "ms\n";

    // for(int i = 0; i < n; i++) b[i] = a[i];
    // start1 = clock();
    // insertionSort(b,n);
    // end1 = clock();
    // cout << "Insertion Sort: " << double(end1-start1) << "ms\n";

    // for(int i = 0; i < n; i++) b[i] = a[i];
    // start1 = clock();
    // bubbleSort(b,n);
    // end1 = clock();
    // cout << "Bubble Sort: " << double(end1-start1) << "ms\n";

    // for(int i = 0; i < n; i++) b[i] = a[i];
    // start1 = clock();
    // shakerSort(b,n);
    // end1 = clock();
    // cout << "Shaker Sort: " << double(end1-start1) << "ms\n";
    
    // for(int i = 0; i < n; i++) b[i] = a[i];
    // start1 = clock();
    // shellSort(b,n);
    // end1 = clock();
    // cout << "Shell Sort: " << double(end1-start1) << "ms\n";

    // for(int i = 0; i < n; i++) b[i] = a[i];
    // start1 = clock();
    // heapSort(b,n);
    // end1 = clock();
    // cout << "Heap Sort: " << double(end1-start1) << "ms\n";

    // for(int i = 0; i < n; i++) b[i] = a[i];
    // start1 = clock();
    // mergeSort(b,0,n - 1);
    // end1 = clock();
    // cout << "Merge Sort: " << double(end1-start1) << "ms\n";

    // for(int i = 0; i < n; i++) b[i] = a[i];
    // start1 = clock();
    // quickSort(b,0,n - 1);
    // end1 = clock();
    // cout << "Quick Sort: " << double(end1-start1) << "ms\n";

    // for(int i = 0; i < n; i++) b[i] = a[i];
    // start1 = clock();
    // countingSort(b,n);
    // end1 = clock();
    // cout << "Counting Sort: " << double(end1-start1) << "ms\n";
    for(int i = 0; i < n; i++) cout << b[i] << " ";

    // for(int i = 0; i < n; i++) b[i] = a[i];
    // start1 = clock();
    // radixSort(b,n);
    // end1 = clock();
    // cout << "Radix Sort: " << double(end1-start1) << "ms\n";

    // for(int i = 0; i < n; i++) b[i] = a[i];
    // start1 = clock();
    // flashSort(b,n);
    // end1 = clock();
    // cout << "Flash Sort: " << double(end1-start1) << "ms\n";
}

void activateSort(char *sort_type, int *a, int n)
{
    if(!strcmp(sort_type,"selection-sort")) selectionSort(a,n);
    else if (!strcmp(sort_type, "insertion-sort")) insertionSort(a,n);
    else if (!strcmp(sort_type, "bubble-sort")) bubbleSort(a,n);
    else if (!strcmp(sort_type, "shaker-sort")) shakerSort(a,n);
    else if (!strcmp(sort_type, "shell-sort")) shellSort(a,n);
    else if (!strcmp(sort_type, "heap-sort")) heapSort(a,n);
    else if (!strcmp(sort_type, "merge-sort")) mergeSort(a,0,n - 1);
    else if (!strcmp(sort_type, "quick-sort")) quickSort(a,0,n - 1);
    else if (!strcmp(sort_type, "counting-sort")) countingSort(a,n);
    else if (!strcmp(sort_type, "radix-sort")) radixSort(a,n);
    else if (!strcmp(sort_type, "flash-sort")) flashSort(a,n);
}

void selectionSort(int *a, int n)
{
	int max;
	for(int i = n-1; i > 0; i--)
	{
		max = i;
		for(int j = i-1; j >= 0; j--)
		{
			if(a[j] > a[max])
			{
				max = j;
			}
		}
		if(max != i)
		{
			swap(a[max],a[i]);
		}
	}
}

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i;
        while ((j > 0) && (a[j - 1] > key))
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = key;
    }
}

void bubbleSort (int *a, int n)
{
    for (int j = 1; j < n ; j++)
    {
        bool flag = false;
        for (int i = n - 1; i >= j; i--)
        {
            if (a[i] < a[i-1]) 
            {
                swap(a[i], a[i-1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void shakerSort (int *a, int n)
{
    int left = 0, right = n - 1, k = -1;   

    while (left < right){
        int tmp_k = k;

        for (int i = right; i > left; i--)
        {
            if (a[i] < a[i-1])
            {
                swap(a[i], a[i-1]);
                k = i - 1;
            }
        }

        if (tmp_k == k) break;

        left = k + 1;   

        for (int i = left; i < right; i++)
        {
            if (a[i+1] < a[i])
            {
                swap(a[i], a[i+1]);
                k = i + 1; 
            }
        }

        right = k - 1; 
    }
}


void shellSort(int *a, int n)
{
    int j, temp;
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        
        for (int i = gap; i < n; i += 1)
        {
            temp = a[i];          
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
			{
                a[j] = a[j - gap];
			}
            a[j] = temp;
        }
    }
}

void heapify(int *a, int n, int i)
{
	int left = 2*i + 1, right = 2*i + 2, largest = i;
	if(left < n && a[left] > a[largest])
	{
		largest = left;
	}
	if(right < n && a[right] > a[largest])
	{
		largest = right;
	}
	if(largest != i)
	{
		swap(a[largest],a[i]);
		heapify(a,n,largest);
	}
}

void heapSort(int *a, int n)
{
	for(int i = n/2 - 1; i >= 0; i--)
	{
		heapify(a,n,i);
	}
	
	for(int i = n - 1; i >= 0; i--)
	{
		swap(a[i],a[0]);
		heapify(a,i,0);
	}
}

void merge(int *a, int left, int mid, int right)
{
    int i,j,k;
    int n1 = mid + 1 - left, n2 = right - mid;
    int L[n1], R[n2];

    for(int m = 0; m < n1; m++) L[m] = a[left + m];
    for(int m = 0; m < n2; m++) R[m] = a[mid + 1 + m];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] >= R[j])
        {
            a[k] = R[j];
            j++;
        }
        else
        {
            a[k] = L[i];
            i++;
        }
        k++;
    }

    while(i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *a, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        
        merge(a,left, mid, right);
    }
}

int partition(int *a, int left, int right)
{
    int pivot = a[left];
    int i = left - 1;
    int j = right + 1;

    while (1)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        
        do
        {
            j--;
        } while (a[j] > pivot);
        
        if (i < j)
            swap(a[i], a[j]);
        else
            return j;    
    }
}

void quickSort(int *a, int left, int right)
{
    if (left >= right)
        return;

    if (left < right)
    {
        int mid = partition(a, left, right);
        quickSort(a, left, mid);
        quickSort(a, mid + 1, right);
    }
}

void countingSort(int *a, int n)
{
    int max = a[0];

    for(int i = 1; i < n; i++)
	{
        if(a[i] > max)
		{
            max = a[i];
        }
    }

    max = max + 1;

    int b[max] ={0}, c[max] , d[n];
    for(int i = 0; i < n; i++)
	{
        b[a[i]]++;
    }

    int sum = 0;

    for(int i = 0; i < max; i++)
	{
        sum = sum + b[i];
        c[i] = sum;
    }
  
    for(int i = 0; i < n; i++)
	{
        d[c[a[i]] - b[a[i]]] = a[i];
        b[a[i]] -- ;
    }
    for(int i = 0; i < n; i++){
        a[i] = d[i];
    }

}

int countDigitNumMax(int *a, int n)
{
    int max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    int count = 0;
    while( max > 1)
    {
        max = max / 10;
        count ++;
    }
    return count; 
}


void radixSort(int *a, int n)
{
    int j = 0;
    int c = countDigitNumMax(a,n) ;
    int f  = 1;
    for(int d = 0; d < c; d++)
    {
        int b[n][n] ={0};
        for(int i = 0; i < n; i++)
        {
            int k = (a[i] / f) % 10;
            b[k][0] ++;
            b[k][b[k][0]] = a[i];
        }
        int k = 0;
        for(int i = 0; i< n; i++)
        {
            if(b[i][0] != 0)
            {
                for(int j = 1; j <= b[i][0]; j++){
                    a[k] = b[i][j];
                    k++;
                }
            }
        }
        f *= 10;
    }

}

void flashSort(int *a, int n)
{
    int m, minVal, max;
    int *l;
    double c1;

    m = int(0.45 * n);   
  
    l = new int[m]{};

    minVal = a[0];
    max = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[max])
            max = i;
    }

    if (a[max] == minVal) { return; }
    
    c1 = (double)(m - 1) / (a[max] - minVal);

    l[0] = -1;

    for (int i = 0; i < n; i++)
    {
        int k = floor(c1 * (a[i] - minVal));
        l[k]++;
    }

    for (int i = 1; i < m; i++)
		l[i] += l[i - 1];

    swap(a[max], a[0]);

    int nmove = 0;
	int j = 0;
	int k = m - 1;
    float flash;

    while (nmove < n)
	{
		while (j > l[k])
		{
			j++;
			k = floor(c1*(a[j] - minVal));
		}

		flash = a[j];
        
		while (j <= l[k])
		{
			k = floor(c1*(flash - minVal));
			int hold = a[l[k]];
			a[l[k]] = flash;
            l[k]--;
			flash = hold;
			nmove++;
		}
	}

    insertionSort(a,n);
    
    delete[] l;
}



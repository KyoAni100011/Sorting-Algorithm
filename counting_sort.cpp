#include "counting_sort.h"

void countingSort(int a[], int n)
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

    cout << endl;
    int sum = 0;
    for(int i = 0; i < max; i++)
	{
        sum = sum + b[i];
        c[i] = sum;
    }
    cout << endl;
    for(int i = 0; i < n; i++)
	{
        d[c[a[i]] - b[a[i]]] = a[i];
        b[a[i]] -- ;
    }
    
}
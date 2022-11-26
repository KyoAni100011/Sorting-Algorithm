#include "radix_sort.h"

void radixSort(int a[], int n)
{
	int exp = 1;
    
    for (int it = 0; it < 9; it++) 
	{
        vector<int> buckets[10];
        
        for (int i = 0; i < n; i++) 
		{
            buckets[(a[i] / exp) % 10].push_back(a[i]);
        }
        
        n = 0;
        for (vector<int> bucket : buckets) 
		{
            for (int v : bucket) 
			{
                a[n++] = v;
            }
        }
        
        exp *= 10;
    }
}